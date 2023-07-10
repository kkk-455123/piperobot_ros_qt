#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/Joy.h>
 
class TeleopTurtle
{
public:
    TeleopTurtle();
 
private:
    // 处理手柄发送过来的信息
    void callback(const sensor_msgs::Joy::ConstPtr &joy);
    // 实例化ROS句柄
    ros::NodeHandle nh;
    // 定义订阅者对象，用来订阅手柄发送的数据
    ros::Subscriber sub;
    // 定义发布者对象，用来将手柄数据发布到乌龟控制话题上
    ros::Publisher pub;
    // 用来接收launch文件中设置的参数，绑定手柄摇杆、轴的映射
    int axis_linear, axis_angular;
};
 
TeleopTurtle::TeleopTurtle()
{
    // 从参数服务器读取的参数
    // nh.param<int>("axis_linear", axis_linear, 1);
    // nh.param<int>("axis_angular", axis_angular, 2);
 
    // pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1);
    pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 1);
    sub = nh.subscribe<sensor_msgs::Joy>("joy", 10, &TeleopTurtle::callback, this);
}
 
void TeleopTurtle::callback(const sensor_msgs::Joy::ConstPtr &joy)
{
    geometry_msgs::Twist vel;
    // 将手柄摇杆轴拨动时值的输出赋值给乌龟的线速度和角速度
    // vel.linear.x = joy->axes[axis_linear];
    // vel.angular.z = joy->axes[axis_angular];
    vel.linear.x = joy->axes[1];
    vel.angular.z = joy->axes[3];
    
    ROS_INFO("当前线速度为:%.3lf ; 角速度为:%.3lf", vel.linear.x, vel.angular.z);
    pub.publish(vel);
}
 
int main(int argc, char **argv)
{
    // 设置编码
    setlocale(LC_ALL, "");
    // 初始化ROS节点
    ros::init(argc, argv, "teleop_turtle");
    TeleopTurtle teleopTurtle;
    ros::spin();
    return 0;
}
 
