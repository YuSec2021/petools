#ifndef ELFDIALOG_H
#define ELFDIALOG_H

#include <QDialog>
#include <QFileInfo>

#include "fileinfohash.h"

namespace Ui {
class ELFDialog;
}

class ELFDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ELFDialog(FileInfoHash fileInfo, QWidget *parent = nullptr);
    ~ELFDialog();

    void importData();

private:
    Ui::ELFDialog *ui;
};

#endif // ELFDIALOG_H
