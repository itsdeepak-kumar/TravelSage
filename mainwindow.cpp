#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ptrAddPackage = new addPackage();
    ptrRegisterTourist = new RegisterTourist();
    ptrFindPackage = new findPackage();
    ptrFindTourist = new findTourist();

}

MainWindow::~MainWindow()
{
    delete ptrAddPackage;
    delete ptrRegisterTourist;
    delete ptrFindPackage;
    delete ptrFindTourist;
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ptrAddPackage->show();
}


void MainWindow::on_pushButton_2_clicked()
{
    ptrRegisterTourist->show();
}


void MainWindow::on_pushButton_3_clicked()
{
    ptrFindPackage->show();
}


void MainWindow::on_pushButton_4_clicked()
{
    ptrFindTourist->show();
}

