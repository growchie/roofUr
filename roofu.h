/**
 * Copyright (c) 2016, Velislav Varbanov
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted
 * provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this list of conditions
 * and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions
 * and the following disclaimer in the documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**/

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
    double toDouble(QString stringDouble);

};

#endif // ROOFU_H
