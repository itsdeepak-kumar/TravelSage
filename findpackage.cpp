#include "findpackage.h"
#include "ui_findpackage.h"

findPackage::findPackage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::findPackage)
{
    ui->setupUi(this);
    model = NULL;
}

findPackage::~findPackage()
{
    qDebug() << "~ Findpackage()";
    delete ui;
    delete model;
}

void findPackage::on_btnFindPackage_clicked()
{
    QString packageName = ui->txtPackageName->text();
    qDebug() << "Package Name : "<< packageName;
//    QSqlDatabase database = QSqlDatabase::database("/home/deepak/Desktop/TouristManager.db");

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

    if(model == NULL)
        model = new QSqlQueryModel();

    model->setQuery("select * from Package where PackageName like '%" + packageName + "%'", database);
    ui->tableView->setModel(model);


}

