#ifndef MAIN_VIEW_H
#define MAIN_VIEW_H

#include <QWidget>

class main_view : public QWidget
{
    Q_OBJECT

public:
    main_view(QWidget *parent = 0);
    ~main_view();
    void setup_ui();
};

#endif // MAIN_VIEW_H
