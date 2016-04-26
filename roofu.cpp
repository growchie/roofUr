#include "roofu.h"
#include "ui_roofu.h"
#include "formulas.h"

roofU::roofU(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::roofU)
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
    connect(ui->lblUw,SIGNAL(editingFinished()),this,SLOT(getUw()));
    connect(ui->leV,SIGNAL(editingFinished()),this,SLOT(getV()));
}

roofU::~roofU()
{
    delete ui;
}

void roofU::getRs1(void)
{
    Rs1 = ui->leRs1->text().toDouble();
}

void roofU::getRs2(void)
{
    Rs2 = ui->leRs2->text().toDouble();
}


void roofU::getV(void)
{
    V = ui->leV->text().toDouble();
}

void roofU::getTi(void)
{
    Ti = ui->leTi->text().toDouble();
}

void roofU::getTe(void)
{
    Te = ui->leTe->text().toDouble();
}

void roofU::getA1(void)
{
    A1 = ui->leA1->text().toDouble();
}

void roofU::getA2(void)
{
    A2 = ui->leA2->text().toDouble();
}

void roofU::getN(void)
{
    n = ui->leN->text().toDouble();
}

void roofU::getUw(void)
{
    Uw = ui->leUw->text().toDouble();
}

void roofU::getAw(void)
{
    Aw = ui->leAw->text().toDouble();
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
}

