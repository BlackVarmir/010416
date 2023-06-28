#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

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

void MainWindow::on_loginButton_clicked() {
    QString login = ui->loginLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    if (login == "admin" && password == "password") {
        QMessageBox::information(this, "Success", "Login successful!");
    }
    else if (login == "admin") {
        QMessageBox::warning(this, "Warning", "Invalid password!");
    }
    else {
        QMessageBox::warning(this, "Warning", "Invalid login!");
    }

    ui->loginLineEdit->clear();
    ui->passwordLineEdit->clear();
    ui->loginLineEdit->setFocus();
    ui->progressBar->setValue(100);
}

