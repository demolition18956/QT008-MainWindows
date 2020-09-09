#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    connect(ui->spinButton, SIGNAL(clicked()), this, SLOT(processSpin()));
}

Form::~Form()
{
    delete ui;
}

void Form::processSpin() {
    int left = qrand() % MODULUS;
    int mid = qrand() % MODULUS;
    int right = qrand() % MODULUS;

    ui->fSpinLabel->setNum(left);
    ui->sSpinLabel->setNum(mid);
    ui->tSpinLabel->setNum(right);

    int spins =ui->totalLabel->text().toInt()+1;
    ui->totalLabel->setNum(spins);

    if (left == mid && mid == right){
        int wins = ui->winLabel->text().toInt()+1;
        ui->winLabel->setNum(wins);
        emit updateStatus("Status: Winner!!");
    } else {
        emit updateStatus("Status: Loser!!");
}

}
