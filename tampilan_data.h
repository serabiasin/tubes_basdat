#ifndef TAMPILAN_DATA_H
#define TAMPILAN_DATA_H

#include<biodata.h>
#include <track_record.h>

#include <QWidget>
#include <QTabWidget>

class tampilan_data : public QWidget
{
    Q_OBJECT
public:
    explicit tampilan_data(QWidget *parent = 0);
    void set_nis(int x);
    int get_nis();

private:
    QTabWidget *tab_view;
    int nis_sekolah;

};

#endif // TAMPILAN_DATA_H
