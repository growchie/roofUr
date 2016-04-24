#ifndef ROOFU_H
#define ROOFU_H

#include <QWidget>

namespace Ui {
class roofU;
}

class roofU : public QWidget
{
    Q_OBJECT

public:
    explicit roofU(QWidget *parent = 0);
    ~roofU();

private:
    Ui::roofU *ui;
};

#endif // ROOFU_H
