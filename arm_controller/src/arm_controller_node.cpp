#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sensor_msgs/JointState.h"
#include "std_msgs/Float64.h"
#include <sstream>

void jointStateCallback(const sensor_msgs::JointState::ConstPtr& msg) {
	/*
    ROS_INFO("Dati sugli stati dei giunti ricevuti:");
    ROS_INFO("Timestamp: %f", msg->header.stamp.toSec());
    ROS_INFO("Frame di riferimento: %s", msg->header.frame_id.c_str());
    */
    
    /*
    ROS_INFO("Nomi dei giunti:");
    for (size_t i = 0; i < msg->name.size(); i++) {
        ROS_INFO("%s", msg->name[i].c_str());
    }
    */
    
    ROS_INFO("Posizioni dei giunti:");
    for (size_t i = 0; i < msg->position.size(); i++) {
    	ROS_INFO("%s", msg->name[i].c_str());
        ROS_INFO("%f", msg->position[i]);
    }
    
    /*
    ROS_INFO("Velocita' dei giunti:");
    for (size_t i = 0; i < msg->velocity.size(); i++) {
        ROS_INFO("%f", msg->velocity[i]);
    }
    */
    /*
    ROS_INFO("Sforzi dei giunti:");
    for (size_t i = 0; i < msg->effort.size(); i++) {
        ROS_INFO("%f", msg->effort[i]);
    }
    */
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "arm_controller_node");
    ros::NodeHandle n;


    // Subscribers
    ros::Subscriber sub = n.subscribe("arm/joint_states", 1000, jointStateCallback);

    // Publisher
    ros::Publisher arm_J0_pub = n.advertise<std_msgs::Float64>("/arm/PositionJointInterface_J0_controller/command", 1000);
    ros::Publisher arm_J1_pub = n.advertise<std_msgs::Float64>("/arm/PositionJointInterface_J1_controller/command", 1000);
    ros::Publisher arm_J2_pub = n.advertise<std_msgs::Float64>("/arm/PositionJointInterface_J2_controller/command", 1000);
    ros::Publisher arm_J3_pub = n.advertise<std_msgs::Float64>("/arm/PositionJointInterface_J3_controller/command", 1000);

    ros::Rate loop_rate(10);


    while (ros::ok()) {
    
 // Creazione di un vettore di 4 elementi di tipo std_msgs::Float64
    std::vector<std_msgs::Float64> msg_vector(4);

    // Assegnazione di valori ai singoli elementi del vettore
    msg_vector[0].data = 1.6;
    msg_vector[1].data = -1;
    msg_vector[2].data = 1.3;
    msg_vector[3].data = -1;


        // Publish to all joint controllers
        arm_J0_pub.publish(msg_vector[0]);
        arm_J1_pub.publish(msg_vector[1]);
        arm_J2_pub.publish(msg_vector[2]);
        arm_J3_pub.publish(msg_vector[3]);

        ros::spinOnce();
        loop_rate.sleep();
   /*In questo modo, ros::spinOnce() all'interno del ciclo while consente di elaborare i messaggi in arrivo sul subscriber mentre il nodo continua a pubblicare messaggi con il publisher. Questo assicura che il nodo funzioni correttamente sia come subscriber che come publisher.*/
    }

    return 0;
}

