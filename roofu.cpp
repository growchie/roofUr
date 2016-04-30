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
    Rs1 = ui->leRs1->text().toDouble();
    dataFilled |= 1 << 0;
    calculateUr();
}

void roofU::getRs2(void)
{
    Rs2 = ui->leRs2->text().toDouble();
    dataFilled |= 1 << 1;
    calculateUr();
}


void roofU::getV(void)
{
    V = ui->leV->text().toDouble();
    dataFilled |= 1 << 2;
    calculateUr();
}

void roofU::getTi(void)
{
    Ti = ui->leTi->text().toDouble();
    dataFilled |= 1 << 3;
    calculateUr();
}

void roofU::getTe(void)
{
    Te = ui->leTe->text().toDouble();
    dataFilled |= 1 << 4;
    calculateUr();
}

void roofU::getA1(void)
{
    A1 = ui->leA1->text().toDouble();
    dataFilled |= 1 << 5;
    calculateUr();
}

void roofU::getA2(void)
{
    A2 = ui->leA2->text().toDouble();
    dataFilled |= 1 << 6;
    calculateUr();
}

void roofU::getN(void)
{
    n = ui->leN->text().toDouble();
    calculateUr();
}

void roofU::getUw(void)
{
    Uw = ui->leUw->text().toDouble();
    calculateUr();
}

void roofU::getAw(void)
{
    Aw = ui->leAw->text().toDouble();
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
