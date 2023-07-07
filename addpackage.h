#ifndef ADDPACKAGE_H
#define ADDPACKAGE_H

#include <QDialog>
#include "databaseHeader.h"

namespace Ui {
class addPackage;
}

class addPackage : public QDialog
{
    Q_OBJECT

public:
    explicit addPackage(QWidget *parent = nullptr);
    ~addPackage();

private slots:
    void on_btnSave_clicked();

    void on_btnReset_clicked();

private:
    Ui::addPackage *ui;
};

#endif // ADDPACKAGE_H
