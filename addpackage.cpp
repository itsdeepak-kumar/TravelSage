#include "addpackage.h"
#include "ui_addpackage.h"

addPackage::addPackage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addPackage)
{
    ui->setupUi(this);
}

addPackage::~addPackage()
{
    delete ui;
}

void addPackage::on_btnSave_clicked()
{
    QString packageName = ui->txtPackageName->text();
    QString packageDescription = ui->txtDescription->toPlainText();
    QString amount = ui->txtAmount->text();

    qDebug() << "Package Name : " << packageName << "Package Description : " << packageDescription << "Package Amount : " << amount;

    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("/home/deepak/Desktop/TouristManager.db");

    if(QFile::exists("/home/deepak/Desktop/TouristManager.db")){
       qDebug() << "Database file exists";
    }
    else{
       qDebug() << "Database file doesn't exists";
        return;
    }

    if(!database.open()){
        qDebug() << "Error : Unable to open database!";
        return;
    }
    else{
        qDebug() << "Database open successfully....";
    }

    QSqlQuery query(database);
    query.prepare("insert into Package (PackageName, PackageDescription, Amount) values('" + packageName + "', '" + packageDescription + "', '" + amount +"')");
    query.exec();
    query.finish();query.clear();
    qDebug() <<"Last Error : " << query.lastError().text();
    database.close();
    on_btnReset_clicked();

}


void addPackage::on_btnReset_clicked()
{
    ui->txtPackageName->clear();
    ui->txtDescription->clear();
    ui->txtAmount->clear();
}

