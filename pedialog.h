#ifndef PEDIALOG_H
#define PEDIALOG_H

#include <QDialog>
#include <QFileInfo>

#include "fileinfohash.h"

namespace Ui {
class PEDialog;
}

class PEDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PEDialog(const FileInfoHash &fileInfo, QWidget *parent = nullptr);
    ~PEDialog();

    void loadBaseData();
    void loadPEData();
    FileInfoHash fileInfo;

private:
    Ui::PEDialog *ui;
};

#endif // PEDIALOG_H
