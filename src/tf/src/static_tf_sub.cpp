#include"ros/ros.h"
#include"tf2_ros/buffer.h"
#include"tf2_ros/transform_listener.h"
#include"geometry_msgs/PointStamped.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h" //注意: 调用 transform 必须包含该头文件
int main(int argc, char  *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"static_tf_sub");
    ros::NodeHandle nh;
    // 创建一个butffer缓存
    tf2_ros::Buffer buffer;
    // 创建监听对像给buffer存入值
    tf2_ros::TransformListener listener(buffer);
    // 创建一个坐标点
    geometry_msgs::PointStamped ps;
    ps.header.frame_id="lidar";
    ps.point.x=2;
    ps.point.y=3;
    ps.point.z=1;
    // 添加休眠(要让发布者先发布出来)
    ros::Duration(2).sleep();
    // 转换坐标点
    geometry_msgs::PointStamped ps_out;
    ps_out=buffer.transform(ps,"base_link");
    ROS_INFO("%.2f,%.2f,%.2f, 参考的坐标系:%s",
    ps_out.point.x,
    ps_out.point.y,
    ps_out.point.z,
    ps_out.header.frame_id.c_str()
    );
    return 0;
}
