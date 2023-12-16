#ifndef QNODE_H
#define QNODE_H


/**
 * @file /include/robot_hmi/qnode.hpp
 *
 * @brief Communications central!
 *
 * @date February 2011
 **/

#include <ros/ros.h>

#include <string>
#include <QThread>
#include <QStringListModel>
#include <std_msgs/String.h>
#include "std_msgs/Float32MultiArray.h"
// #include <map>
// #include <geometry_msgs/Twist.h>
// #include <nav_msgs/Odometry.h>
// #include <std_msgs/Float32.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
// #include <geometry_msgs/PoseWithCovarianceStamped.h>
// #include <geometry_msgs/PoseStamped.h>
#include <QImage>

// opencv保存视频图像
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
// #include "mainwindow.h"

class MainWindow;

namespace camera_display {

/*****************************************************************************
** Class
*****************************************************************************/

class QNode : public QThread {
    Q_OBJECT
public:
    QNode(int argc, char** argv, void* ptr);
    virtual ~QNode();
    bool init();
    bool init(const std::string &master_url, const std::string &host_url);
    // void set_cmd_vel(char k,float linear,float angular);
    void sub_image(std::string topic_name);
    // void set_goal(double x,double y,double z);
    void run();
    /*********************
    ** Logging
    **********************/
    // enum LogLevel {
    //          Debug,
    //          Info,
    //          Warn,
    //          Error,
    //          Fatal
    //  };

    // QStringListModel* loggingModel() { return &logging_model; }
    // void log( const LogLevel &level, const std::string &msg);

Q_SIGNALS:
    // void loggingUpdated();
    void rosShutdown();
    // void speed_vel(float,float);
    // void power_vel(float);
    void image_val(QImage);
    void temp_humid_val(float,float);
    // voiQd position(double x,double y,double z);
private:
    int init_argc;
    char** init_argv;
    //ros::Publisher temp_humid_pub;
    // ros::Publisher chatter_publisher;
    // ros::Publisher cmd_vel_pub;
    // ros::Publisher goal_pub;
    // QStringListModel logging_model;
    ros::Subscriber temp_humid_sub;
    // ros::Subscriber chatter_sub;
    // ros::Subscriber odom_sub;
    // ros::Subscriber power_sub;
    // ros::Subscriber amcl_pose_sub;
    image_transport::Subscriber image_sub;
    void image_callback(const sensor_msgs::ImageConstPtr &msg);
    void temp_humid_callback(const std_msgs::Float32MultiArray::ConstPtr& msg);
    // void power_callback(const std_msgs::Float32 &msg);
    // void chatter_callback(const std_msgs::String &msg);
    // void odom_callback(const nav_msgs::Odometry &msg);
    // void amcl_pose_callback(const geometry_msgs::PoseWithCovarianceStamped &msg);
    QImage Mat2QImage(cv::Mat const& src);

    void saveFrameToVideo(const cv::Mat& frame);  // 保存图像帧
    std::string fileName;
    std::string videoFolder;
    bool isFirstFrame;

    bool finFlag;

public slots:
    void fileNameChange(std::string);
    void finChange(bool);
};

}  // namespace camera_display

#include "mainwindow.h"
#endif // QNODE_H