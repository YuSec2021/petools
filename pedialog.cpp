#include "pedialog.h"
#include "ui_pedialog.h"

PEDialog::PEDialog(const FileInfoHash &fileInfo, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PEDialog)
{
    ui->setupUi(this);
    this->fileInfo = fileInfo;
    this->loadBaseData();
    this->loadPEData();
}

PEDialog::~PEDialog()
{
    delete ui;
}


void PEDialog::loadBaseData() {
    ui->path_browser->setText(this->fileInfo.filePath());
    ui->last_modified->setText(this->fileInfo.lastModified().toString());
    ui->author_browser->setText(this->fileInfo.owner());
    ui->md5_browser->setText(QString(this->fileInfo.MD5()));
    ui->sha1_browser->setText(QString(this->fileInfo.SHA1()));
}

void PEDialog::loadPEData() {

}
