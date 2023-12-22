#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_analysisBtn_clicked()
{
    QString filePath = ui->plainTextEdit->toPlainText();
    FileInfoHash fileInfo(filePath);
    std::wstring wlpstr = filePath.toStdWString();
    LPCWSTR fileName = wlpstr.c_str();
    LPVOID lpBuffer = tools::loadFile(fileName);
    if (!lpBuffer) {
        QMessageBox::critical(this, "Error", "Cannot load File");
        ui->plainTextEdit->clear();
        return;
    }
    Factory *fac = new Factory();
    CommonProgram *p = fac->program(lpBuffer);
    p->init(lpBuffer);

    delete(fac);

    BaseDialog *baseDialog = new BaseDialog();
    this->dialog = baseDialog->dialog(p->flag, fileInfo);
    this->dialog->setWindowTitle(filePath);
    this->dialog->show();

    delete(baseDialog);
    this->dialog = NULL;
}


void MainWindow::on_openFileBtn_clicked()
{
    ui->plainTextEdit->clear();
    QString filepath = QFileDialog::getOpenFileName(
        this,
        tr("open a file."),
        ".",
        tr(FILE_FORMAT)
    );
    if (filepath.isEmpty()) {
        QMessageBox::warning(this, "Warning!", "Failed to open the file!");
        ui->plainTextEdit->clear();
    } else {
        ui->plainTextEdit->setPlainText(filepath);
    }
}

