#include "roofu.h"
#include "ui_roofu.h"
#include "formulas.h"

roofU::roofU(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::roofU)
{
    ui->setupUi(this);
    //getU();
}

roofU::~roofU()
{
    delete ui;
}
