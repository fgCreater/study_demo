#include"ros/ros.h"
#include "turtlesim/Pose.h"
#include"tf2_ros/transform_broadcaster.h"
#include"geometry_msgs/TransformStamped.h"
#include"tf2/LinearMath/Quaternion.h"
void doPose(const turtlesim::Pose ::&ConstPtr pose ){
    // 设置广播变换器
    static  tf2_ros::TransformBroadcaster broadcast;
    // 创建发布的消息
    geometry_msgs::TransformStamped ts;
    ts.header.frame_id="world";
    ts.header.stamp=ros::Time::now();
    ts.header.seq=10;

    ts.child_frame_id="turtle1";
    // 坐标系相对位置
    ts.transform.translation.x=pose->x;
    ts.transform.translation.y=pose->y;
    ts.transform.translation.z=0;
    // 设置四元数
    tf2::Quaternion qtn;
    qtn.setRPY(0,0,0);
    ts.transform.rotation.x=qtn.getX();
    ts.transform.rotation.y=qtn.getY();
    ts.transform.rotation.z=qtn.getZ();
    ts.transform.rotation.w=qtn.getW();
    broadcast.sendTransform(ts);

}
int main(int argc, char  *argv[])
{
    ros::init(argc,argv,"dynamic_tf_pub");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe<turtlesim::Pose>("/turtle1/pose",1000,doPose);
    ros::spin();
    return 0;                                                                                                                     
}
                                                                                                                                                                 