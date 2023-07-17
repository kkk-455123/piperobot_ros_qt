// #include "mainwindow.h"
#include "../include/camera_display/mainwindow.h"
#include "ui_mainwindow.h"

#include <fstream>

void MyDebug(std::string str) {
    // std::ofstream logFile("log.txt", std::ios::app);
    std::ofstream logFile("/home/piperobot/piperobot/log.txt", std::ios::app);
    if(logFile.is_open()) {
      auto nowTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
      logFile << str << "\t" << ctime(&nowTime);
      logFile.close();
    }
}

std::string sqlCheck(QSqlQuery& query) {
    // 最后执行的sql语句（替换占位符）
    QMap<QString, QVariant> boundValues = query.boundValues();
    QString sql = query.lastQuery();

    for (auto it = boundValues.begin(); it != boundValues.end(); ++it) {
        QString placeholder = it.key();
        QVariant value = it.value();

        QString strValue;
        if (value.isNull())
            strValue = "NULL";
        else
            strValue = value.toString();

        sql.replace(placeholder, strValue);
    }

    return sql.toStdString();
}

MainWindow::MainWindow(int argc, char** argv, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    // , qnode(argc, argv, this)
    , qnode(new camera_display::QNode(argc, argv, this))
    , configWindow(new Dialog(this))
    // , isRunFlag(false), isInput(false)
    , sysStat({NULL})
    , db(QSqlDatabase::addDatabase("QMYSQL"))
    , model(new QSqlQueryModel)
    , proxyModel(new QSortFilterProxyModel(this))
    // , progressDialog(new QProgressDialog("导出文件", "取消", 0, 100, this))
    , videoFolder("/home/piperobot/视频")
{
    MyDebug("系统启动");
    ui->setupUi(this);
    Init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Init() {
    UiInit();  // ui初始化
    mysqlInit();  // 初始化数据库连接
    ConnInit();  // 信号槽连接
}

void MainWindow::UiInit() {
    // 设置按钮点击属性
    ui->pushButton_start->setEnabled(true);
    ui->pushButton_finish->setEnabled(false);

    // 设置标签显示图片
    // 获取到图片目录
    QDir dir(qApp->applicationDirPath());
    // MyDebug("Current Path: " + dir.absolutePath().toStdString());
    dir.cd("../../../src/camera_display/resources/images");
    // MyDebug("Current Path: " + dir.absolutePath().toStdString());
    // 构建pixmap
    QPixmap pixmap(dir.absoluteFilePath("robot3.png"));
    // 设置pixmap比例
    int labelH = ui->label_image->height() + 500;
    int labelW = int(pixmap.width() * labelH / pixmap.height());
    QSize size(labelW, labelH);  // 高为label的高，宽通过比例计算，要保持图片原比例
    pixmap = pixmap.scaled(size);
    // 将pixmap设置到label
    ui->label_image->setPixmap(pixmap);

    // // 创建 QStackedWidget
    // QStackedWidget *stackedWidget = new QStackedWidget(this);

    // // 创建 QLabel 对象和 QPixmap 对象
    // QPixmap backgroundPixmap("/home/kkk/test1.jpg");
    // // 调整背景标签的尺寸为窗口尺寸
    // ui->label_image->setGeometry(0, 0, this->width(), this->height());
    // // 缩放图片以适应标签的尺寸
    // QPixmap scaledPixmap = backgroundPixmap.scaled(ui->label_image->size(), Qt::KeepAspectRatio);
    // // 将缩放后的图片设置为标签的背景
    // ui->label_image->setPixmap(scaledPixmap);
    // ui->label_image->setScaledContents(true);
    // ui->label_image->setAlignment(Qt::AlignCenter);
    // // ui->label_image->lower();  // 确保标签在窗口的底部

    // // 创建 QWidget 对象来包含其他控件
    // QWidget *contentWidget = new QWidget(this);

    // // 添加背景图片和其他控件到 QStackedWidget
    // stackedWidget->addWidget(backgroundLabel); // 索引为0，底层
    // stackedWidget->addWidget(contentWidget);   // 索引为1，顶层

    // // 设置 QStackedWidget 为窗口的中心部件
    // setCentralWidget(stackedWidget);
    // // 将标签设置为窗口的中心部件
    // setCentralWidget(ui->label_image);
}
 
void MainWindow::ConnInit() {
    // connect
    connect(qnode.get(), SIGNAL(rosShutdown()), this, SLOT(close()));  // 接收qnode
    connect(qnode.get(),SIGNAL(image_val(QImage)),this,SLOT(slot_update_image(QImage)));
//    connect(&qnode,SIGNAL(position(double,double,double)),this,SLOT(slot_update_pos(double,double,double)));
    // connect(ui->pushButton_front, SIGNAL(clicked()),this,SLOT(slot_sub_image("pushButton_front")));
    // connect(ui->pushButton_behind, SIGNAL(clicked()),this,SLOT(slot_sub_image("ppushButton_behind")));
    connect(ui->pushButton_front, SIGNAL(clicked()),this,SLOT(slot_sub_image_front()));
    connect(ui->pushButton_behind, SIGNAL(clicked()),this,SLOT(slot_sub_image_behind()));
    // ui->label_image->setText("等待视频图像数据...");

    connect(ui->menubar,SIGNAL(triggered(QAction*)),this,SLOT(trigerMenu(QAction*)));  // 菜单设置触发
    connect(configWindow.get(), SIGNAL(dataModified(const std::unordered_map<std::string, std::string>&)), this, SLOT(handleDataModified(const std::unordered_map<std::string, std::string>&)));  // 信息登记窗口信号接收-槽函数调用
    connect(this->timer, SIGNAL(timeout()), this, SLOT(labelConnectUpdate()));
    timer->start(1000);

    // 获取表格的 horizontalHeader
    QHeaderView* header = ui->tableView->horizontalHeader();
    // 连接 sectionClicked 信号到自定义槽函数
    QObject::connect(header, &QHeaderView::sectionClicked, this, &MainWindow::onHeaderClicked);
}

void MainWindow::slot_update_image(QImage im)
{
    // MyDebug("更新图片");
    ui->label_image->resize(this->size());
    // 按比例缩放图片
    QPixmap pixmap = QPixmap::fromImage(im);
    int width = ui->label_image->width();    
    int height = ui->label_image->height();    
    QPixmap fitpixmap = pixmap.scaled(width, height, Qt::KeepAspectRatio, Qt::SmoothTransformation); //按比例缩放    
    ui->label_image->setPixmap(fitpixmap);
    // ui->label_image->setPixmap(QPixmap::fromImage(im));
}

void MainWindow::slot_sub_image_front()
{   
    // MyDebug("front button clicked");
    std::string imageTopic = "/usb_cam/image_raw";
    if(sysStat.isRun && sysStat.isInput) {
        qnode->sub_image(imageTopic);
        sysStat.isDisplay = true;
    } else if(sysStat.isRun) {
        QMessageBox::warning(this, "警告", "请先录入任务信息！");
    } else if(sysStat.isInput) {
        QMessageBox::warning(this, "警告", "系统未连接，请先点击连接按钮！");
    } else QMessageBox::warning(this, "警告", "请连接系统，并录入检测信息！");
}

void MainWindow::slot_sub_image_behind()
{
    // std::string imageMode = "pushButton_front";
    // std::string imageTopic;
    // // 订阅云台摄像头图像
    // if(imageMode == "pushButton_front") imageTopic = "/usb_cam/image_raw";
    // // 订阅后置摄象头图像
    // else if(imageMode == "pushButton_behind") imageTopic = "/usb_cam/image_raw";
    // qnode.sub_image(imageTopic);

    // MyDebug("behind button clicked");
    std::string imageTopic = "/usb_cam1/image_raw";
    if(sysStat.isRun && sysStat.isInput) {
        qnode->sub_image(imageTopic);
        sysStat.isDisplay = true;
    } else if(sysStat.isRun) {
        QMessageBox::warning(this, "警告", "请先录入任务信息！");
    } else if(sysStat.isInput) {
        QMessageBox::warning(this, "警告", "系统未连接，请先点击连接按钮！");
    } else QMessageBox::warning(this, "警告", "请连接系统，并录入检测信息！");
}

/******************************************
** Auto-connections (connectSlotsByName())
*******************************************/
void MainWindow::on_pushButton_connect_clicked() {
    if(!sysStat.isRun) {
        if(qnode->init()) {
            QMessageBox::information(this, "提示", "ROS已连接");
            ui->label_connect->setText("已连接");
            sysStat.isRun = true;
            // 更改连接图标为绿色
            QDir dir(qApp->applicationDirPath());
            dir.cd("../../../src/camera_display/resources/images");
            QPixmap pixmap(dir.absoluteFilePath("已连接.png"));
            ui->label_connect->setPixmap(pixmap);
            this->timer->stop();  // 停止更新指示灯
            ui->label_connect->setEnabled(true);  // 一直显示当前颜色(绿色)
        } else {
            QMessageBox::warning(this, "警告", "连接失败，请检查是否启动ROS节点！");
        }
    }
}

void MainWindow::on_pushButton_quit_clicked() {
    if(QMessageBox::question(this,"提示", "确定退出检测系统？", tr("取消"), tr("确定"))) {
        this->close();
    }
}

void MainWindow::on_pushButton_back_clicked() {
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::trigerMenu(QAction* act)
{
    if(act->text() == "信息录入")
    {
        configWindow->show();
    }

    if(act->text() == "信息查询")
    {
        if(!db.isOpen()) {  // 数据库未连接
            QMessageBox::warning(this, "警告", "系统数据库未连接!");
        } else {  // 查询并显示
            QString str = QString("select * from tasks");
            model->setQuery(str);  //执行查询操作，并将结果集保存到 model 对象中
            // ui->tableView->setModel(model.get());  // 显示查询结果
            proxyModel->setSourceModel(model.get()); // 设置源模型为原始的 QSqlQueryModel 对象
            ui->tableView->setModel(proxyModel.get());  // 设置代理模型为表格视图的模型
            ui->stackedWidget->setCurrentIndex(1);
        }
    }

    if(act->text() == "启动声呐")
    {
        QMessageBox::warning(this, "警告", "声呐未连接！");
    }
}


void MainWindow::handleDataModified(const std::unordered_map<std::string, std::string>& modifiedData) {
    sysStat.isInput = true;
    // 更新标签显示数据
    ui->label_dectPlace_input->setText(QString::fromStdString(modifiedData.at("place")));
    ui->label_dectTye_input->setText(QString::fromStdString(modifiedData.at("pipeType")));
    ui->label_pipeType_input->setText(QString::fromStdString(modifiedData.at("pipeMaterial")));
    ui->label_pipeD_input->setText(QString::fromStdString(modifiedData.at("pipeSize")));
    ui->label_dectDirect_input->setText(QString::fromStdString(modifiedData.at("direction")));

    ui->label_dectNum_input->setText(QString::fromStdString(modifiedData.at("num")));
    ui->label_dectStart_input->setText(QString::fromStdString(modifiedData.at("startNum")));
    ui->label_dectEnd_input->setText(QString::fromStdString(modifiedData.at("endNum")));
    ui->label_pipeUnit_input->setText(QString::fromStdString(modifiedData.at("unit")));
    ui->label_dectPeople_input->setText(QString::fromStdString(modifiedData.at("person")));

    // 更新数据库数据
    // 如果任务编号没有改变，则update更新; 否则insert一条新数据
    updateDatabase(modifiedData, "tasks");

    // 发送信号：日期+任务编号
    // 更新视频名
    this->videoName = QString::fromStdString(modifiedData.at("date") + modifiedData.at("num"));
    emit fileName(this->videoName.toStdString());
}

bool MainWindow::mysqlInit() {
    // qDebug() << QSqlDatabase::drivers();
    // for(auto& str: QSqlDatabase::drivers()) {
    //     MyDebug(str.toStdString());
    // }
    // 设置表格行高自适应
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);  // 自动设置行高
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);  // 自动设置行高

    // 数据库初始化
    // db.setConnectOptions("MYSQL_OPT_SET_CHARSET_NAME=utf8mb4");
    db.setHostName("localhost");  //database ip address
    db.setUserName("root");   //database username
    db.setPassword("123456");   //database password
    db.setDatabaseName("detect_info");     //database table name

    if(db.open() == true) {
        return true;
    } else {
        // qDebug() << "Database error:" << db.lastError().text();
        // MyDebug("Database error:" + db.lastError().text().toStdString());
        QMessageBox::warning(this, "警告", "数据库连接失败！请检查数据库服务并重启系统！");
        return false;
    }
    // ui->tableView->setModel(proxyModel.get());  // 设置代理模型为表格视图的模型
}

void MainWindow::onHeaderClicked(int logicalIndex) {
    static bool flag = false;
//    QSortFilterProxyModel* proxyModel = qobject_cast<QSortFilterProxyModel*>(ui->tableView->model());
    if (proxyModel)
    {
        if(flag) {
            proxyModel->sort(logicalIndex, Qt::AscendingOrder); // 使用代理模型进行排序操作
            flag = false;
            // qDebug() << logicalIndex;
        } else {
            proxyModel->sort(logicalIndex, Qt::DescendingOrder); // 使用代理模型进行排序操作
            flag = true;
            // qDebug() << logicalIndex;
        }
    }
}

void MainWindow::updateDatabase(const std::unordered_map<std::string, std::string>& modifiedData, const QString&& tableName) {
    MyDebug("更新数据");

    // 获取任务日期和任务编号的值
    QString taskDate = QString::fromStdString(modifiedData.at("date")).toUtf8();
    QString taskNum = QString::fromStdString(modifiedData.at("num"));

    // 判断数据库中是否存在相同任务日期和任务编号的记录
    QSqlQuery query(db);
    // QSqlQuery query = QSqlQuery(db);
    query.prepare("SELECT 任务编号 FROM " + tableName + " WHERE 检测日期 = :taskDate AND 任务编号 = :taskNum");
    query.bindValue(":taskDate", taskDate);
    query.bindValue(":taskNum", taskNum);
    // MyDebug("exec: " + query.exec() ? "true" : "false");  // 检查exec函数执行结果
    // MyDebug("next: " + query.next() ? "true" : "false");  // 检查next函数结果
    // if (query.exec() && query.next()) {  // next导致if判断失败,去掉后正常
    if (query.exec()) {
        MyDebug("sql语句执行成功");
        // int rowCount = query.value(0).toInt();
        int rowCount = query.size();
        MyDebug("表的行数：" + std::to_string(rowCount));
        MyDebug("SQL: " + sqlCheck(query));
        if (rowCount > 0) {
            // 存在相同记录，执行更新操作
            MyDebug("数据已存在,更新");
            query.prepare("UPDATE " + tableName + " SET 检测日期 = :taskDate, 任务编号 = :taskNum, 任务名称 = :name, 检测地点 = :place, 管道类型 = :pipeType, 管道材质 = :pipeMaterial, 管径 = :pipeSize, 检测方向 = :direction, 起始井号 = :startNum, 结束井号 = :endNum, 检测单位 = :unit, 检测员 = :person WHERE 检测日期 = :taskDate AND 任务编号 = :taskNum");
        } else {
            // 不存在相同记录，执行插入操作
            MyDebug("数据不存在, 插入");
            query.prepare("INSERT INTO " + tableName + " (检测日期, 任务名称, 任务编号, 检测地点, 管道类型, 管道材质, 管径, 检测方向, 起始井号, 结束井号, 检测单位, 检测员) VALUES (:taskDate, :name, :taskNum, :place, :pipeType, :pipeMaterial, :pipeSize, :direction, :startNum, :endNum, :unit, :person)");
        }

        // 绑定参数
        query.bindValue(":taskDate", taskDate);
        query.bindValue(":taskNum", taskNum);
        query.bindValue(":place", QString::fromStdString(modifiedData.at("place")));
        query.bindValue(":pipeType", QString::fromStdString(modifiedData.at("pipeType")));
        query.bindValue(":pipeMaterial", QString::fromStdString(modifiedData.at("pipeMaterial")));
        query.bindValue(":pipeSize", QString::fromStdString(modifiedData.at("pipeSize")));
        query.bindValue(":direction", QString::fromStdString(modifiedData.at("direction")));
        // query.bindValue(":num", QString::fromStdString(modifiedData.at("num")));
        query.bindValue(":startNum", QString::fromStdString(modifiedData.at("startNum")));
        query.bindValue(":endNum", QString::fromStdString(modifiedData.at("endNum")));
        query.bindValue(":unit", QString::fromStdString(modifiedData.at("unit")));
        query.bindValue(":person", QString::fromStdString(modifiedData.at("person")));
        query.bindValue(":name", QString::fromStdString(modifiedData.at("name")));

        // 执行SQL语句
        if (query.exec()) {
            MyDebug("更新成功");
            // qDebug() << "Database update/insert successful";
            // 更新模型数据
            model->setQuery("SELECT * FROM " + tableName);
        } else {
            MyDebug("更新失败");
            MyDebug("error: " + query.lastError().text().toStdString());
            MyDebug("SQL: " + sqlCheck(query));
            // qDebug() << "Database update/insert failed: " << query.lastError().text();
        }
    } else {
        // qDebug() << "Database query failed: " << query.lastError().text();
        MyDebug("error: " + query.lastError().text().toStdString());
        // MyDebug("sql: " + query.lastQuery().toStdString());
        MyDebug("SQL: " + sqlCheck(query));

    }
}

void MainWindow::on_pushButton_video_clicked() {
    // QString folderPath = "/home/piperobot/Videos"; // 指定文件夹的路径

    // 使用QDesktopServices打开指定路径的文件夹
    if (QDir(this->videoFolder).exists()) {
        QDesktopServices::openUrl(QUrl::fromLocalFile(this->videoFolder));
    } else {
        QMessageBox::warning(this, "文件夹不存在", "指定的文件夹路径不存在！");
    }
}

// // 本地导出功能实现，将本地数据导出到U盘
// void MainWindow::copyToUSB() {
//     // QString sourceFolderPath = "/home/piperobot/Videos"; // 源文件夹路径
//     QString usbFolderPath = ""; // U盘文件夹路径
//     if((usbFolderPath = getUSBFolderPath()).isEmpty()) {
//         QMessageBox::warning(this, "未找到U盘", "没有检测到插入的U盘！");
//         return;
//     }
//     MyDebug("U盘路径：" + usbFolderPath.toStdString());

//     QDir sourceDir(this->videoFolder);
//     QDir usbDir(usbFolderPath);

//     if (!sourceDir.exists()) {
//         QMessageBox::warning(this, "源文件夹不存在", "指定的源文件夹路径不存在！");
//         return;
//     }

//     if (!usbDir.exists()) {
//         QMessageBox::warning(this, "U盘文件夹不存在", "指定的U盘文件夹路径不存在！");
//         return;
//     }

//     QFileInfoList fileList = sourceDir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
//     int numFiles = fileList.size();  // 文件总数

//     // 创建进度对话框
//     // QProgressDialog progressDialog("导出文件", "取消", 0, numFiles, this);
//     QApplication::processEvents();
//     std::unique_ptr<QProgressDialog> progressDialog(new QProgressDialog("导出文件", "取消", 0, numFiles, this));
//     progressDialog->setValue(0);
//     progressDialog->setWindowModality(Qt::WindowModal);
//     progressDialog->setWindowTitle("文件导出进度");  // 窗口标题
    
//     progressDialog->setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint);		//不显示进度条上的“最小化”“最大化”“关闭”
//     // progressDialog->setAutoClose(false);		//进度达到最大值时不关闭，默认为true
//     progressDialog->setLabelText("文件传输中...");	 //显示的文本
//     // progressDialog.setRange(0,100);				//设置进度条的极值，默认为[0,100]
//     // progressDialog.setCancelButton(NULL);		//不显示取消按钮
//     progressDialog->resize(this->width()*0.45, this->height()*0.1);
//     progressDialog->show();						//进度条显示

//     // 连接信号和槽函数，以更新进度条的值
//     // connect(this, &MainWindow::updateProgressValue, &progressDialog, &QProgressDialog::setValue);

//     int progress = 0;

//     foreach (const QFileInfo& fileInfo, fileList) {
//         QApplication::processEvents();
//         if (progressDialog->wasCanceled()) {
//             break;
//         }

//         QString fileName = fileInfo.fileName();
//         QString sourceFilePath = fileInfo.filePath();
//         QString usbFilePath = usbDir.filePath(fileName);

//         if (QFile::exists(usbFilePath)) {
//             // 如果U盘中已存在同名文件，跳过复制
//             progress++;
//             progressDialog->setValue(progress);
//             // emit updateProgressValue(progress);
//             continue;
//         }

//         if (fileInfo.isDir()) {
//             // 如果是子文件夹，递归复制文件夹
//             QDir subSourceDir(sourceFilePath);
//             QDir subUsbDir(usbFilePath);
//             copyDirectory(subSourceDir, subUsbDir);
//         } else {
//             // 复制文件
//             QFile::copy(sourceFilePath, usbFilePath);
//         }
//         progress++;
//         progressDialog->setValue(progress);
//         // emit updateProgressValue(progress);
//     }

//     if (progressDialog->wasCanceled()) {
//         QMessageBox::information(this, "复制取消", "文件夹复制到U盘已取消！");
//     } else {
//         QMessageBox::information(this, "复制完成", "文件夹复制到U盘成功！");
//     }

// }

// // 文件夹复制
// void MainWindow::copyDirectory(const QDir& sourceDir, const QDir& targetDir) {
//     if (!targetDir.exists()) {
//         targetDir.mkdir(targetDir.absolutePath());
//     }

//     QFileInfoList fileList = sourceDir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);

//     foreach (const QFileInfo& fileInfo, fileList) {
//         QString fileName = fileInfo.fileName();
//         QString sourceFilePath = fileInfo.filePath();
//         QString targetFilePath = targetDir.filePath(fileName);

//         if (fileInfo.isDir()) {
//             // 如果是子文件夹，递归复制文件夹
//             QDir subSourceDir(sourceFilePath);
//             QDir subTargetDir(targetFilePath);
//             copyDirectory(subSourceDir, subTargetDir);
//         } else {
//             // 复制文件
//             QFile::copy(sourceFilePath, targetFilePath);
//         }
//     }
// }

QString MainWindow::getUSBFolderPath() {
    foreach (const QStorageInfo& storage, QStorageInfo::mountedVolumes()) {
        if (storage.isValid() && storage.isReady() && storage.rootPath().contains("media")) {
            return storage.rootPath();
        }
    }
    return QString();
}


void CopyThread::copyDirectory(const QDir& sourceDir, const QDir& targetDir) {
    if (!targetDir.exists()) {
        targetDir.mkdir(targetDir.absolutePath());
    }

    QFileInfoList fileList = sourceDir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);

    foreach (const QFileInfo& fileInfo, fileList) {
        QString fileName = fileInfo.fileName();
        QString sourceFilePath = fileInfo.filePath();
        QString targetFilePath = targetDir.filePath(fileName);

        if (fileInfo.isDir()) {
            // 如果是子文件夹，递归复制文件夹
            QDir subSourceDir(sourceFilePath);
            QDir subTargetDir(targetFilePath);
            copyDirectory(subSourceDir, subTargetDir);
        } else {
            // 复制文件
            QFile::copy(sourceFilePath, targetFilePath);
        }
    }
} 

// 使用多线程拷贝
void MainWindow::copyToUSB() {
    // QString sourceFolderPath = "/home/piperobot/Videos"; // 源文件夹路径
    QString usbFolderPath = ""; // U盘文件夹路径
    if((usbFolderPath = getUSBFolderPath()).isEmpty()) {
        QMessageBox::warning(this, "未找到U盘", "没有检测到插入的U盘！");
        return;
    }
    MyDebug("U盘路径：" + usbFolderPath.toStdString());

    QDir sourceDir(this->videoFolder);
    QDir usbDir(usbFolderPath);

    if (!sourceDir.exists()) {
        QMessageBox::warning(this, "源文件夹不存在", "指定的源文件夹路径不存在！");
        return;
    }

    if (!usbDir.exists()) {
        QMessageBox::warning(this, "U盘文件夹不存在", "指定的U盘文件夹路径不存在！");
        return;
    }

    // progressDialog = std::make_unique<QProgressDialog>(new QProgressDialog("导出文件", "取消", 0, 100, this));
    progressDialog = new QProgressDialog("数据导出", "取消", 0, 100, this);
    progressDialog->setValue(0);
    progressDialog->setWindowModality(Qt::WindowModal);
    progressDialog->setWindowTitle("文件导出进度");  // 窗口标题
    progressDialog->setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint);		//不显示进度条上的“最小化”“最大化”“关闭”
    // progressDialog->setAutoClose(false);		//进度达到最大值时不关闭，默认为true
    progressDialog->setLabelText("文件传输中...");	 //显示的文本
    // progressDialog.setRange(0,100);				//设置进度条的极值，默认为[0,100]
    progressDialog->setCancelButton(NULL);		//不显示取消按钮
    progressDialog->resize(this->width()*0.45, this->height()*0.1);
    progressDialog->show();						//进度条显示

    CopyThread* th = new CopyThread(this->videoFolder, usbFolderPath);  // 创建子线程
    // 连接信号与槽函数
    connect(th, SIGNAL(filesUpdated(int, int)), this->progressDialog, SLOT(setRange(int, int)));  // 更新进度条范围
    connect(th, SIGNAL(progressUpdated(int)), this->progressDialog, SLOT(setValue(int)));  // 更新进度条的值
    connect(th, SIGNAL(finished(bool)), this, SLOT(copyMessage(bool)));  // 状态消息
    th->start();
}

void CopyThread::run() {
    QDir sourceDir(this->sourceFolderPath_);
    QDir usbDir(this->usbFolderPath_);

    QFileInfoList fileList = sourceDir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
    int numFiles = fileList.size();  // 文件总数
    emit filesUpdated(0, numFiles);

    int progress = 0;
    foreach (const QFileInfo& fileInfo, fileList) {  // foreach是qt函数
        QString fileName = fileInfo.fileName();
        QString sourceFilePath = fileInfo.filePath();
        QString usbFilePath = usbDir.filePath(fileName);

        if (QFile::exists(usbFilePath)) {
            // 如果U盘中已存在同名文件，跳过复制
            emit progressUpdated(++progress);
            continue;
        }

        if (fileInfo.isDir()) {
            // 如果是子文件夹，递归复制文件夹
            QDir subSourceDir(sourceFilePath);
            QDir subUsbDir(usbFilePath);
            copyDirectory(subSourceDir, subUsbDir);
        } else {
            // 复制文件
            QFile::copy(sourceFilePath, usbFilePath);
        }
        emit progressUpdated(++progress);
    }

    if(progress == numFiles) {
        emit finished(true);
    } else emit(finished(false));
}

void MainWindow::on_pushButton_datainput_clicked() {
    MyDebug("信息录入");
    configWindow->show();
}

void MainWindow::on_pushButton_datasearch_clicked() {
    if(!db.isOpen()) {  // 数据库未连接
        QMessageBox::warning(this, "警告", "系统数据库未连接!");
    } else {  // 查询并显示
        QString str = QString("select * from tasks");
        model->setQuery(str);  //执行查询操作，并将结果集保存到 model 对象中
        // ui->tableView->setModel(model.get());  // 显示查询结果
        proxyModel->setSourceModel(model.get()); // 设置源模型为原始的 QSqlQueryModel 对象
        ui->tableView->setModel(proxyModel.get());  // 设置代理模型为表格视图的模型
        ui->stackedWidget->setCurrentIndex(1);
    }
}

void MainWindow::on_pushButton_localvideo_clicked() {
    // 使用QDesktopServices打开指定路径的文件夹
    if (QDir(this->videoFolder).exists()) {
        QDesktopServices::openUrl(QUrl::fromLocalFile(this->videoFolder));
    } else {
        QMessageBox::warning(this, "文件夹不存在", "指定的文件夹路径不存在！");
    }
}

void MainWindow::on_pushButton_utrans_clicked() {
    MyDebug("copy to USB");
    copyToUSB();
}

void MainWindow::on_pushButton_upload_clicked() {
    QMessageBox::warning(this, "服务器未连接", "请检查网络连接！");
}

void MainWindow::copyMessage(bool flag) {
    if (!flag) {
        QMessageBox::warning(this, "失败", "数据导出失败！");
    } else {
        QMessageBox::information(this, "完成", "数据已全部导出至U盘！");
    }
    delete this->progressDialog;
}

void MainWindow::on_pushButton_finish_clicked() {
    if(sysStat.isDisplay && sysStat.isSave) {
        // 设置按钮状态
        ui->pushButton_start->setEnabled(true);
        ui->pushButton_finish->setEnabled(false);
        ui->pushButton_datainput->setEnabled(true);  // 检测结束，可录入新任务信息
        // 设置系统状态
        sysStat.isInput = false;
        sysStat.isSave = false;

        emit this->finUpdate(true);
        QMessageBox::information(this, "提示", this->videoName + "检测任务完成，视频数据已储存。若要开始新任务，请重新录入检测信息。");
    }
}

// 检测开始，开始录制视频文件
void MainWindow::on_pushButton_start_clicked() {
    // 确保有视频数据，且不在录制状态，且已经录入信息
    if(sysStat.isDisplay && !sysStat.isSave && sysStat.isInput) {
        // 设置按钮状态
        ui->pushButton_start->setEnabled(false);
        ui->pushButton_finish->setEnabled(true);
        ui->pushButton_datainput->setEnabled(false);  // 检测开始，不可录入新任务信息
        // 通知node节点开始录制视频文件
        emit this->finUpdate(false);
        // 更改系统状态
        sysStat.isSave = true;  // 正在存储视频
        QMessageBox::information(this, "提示", "检测开始，正在录制检测视频。");
    } else {
        QMessageBox::warning(this, "提示", "请选择视频源，等待出现视频画面！");
    }
}

void MainWindow::on_pushButton_sonar_clicked() {
    QMessageBox::warning(this, "警告", "声呐未连接！");
}

void MainWindow::labelConnectUpdate() {
    static bool flag = 0;
    flag = !flag;
    ui->label_connect->setEnabled(flag);
}