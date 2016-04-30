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

    double Rs1;
    double Rs2;
    double V, Ti, Te, A1, A2, Uw, Aw, Ur, n;
    double Pr, Gr, Tu, Rse;
    unsigned char dataFilled;

    void calculateUr(void);

public slots:
    void getRs1(void);
    void getRs2(void);
    void getV(void);
    void getTi(void);
    void getTe(void);
    void getA1(void);
    void getA2(void);
    void getUw(void);
    void getAw(void);
    void getN(void);

};

#endif // ROOFU_H
