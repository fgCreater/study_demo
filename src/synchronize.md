## message_filters时间同步介绍：
message_filters 是 ROS（机器人操作系统）中的一个功能包，用于实现多个传感器数据或消息的时间同步。它提供了一个简单而灵活的接口，可以方便地对不同话题发布的消息进行时间戳的同步，以确保数据在处理时具有一致的时间对齐。


具体的实现步骤如下：
1.创建一个 message_filters::Subscriber 对象来监听需要同步的话题，并指定消息类型。
2.创建一个 message_filters::Cache 对象来管理接收到的消息，并指定缓存的大小和策略（例如 ApproximateTime 或 ExactTime）。
3.创建一个回调函数，用于处理同步后的消息。该回调函数会在同步消息到达时被触发，并接收同步后的消息作为参数。
4.使用 message_filters::Synchronizer 类将订阅者、缓存和回调函数组合在一起，并设置同步的时间窗口大小等参数。
5.调用 Synchronizer 对象的 registerCallback() 函数来注册回调函数。