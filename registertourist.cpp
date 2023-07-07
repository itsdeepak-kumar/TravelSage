#include "registertourist.h"
#include "ui_registertourist.h"

RegisterTourist::RegisterTourist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterTourist)
{
    ui->setupUi(this);
}

RegisterTourist::~RegisterTourist()
{
    delete ui;
}

void RegisterTourist::on_btnSave_clicked()
{
    QString firstName = ui->txtFirstName->text();
    QString middleName = ui->txtMiddleName->text();
    QString lastName = ui->txtLastName->text();
    QString passportNo = ui->txtPassportNo->text();
    QString contactNo = ui->txtContactNo->text();
    QString permanentAddress = ui->txtPermanentAddress->text();
    QString packageName = ui->cmbChooseDescription->currentText();

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
    query.prepare("insert into Tourist (FirstName, MiddleName, LastName, PassportNo, ContactNo, PermanentAddress, PackageName) "
                  "values('" + firstName + "','" + middleName + "','" + lastName + "', '" + passportNo + "','" + contactNo + "','" + permanentAddress + "','" + packageName +"')");
    query.exec();
    query.finish();query.clear();
    qDebug() <<"Last Error : " << query.lastError().text();
    database.close();
    on_btnReset_clicked();
}

void RegisterTourist::on_loadPackage_clicked()
{
    QSqlDatabase database = QSqlDatabase::database("/home/deepak/Desktop/TouristManager.db");
    QSqlQuery query(database);

     query.prepare("select PackageName from Package");
     query.exec();
     while(query.next())
      {
             ui->cmbChooseDescription->addItem(query.value(0).toString());
             qDebug() << "Filling Combobox " << query.value(0).toString();
      }

     qDebug() << "Last error : "<< query.lastQuery();
     qDebug() << "Last error : "<< query.lastError().text();
}

void RegisterTourist::on_cmbChooseDescription_currentIndexChanged(int index)
{
    QString packageName = ui->cmbChooseDescription->currentText();
    QSqlDatabase database = QSqlDatabase::database("/home/deepak/Desktop/TouristManager.db");
    QSqlQuery query(database);

     query.prepare("select PackageDescription from Package where PackageName ='" + packageName + "'");
     query.exec(); query.next();
     ui->txtPackageDescription->setText(query.value(0).toString());
     query.finish();query.clear();
     qDebug() << "Last error : "<< query.lastQuery();
     qDebug() << "Last error : "<< query.lastError().text();
}

void RegisterTourist::on_btnReset_clicked()
{
    ui->txtFirstName->clear();
    ui->txtLastName->clear();
    ui->txtMiddleName->clear();
    ui->txtContactNo->clear();
    ui->txtPassportNo->clear();
    ui->txtPermanentAddress->clear();
    ui->txtPackageDescription->clear();
}




