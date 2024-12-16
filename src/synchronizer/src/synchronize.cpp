/*
    控制台输出 HelloVSCode !!!

*/
#include "ros/ros.h"
#include <message_filters/subscriber.h>
#include <message_filters/synchronizer.h>
#include <message_filters/sync_policies/exact_time.h>
#include <message_filters/sync_policies/approximate_time.h>
#include <math.h>
#include "sensor_msgs/LaserScan.h"
#include "sensor_msgs/NavSatFix.h"
#include <sensor_msgs/PointCloud2.h>
using namespace std;


void callback(const sensor_msgs::PointCloud2::ConstPtr &points_01,const sensor_msgs::PointCloud2::ConstPtr &points_02){
    ROS_INFO("时间同步u");
}
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    //执行节点初始化
    ros::init(argc,argv,"HelloVSCode");
    ros::NodeHandle nh;
    // 1.创建接受消息对象
     message_filters::Subscriber<sensor_msgs::PointCloud2>points_01(nh,"filed_points_01",10);
     message_filters::Subscriber<sensor_msgs::PointCloud2>points_02(nh,"filted_points_02",10);
     //2. message_filters::Cache 对象来管理接收到的消息
    typedef message_filters::sync_policies::ExactTime<sensor_msgs::PointCloud2,sensor_msgs::PointCloud2>MySyncPolicy;
    // typedef message_filters::sync_policies::ApproximateTime<sensor_msgs::PointCloud2,sensor_msgs::PointCloud2>MySyncPolicy2;
    // 3.使用 message_filters::Synchronizer 类将订阅者、缓存和回调函数组合在一起，并设置同步的时间窗口大小等参数
    message_filters:: Synchronizer<MySyncPolicy>sync (MySyncPolicy(10),points_01,points_02);
    // 4.调用 Synchronizer 对象的 registerCallback() 函数来注册回调函数。
    sync.registerCallback(boost::bind(&callback,_1,_2));
    ros::spin();
    //输出日志
    ROS_INFO("Hello VSCode!!!哈哈哈哈   哈哈哈哈哈哈");
    return 0;
}
