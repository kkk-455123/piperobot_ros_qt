# 管网检测机器人地面支持系统软件
为管道检测机器人提供地面支持，最基本的要为用户提供控制接口与视频图像实时显示的功能，其次是数据导出、信息录入等信息管理功能，核心算法方面提供实时检测与定位。

## 环境
- Ubuntu 20.04  
- C++ 14
- ROS Noetic  
- QT 5.12  
- MySQL 8.0  

## 框架
  使用QT开发，将QT程序作为ROS的节点，基于ROS的分布式通信机制实现系统中各数据的流动。

## 功能
  - 实时视频传输：UDP通信(ROS)，视频编解码(OpenCV)，显示(QT信号与槽 QLabel)。
  - 用户控制：ROS的发布订阅机制
  - 视频保存：opencv
  - 视频数据导出：
     - U盘一键导出
     - 上云（待完善）：本地视频上传至视频存储云服务器，供各单位用户下载检测
  - 信息管理：MySQL相关
  - 算法：
     - 声呐检测（待移植部署）：MATLAB，C/C++混合编程移植
     - 视觉检测：FastDeploy部署，如要实现更灵活的设计，可使用OpenVINO, TensorRT, ONNXruntime等从底层构建优化
     - 定位（待移植部署）
## 目录树
```
.
├── src           源代码
│   ├── camera_display
│   │   ├── include        头文件
│   │   ├── launch         ros launch
│   │   ├── resources      静态资源
│   │   ├── src            源代码
│   │   ├── ui             界面UI
│   │   ├── CMakeLists.txt
│   │   ├── package.xml    ROS包管理
│   ├── ros_handle_control
│   └── CmakeLists.txt
├── build           
├── devel
└── readme.md
```

## 项目启动
## TODO
- 完善云服务器视频存储中转服务与客户端上传/下载业务
- 声呐检测/定位等算法部署与检测结果实时可视化
