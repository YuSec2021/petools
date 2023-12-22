#include "commonprogram.h"

// Create method
CommonProgram::CommonProgram(){}
PE::PE(){}
ELF::ELF(){}
PE32::PE32(){}
PE64::PE64(){}
ELF32::ELF32(){}
ELF64::ELF64(){}
DARWIN::DARWIN(){}

// initail ELF32
void ELF32::init(LPVOID lpBuffer) {
    this->flag = 2;
    MessageBox(NULL, TEXT("ELF 32"), TEXT("Linux"), 0);
}

// initial ELF64
void ELF64::init(LPVOID lpBuffer) {
    this->flag = 2;
    MessageBox(NULL, TEXT("ELF 64"), TEXT("Linux"), 0);
}

// initial PE32
void PE32::init(LPVOID lpBuffer) {
    this->flag = 1;
    MessageBox(NULL, TEXT("PE 32"), TEXT("Windows"), 0);

    this->pImage = (PIMAGE_DOS_HEADER)lpBuffer;
    this->pNt = (PIMAGE_NT_HEADERS32)((PBYTE)lpBuffer + this->pImage->e_lfanew);
    this->pFile = &this->pNt->FileHeader;
    this->pOptional = &this->pNt->OptionalHeader;
    PIMAGE_SECTION_HEADER pTmpSection = (PIMAGE_SECTION_HEADER)(this->pOptional + 1);
    for (int i = 0; i < this->pFile->NumberOfSections; i++) {
        this->sections.append(pTmpSection + i);
    }

    this->pDataDirectory = this->pOptional->DataDirectory;
}

// initial PE64
void PE64::init(LPVOID lpBuffer) {
    this->flag = 1;
    MessageBox(NULL, TEXT("PE 64"), TEXT("Windows"), 0);

    this->pImage = (PIMAGE_DOS_HEADER)lpBuffer;
    this->pNt = (PIMAGE_NT_HEADERS64)((PBYTE)lpBuffer + this->pImage->e_lfanew);
    this->pFile = &this->pNt->FileHeader;
    this->pOptional = &this->pNt->OptionalHeader;
    PIMAGE_SECTION_HEADER pTmpSection = (PIMAGE_SECTION_HEADER)(this->pOptional + 1);
    for (int i = 0; i < this->pFile->NumberOfSections; i++) {
        this->sections.append(pTmpSection + i);
    }

    this->pDataDirectory = this->pOptional->DataDirectory;

}

PE* PE64::getInstance() {
    return this;
}


DWORD PE64::RAWtoRVA(DWORD physicsAddress) {
    return -1;
}

DWORD PE32::RAWtoRVA(DWORD physicsAddress) {
    return -1;
}

DWORD PE64::RVAtoRAW(DWORD VirtualAddress) {
    return -1;
}

DWORD PE32::RVAtoRAW(DWORD VirtualAddress) {
    return -1;
}


PE* PE32::getInstance() {
    return this;
}

void DARWIN::init(LPVOID lpBuffer) {
    MessageBox(NULL, TEXT("Darwin"), TEXT("macOS"), 0);
}


