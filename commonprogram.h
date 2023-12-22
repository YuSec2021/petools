#ifndef COMMONPROGRAM_H
#define COMMONPROGRAM_H

#include <QMessageBox>
#include <QVector>

#include "constants.h"
#include "windows.h"
#include "elf.h"

#endif // COMMONPROGRAM_H

class CommonProgram
{
public:
    CommonProgram();
    virtual void init(LPVOID lpBuffer) = 0;

    DWORD flag;
};



// PE
class PE: public CommonProgram{
public:
    PE();
    virtual void init(LPVOID lpBuffer) = 0;
    virtual PE* getInstance() = 0;
    virtual DWORD RVAtoRAW(DWORD virtualAddress) = 0;
    virtual DWORD RAWtoRVA(DWORD physicsAddress) = 0;

public:
    PIMAGE_DOS_HEADER pImage;
    PIMAGE_FILE_HEADER pFile;
    QVector<PIMAGE_SECTION_HEADER> sections;
    PIMAGE_DATA_DIRECTORY pDataDirectory;
    PIMAGE_EXPORT_DIRECTORY pExportDirectory;
    PIMAGE_IMPORT_DESCRIPTOR pImportDirectory;
    PIMAGE_BASE_RELOCATION pReloc;
};

class PE32: public PE {
public:
    PE32();
    virtual void init(LPVOID lpBuffer);
    virtual PE* getInstance();
    virtual DWORD RVAtoRAW(DWORD virtualAddress);
    virtual DWORD RAWtoRVA(DWORD physicsAddress);

public:
    PIMAGE_OPTIONAL_HEADER32 pOptional;
    PIMAGE_NT_HEADERS32 pNt;
    PIMAGE_THUNK_DATA32 pThunkData;
};

class PE64: public PE {
public:
    PE64();
    virtual void init(LPVOID lpBuffer);
    virtual PE* getInstance();
    virtual DWORD RVAtoRAW(DWORD virtualAddress);
    virtual DWORD RAWtoRVA(DWORD physicsAddress);

public:
    PIMAGE_OPTIONAL_HEADER64 pOptional;
    PIMAGE_NT_HEADERS64 pNt;
    PIMAGE_THUNK_DATA64 pThunkData;
};


// ELF
class ELF: public CommonProgram{
public:
    ELF();
    virtual void init(LPVOID lpBuffer) = 0;
    virtual ELF* getInstance() = 0;
};

class ELF32: public ELF{
public:
    ELF32();
    virtual void init(LPVOID lpBuffer);
    virtual ELF* getInstance();

public:
    PElf32_Ehdr pHeader;
};

class ELF64: public ELF{
public:
    ELF64();
    virtual void init(LPVOID lpBuffer);
    virtual ELF* getInstance();

public:
    PElf64_Ehdr pHeader;
};


class DARWIN: public CommonProgram{
public:
    DARWIN();
    virtual void init(LPVOID lpBuffer);
};

class Factory {
public:
    CommonProgram *program(LPVOID lpBuffer) {
        switch ((PROGRAM_TYPE)*(PDWORD)lpBuffer) {
        case LINUX_HEADER:
            {
                PElf32_Ehdr p = (PElf32_Ehdr)lpBuffer;
                switch(p->e_ident[EI_CLASS]) {
                case ELFCLASS32:
                    return (new ELF32());
                    break;
                case ELFCLASS64:
                    return (new ELF64());
                    break;
                }
            }
            return NULL;
            break;
        case WINDOWS_HEADER:
            {
                PIMAGE_DOS_HEADER pImage = (PIMAGE_DOS_HEADER)lpBuffer;
                PIMAGE_FILE_HEADER pFile = (PIMAGE_FILE_HEADER) & (((PBYTE)lpBuffer)[pImage->e_lfanew + sizeof(DWORD)]);
                switch(pFile->Machine) {
                case IMAGE_FILE_MACHINE_I386:
                    return (new PE32());
                    break;
                case IMAGE_FILE_MACHINE_AMD64:
                    return (new PE64());
                    break;
                }
            }
            return NULL;
            break;
        case DARWIN_HEADER:
            MessageBox(NULL, TEXT("mac"), 0, 0);
            {
                return (new DARWIN());
            }
            return NULL;
            break;
        default:
            return NULL;
        }
    }
};



