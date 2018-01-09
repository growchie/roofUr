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

#include "roofu.h"
#include "ui_roofu.h"
#include "formulas.h"

roofU::roofU(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::roofU),
    Uw(0),
    Aw(0),
    n(0.1),
    dataFilled('0')
{
    ui->setupUi(this);

    connect(ui->leA1,SIGNAL(editingFinished()),this,SLOT(getA1()));
    connect(ui->leA2,SIGNAL(editingFinished()),this,SLOT(getA2()));
    connect(ui->leAw,SIGNAL(editingFinished()),this,SLOT(getAw()));
    connect(ui->leN,SIGNAL(editingFinished()),this,SLOT(getN()));
    connect(ui->leRs1,SIGNAL(editingFinished()),this,SLOT(getRs1()));
    connect(ui->leRs2,SIGNAL(editingFinished()),this,SLOT(getRs2()));
    connect(ui->leTe,SIGNAL(editingFinished()),this,SLOT(getTe()));
    connect(ui->leTi,SIGNAL(editingFinished()),this,SLOT(getTi()));
    connect(ui->leUw,SIGNAL(editingFinished()),this,SLOT(getUw()));
    connect(ui->leV,SIGNAL(editingFinished()),this,SLOT(getV()));

    QDoubleValidator *tempValidator = new QDoubleValidator(-20, 30, 1);
    tempValidator->setLocale(QLocale::C);
    QDoubleValidator *volAreaValidator = new QDoubleValidator(0, 99999, 2);
    volAreaValidator->setLocale(QLocale::C);
    QDoubleValidator *resValidator = new QDoubleValidator(0.001, 99, 3);
    resValidator->setLocale(QLocale::C);

    ui->leV->setValidator(volAreaValidator);
    ui->leN->setValidator(resValidator);
    ui->leTe->setValidator(tempValidator);
    ui->leTi->setValidator(tempValidator);
    ui->leRs1->setValidator(resValidator);
    ui->leRs2->setValidator(resValidator);
    ui->leUw->setValidator(resValidator);
    ui->leA1->setValidator(volAreaValidator);
    ui->leA2->setValidator(volAreaValidator);
    ui->leAw->setValidator(volAreaValidator);
}

roofU::~roofU()
{
    delete ui;
}

void roofU::getRs1(void)
{
    Rs1 = toDouble(ui->leRs1->text());
    dataFilled |= 1 << 0;
    calculateUr();
}

void roofU::getRs2(void)
{
    Rs2 = toDouble(ui->leRs2->text());
    dataFilled |= 1 << 1;
    calculateUr();
}


void roofU::getV(void)
{
    V = toDouble(ui->leV->text());
    dataFilled |= 1 << 2;
    calculateUr();
}

void roofU::getTi(void)
{
    Ti = toDouble(ui->leTi->text());
    dataFilled |= 1 << 3;
    calculateUr();
}

void roofU::getTe(void)
{
    Te = toDouble(ui->leTe->text());
    dataFilled |= 1 << 4;
    calculateUr();
}

void roofU::getA1(void)
{
    A1 = toDouble(ui->leA1->text());
    dataFilled |= 1 << 5;
    calculateUr();
}

void roofU::getA2(void)
{
    A2 = toDouble(ui->leA2->text());
    dataFilled |= 1 << 6;
    calculateUr();
}

void roofU::getN(void)
{
    n = toDouble(ui->leN->text());
    calculateUr();
}

void roofU::getUw(void)
{
    Uw = toDouble(ui->leUw->text());
    calculateUr();
}

void roofU::getAw(void)
{
    Aw = toDouble(ui->leAw->text());
    calculateUr();
}

void roofU::calculateUr(void)
{
    if (dataFilled == 0x7F)
    {
        Variables exVars;
        exVars.A1 = A1;
        exVars.A2 = A2;
        exVars.Aw = Aw;
        exVars.n = n;
        exVars.Gr = &Gr;
        exVars.Pr = &Pr;
        exVars.Rs1 = Rs1;
        exVars.Rs2 = Rs2;
        exVars.Rse = &Rse;
        exVars.Te = Te;
        exVars.Ti = Ti;
        exVars.Tu = &Tu;
        exVars.Uw = Uw;
        exVars.V = V;

        Ur = getUr(exVars);

        ui->leUr->setText(QVariant(Ur).toString());
        ui->leTu->setText(QVariant(Tu).toString());
        ui->leU1->setText(QVariant((1/(Rse+Rs1+0.1))).toString());
        ui->leU2->setText(QVariant((1/(Rse+Rs2+0.04))).toString());
        ui->leGr->setText(QVariant(Gr).toString());
        ui->lePr->setText(QVariant(Pr).toString());
    }
}

double roofU::toDouble(QString stringDouble)
{
    QLocale c(QLocale::C);
    QLocale current(QLocale::system());
    bool success = false;
    double data = 0;
    data = current.toDouble(stringDouble, &success);
    if (success)
    {
        return data;
    }
    else
    {
        data = c.toDouble(stringDouble, &success);
        if(success)
            return data;
        else
            return 0;
    }
}
