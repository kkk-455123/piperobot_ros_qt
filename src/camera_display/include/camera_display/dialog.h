#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

#include <QDebug>

#include <iostream>
#include <string>
#include <unordered_map>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
public:
    explicit Dialog(QWidget *parent = nullptr);
//    Dialog(Ui::MainWindow* mainWindow): m_mainWindow(mainWindow) {};
    ~Dialog();

    std::unordered_map<std::string, std::string> GetInfo();

private slots:
    void on_buttonBox_clicked();

private:
    Ui::Dialog *ui;
//    Ui::MainWindow *m_mainWindow;
    std::unordered_map<std::string, std::string> infoMap{
        {"name", ""}, {"num", ""},
        {"place", ""}, {"unit", ""},
        {"direction", ""}, {"person", ""},
        {"startNum", ""}, {"endNum", ""},
        {"pipeSize", ""}, {"pipeType", ""},
        {"pipeMaterial", ""}, {"pipeLength", ""},
        {"date", ""}
        };

Q_SIGNALS:
    void dataModified(const std::unordered_map<std::string, std::string>& modifiedData);  // 定义信号
};

#endif // DIALOG_H
