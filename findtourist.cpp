#include "findtourist.h"
#include "ui_findtourist.h"

findTourist::findTourist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::findTourist)
{
    ui->setupUi(this);
    model = NULL;
}

findTourist::~findTourist()
{
    delete ui;
    delete model;
}

void findTourist::on_btnFindTourist_clicked()
{
    QString packageName = ui->txtTouristName->text();
    qDebug() << "Package Name : "<< packageName;
//    QSqlDatabase database = QSqlDatabase::database("DB1");

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

    model->setQuery("select * from Tourist where FirstName like '%" + packageName + "%'", database);
    ui->tableView->setModel(model);
    qDebug() << " after btnFind_clicked";
}

