// #include "dialog.h"
#include "../include/camera_display/dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_clicked()
{
    this->infoMap["name"] = ui->nameEdit->toPlainText().toStdString();
    this->infoMap["num"] = ui->numEdit->toPlainText().toStdString();
    this->infoMap["place"] = ui->placeEdit->toPlainText().toStdString();  // place和name是不是一样的？
    this->infoMap["unit"] = ui->unitEdit->toPlainText().toStdString();
    this->infoMap["person"] = ui->personEdit->toPlainText().toStdString();
    this->infoMap["startNum"] = ui->startNumEdit->toPlainText().toStdString();
    this->infoMap["endNum"] = ui->endNumEdit->toPlainText().toStdString();
    this->infoMap["pipeSize"] = ui->pipeDEdit->toPlainText().toStdString();
    this->infoMap["pipeLength"] = ui->pipeLengthEdit->toPlainText().toStdString();

    this->infoMap["pipeType"] = ui->pipeTypeComboBox->currentText().toStdString();
    this->infoMap["pipeMaterial"] = ui->pipeMaterialComboBox->currentText().toStdString();
    this->infoMap["direction"] = ui->direcComboBox->currentText().toStdString();

    this->infoMap["date"] = ui->dateEdit->date().toString(Qt::ISODate).toStdString();
    
    emit dataModified(infoMap);
    // qDebug() << "succsess";
}

