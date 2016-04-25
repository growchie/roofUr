#ifndef FORMULAS_H
#define FORMULAS_H

struct Variables {
    double A1;
    double Rs1;
    double A2;
    double Rs2;
    double Aw;
    double Uw;
    double n;
    double V;
    double Ti;
    double Te;
    double *Tu;
    double *Gr;
    double *Pr;
    double *Rse;
};

double getUr(Variables var);

#endif // FORMULAS_H
