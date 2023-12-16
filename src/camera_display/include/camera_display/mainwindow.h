#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QProcess>
#include <QComboBox>
#include <QSpinBox>
#include <QMessageBox>  // 提示信息
#include <QTimer>

// sql相关
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlError>
#include <QSortFilterProxyModel> 

// C++库
#include <iostream>
#include <memory>
#include <string>

// 系统/文件操作相关
#include <QDir>
#include <QUrl>
#include <QDesktopServices>
#include <QFile>
#include <QFileInfo>
#include <QFileInfoList>
#include <QProgressDialog>
#include <QStorageInfo>

#include <QThread>
#include <QFileDialog>

// #include <QApplication>

// #include "qnode.h"
#include "dialog.h"

namespace camera_display {class QNode;}

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(int argc, char** argv, QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void fileName(std::string);
    void updateProgressValue(int);
    void finUpdate(bool);

public slots:
    /******************************************
    ** Auto-connections (connectSlotsByName())
    *******************************************/

    /******************************************
    ** Manual connections
    *******************************************/
//    void slot_update_power(float);
    void slot_update_image(QImage);
    void slot_update_temp_humid(float temp,float humi);
    // void slot_sub_image(std::string);  // 订阅图像话题
    void slot_sub_image_front();  // 订阅图像话题
    void slot_sub_image_behind();
    void copyMessage(bool);

private slots:
    /******************************************
    ** Auto-connections (connectSlotsByName())
    *******************************************/
	void on_pushButton_connect_clicked();
    void on_pushButton_quit_clicked();
    void on_pushButton_back_clicked();
    void on_pushButton_video_clicked();
    void on_pushButton_datainput_clicked();
    void on_pushButton_datasearch_clicked();
    void on_pushButton_localvideo_clicked();
    void on_pushButton_utrans_clicked();
    void on_pushButton_upload_clicked();
    void on_pushButton_finish_clicked();
    void on_pushButton_start_clicked();
    void on_pushButton_sonar_clicked();

    /******************************************
    ** Manual connections
    *******************************************/
    void trigerMenu(QAction* act);
    void handleDataModified(const std::unordered_map<std::string, std::string>& modifiedData);
    void onHeaderClicked(int logicalIndex);  // 表头点击事件
    void labelConnectUpdate();  // 指示灯状态更新

private:
    Ui::MainWindow *ui;
    // camera_display::QNode qnode;
    std::unique_ptr<camera_display::QNode> qnode;
    std::unique_ptr<Dialog> configWindow;  // unique指针存放信息登记窗口资源
    QTimer *timer = new QTimer(this);
    // std::unique_ptr<QProgressDialog> progressDialog;  // 使用指针成员变量，用于验证局部对象进度条对话框是不是因为执行速度过快，跳出作用域导致其生命周期结束，所以没有及时显示
    QProgressDialog* progressDialog;
    
    QSqlDatabase db;  // mysql数据库
    std::unique_ptr<QSqlQueryModel> model;
    std::unique_ptr<QSortFilterProxyModel> proxyModel;  // 代理模型

    bool isRunFlag;  // 记录ROS系统连接状态
    bool isInput;  // 是否已经录入信息
    QString videoFolder;
    QString videoName;

    // 记录系统运行状态 isRun && isInput -> isDisplay -> isSave
    struct sysState {
        bool isRun;
        bool isInput;
        bool isDisplay;
        bool isSave;
    } sysStat;

    void Init();
    void UiInit();
    void ConnInit();
    bool mysqlInit();
    void updateDatabase(const std::unordered_map<std::string, std::string>& modifiedData, const QString&& tableName);
    // 数据导出功能
    QString getUSBFolderPath();
    void copyToUSB();
    // void copyDirectory(const QDir& sourceDir, const QDir& targetDir);  
};

// 自定义的后台线程类
class CopyThread : public QThread {
    Q_OBJECT

public:
    explicit CopyThread(const QString& sourceFolderPath, const QString& usbFolderPath)
        : sourceFolderPath_(sourceFolderPath), usbFolderPath_(usbFolderPath) {}

signals:
    void progressUpdated(int value);
    void filesUpdated(int start, int value);
    void finished(bool);

protected:
    void run() override;

private:
    QString sourceFolderPath_;
    QString usbFolderPath_;

    void copyDirectory(const QDir& sourceDir, const QDir& targetDir);  
};


// 输出我的调试信息到文件中
void MyDebug(std::string);

#include "qnode.h"
#endif // MAINWINDOW_H
