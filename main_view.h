#ifndef MAIN_VIEW_H
#define MAIN_VIEW_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLineEdit>
#include <QTableWidget>
class main_view : public QWidget
{
    Q_OBJECT

public:
    main_view(QWidget *parent = 0);
    ~main_view();
    int getrow();
    void setup_ui();
    int get_id();
private:
    int store_id;
    QGridLayout *tampilan_core;
    QPushButton *tutup;
    QPushButton *search_t;
    QLineEdit *nis;
    QTableWidget *list_sekolah;

private slots:
    void search_t_clicked();
};

#endif // MAIN_VIEW_H
