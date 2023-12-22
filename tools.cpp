#include "tools.h"

tools::tools() {}

HANDLE tools::loadFile(LPCWSTR lpFileName) {
    HANDLE hFile = CreateFile(lpFileName, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    LPVOID lpBuffer;
    if (hFile != INVALID_HANDLE_VALUE) {
        int fileSize = GetFileSize(hFile, NULL);
        lpBuffer = malloc(fileSize);
        memset(lpBuffer, 0, fileSize);
        if (ReadFile(hFile, lpBuffer, fileSize, NULL, NULL)) {
            CloseHandle(hFile);
            return lpBuffer;
        }
    }
    return NULL;
}
