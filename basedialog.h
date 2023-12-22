#ifndef BASEDIALOG_H
#define BASEDIALOG_H

#include <QDialog>
#include "fileinfohash.h"
#include <windows.h>
#include "pedialog.h"
#include "elfdialog.h"
#include "constants.h"

class BaseDialog {
public:
    QDialog *dialog(DWORD flag, FileInfoHash fileInfo) {
        switch (flag) {
        case PE_TYPE:
            return (new PEDialog(fileInfo));
            break;
        case ELF_TYPE:
            return (new ELFDialog(fileInfo));
            break;
        case DARWIN_TYPE:
            return NULL;
            break;
        default:
            return NULL;
        }
    }
};

#endif // BASEDIALOG_H
