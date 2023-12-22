#ifndef CONSTANTS_H
#define CONSTANTS_H


// File Header
enum PROGRAM_TYPE {
    LINUX_HEADER = 0x464C457F,
    WINDOWS_HEADER = 0x00905A4D,
    DARWIN_HEADER = 0x00000000
};
// Common
#define WINDOWS_TITLE "PETools by YuSec 2023"
#define FILE_FORMAT "pe(*.exe *.dll);;elf(*.*);;darwin(*.*);;All files(*.*)"

#define PE_TYPE 1
#define ELF_TYPE 2
#define DARWIN_TYPE 3


#endif // CONSTANTS_H

