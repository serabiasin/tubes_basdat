#ifndef DATA_ALUMNI_H
#define DATA_ALUMNI_H

#include "tampilan_data.h"

#include <QDialog>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QMessageBox>
#include <QDebug>
#include <QTableWidgetItem>
#include <QGridLayout>
#include <QLineEdit>
#include <QTableWidget>

class data_alumni : public QDialog
{
public:
    data_alumni();
    void set_alumni(int pk);
    int getrow(int pk);
private:
QTableWidget *list_alumni;


};

#endif // DATA_ALUMNI_H
