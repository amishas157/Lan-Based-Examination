#include "result.h"
#include "ui_result.h"
#include "stdio.h"

result::result(int a, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::result)
{
    ui->setupUi(this);
    ui->label->setNum(a);

    //display performance according to the score
    if(a>=0 && a <=3)
        ui->label_5->setText("Poor Performance :(");
    else if(a >= 4 && a <=7)
        ui->label_5->setText("Average performance :|");
    else
        ui->label_5->setText("Excellent Performance. :)");
}

result::~result()
{
    delete ui;
}
