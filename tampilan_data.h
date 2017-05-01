#ifndef TAMPILAN_DATA_H
#define TAMPILAN_DATA_H
#include <QWidget>
#include <QTableWidget>

class tampilan_data : public QWidget
{
    Q_OBJECT
public:
    explicit tampilan_data(QWidget *parent = 0);
    void setup_ui_2();

};

#endif // TAMPILAN_DATA_H
