#ifndef FINDTOURIST_H
#define FINDTOURIST_H

#include <QDialog>
#include "databaseHeader.h"

namespace Ui {
class findTourist;
}

class findTourist : public QDialog
{
    Q_OBJECT

public:
    explicit findTourist(QWidget *parent = nullptr);
    ~findTourist();

private slots:
    void on_btnFindTourist_clicked();

private:
    Ui::findTourist *ui;
    QSqlQueryModel *model;
};

#endif // FINDTOURIST_H
