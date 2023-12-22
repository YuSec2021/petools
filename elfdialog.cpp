#include "elfdialog.h"
#include "ui_elfdialog.h"

ELFDialog::ELFDialog(FileInfoHash fileInfo, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ELFDialog)
{
    ui->setupUi(this);
}

ELFDialog::~ELFDialog()
{
    delete ui;
}


void  ELFDialog::importData() {
}
