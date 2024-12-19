#include"ros/ros.h"
#include"tf2_ros/static_transform_broadcaster.h"
#include"geometry_msgs/TransformStamped.h"
#include"tf2/LinearMath/Quaternion.h"
int main(int argc, char  *argv[])
{
    ros::init(argc,argv,"static_broadst");
    // 创建广播变换器
    tf2_ros::StaticTransformBroadcaster brodadcaster;
    // 创建发布信息
    geometry_msgs::TransformStamped ts;
    ts.header.frame_id="base_link";
    ts.header.stamp=ros::Time::now();
    ts.header.seq=10;
    // 偏移量
    ts.transform.translation.x=0.2;
    ts.transform.translation.y=0.3;
    ts.transform.translation.z=0.4;
    ts.child_frame_id="lidar";
    //  把欧拉角转换成四元数
    tf2::Quaternion qtn;
    qtn.setRPY(0,0,0);
    ts.transform.rotation.x=qtn.getX();
    ts.transform.rotation.y=qtn.getY();
    ts.transform.rotation.z=qtn.getZ();
    ts.transform.rotation.w=qtn.getW();
    // 广播消息
    brodadcaster.sendTransform(ts);
    ros::spin();
    return 0;
}
