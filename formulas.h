#ifndef FORMULAS_H
#define FORMULAS_H

namespace {

struct Air {
    int Temperature;
    double Lambda;
    double Ni;
    double Pr;
} airData[51];

}

double getU( double Rs, double Rsi, double Rse);


#endif // FORMULAS_H
