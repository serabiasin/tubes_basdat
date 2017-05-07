#ifndef TRACK_RECORD_H
#define TRACK_RECORD_H

#include "tampilan_data.h"
#include "main_view.h"

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QDebug>
#include <QSqlQuery>

class track_record :public QDialog
{
public:
    track_record();
    void set_record();
    void set_ipa(int pk);
    void set_ips(int pk);
    void set_rata(int pk);
 private:

    QLabel *nilai_rata;
    QLineEdit *nilai_edit;
    QLabel *ipa;
    QLabel *ips;
    QLineEdit *nilai_ipa;
    QLineEdit *nilai_ips;


};

#endif // TRACK_RECORD_H
