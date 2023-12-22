#ifndef TOOLS_H
#define TOOLS_H

#include <windows.h>
#include <QDialog>
#include <QFileInfo>

#include "constants.h"
#include "elfdialog.h"
#include "pedialog.h"
#include "fileinfohash.h"

class tools
{
public:
    tools();

    static HANDLE loadFile(LPCWSTR lpFileName);
};





#endif // TOOLS_H
