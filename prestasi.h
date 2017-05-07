#ifndef PRESTASI_H
#define PRESTASI_H

#include "tampilan_data.h"

#include <QDialog>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QSqlQuery>
#include <QSqlDatabase>

class prestasi : public QDialog
{
public:

    prestasi();
    void set_prestasi(int pk);
    int getrow();

private:
    QTableWidget*tabel_prestasi;


};

#endif // PRESTASI_H
