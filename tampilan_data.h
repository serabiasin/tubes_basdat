#ifndef TAMPILAN_DATA_H
#define TAMPILAN_DATA_H

#include "main_view.h"
#include "track_record.h"
#include "biodata.h"
#include "prestasi.h"
#include "data_alumni.h"

#include <QWidget>
#include <QTabWidget>
#include <QDialog>
#include <QLabel>
#include <QTextEdit>
#include <QGridLayout>
#include <QLineEdit>
#include <QSqlDatabase>
class tampilan_data : public QWidget
{
    Q_OBJECT
public:
    explicit tampilan_data(QWidget *parent = 0);
  static void set_value(int c);
  static int prime_knight; //membuat class lain dapat mengakses data pk



private:
     QTabWidget *tab_view;

};





#endif // TAMPILAN_DATA_H
