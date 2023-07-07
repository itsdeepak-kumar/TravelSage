#ifndef FINDPACKAGE_H
#define FINDPACKAGE_H

#include <QDialog>
#include "databaseHeader.h"

namespace Ui {
class findPackage;
}

class findPackage : public QDialog
{
    Q_OBJECT

public:
    explicit findPackage(QWidget *parent = nullptr);
    ~findPackage();

private slots:
    void on_btnFindPackage_clicked();

private:
    Ui::findPackage *ui;
    QSqlQueryModel *model;
};

#endif // FINDPACKAGE_H
