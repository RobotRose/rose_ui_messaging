/***********************************************************************************
* Copyright: Rose B.V. (2014)
*
* Revision History:
*  Author: Loy van Beek
*  Date  : 2014/08/26
*     - File created.
*
* Description:
*  Helper class to send messages, actions and warnings to the Rose GUI with the least amount of code and setup.
* 
***********************************************************************************/
#include "operator_messaging/operator_messaging.hpp"

OperatorMessaging::OperatorMessaging()
    : UiMessagingBase()
{
    initPublishers();
} 

OperatorMessaging::OperatorMessaging(ros::NodeHandle n ) 
    : GuiMessaging(n)
{
    initPublishers();
}

OperatorMessaging::~OperatorMessaging()
{

}

void OperatorMessaging::initPublishers()
{
    message_pub_  = n_.advertise<std_msgs::String>("/messages_window/message", 10);
    action_pub_   = n_.advertise<std_msgs::String>("/messages_window/action",  10);
    warn_pub_     = n_.advertise<std_msgs::String>("/messages_window/warning", 10);
}

void OperatorMessaging::message(std::string message)
{
    std_msgs::String msg;
    msg.data = message.c_str();

    ROS_INFO_NAMED(ROS_NAME, "OperatorMessaging::message: %s", msg.data.c_str());

    message_pub_.publish(msg);
}

void OperatorMessaging::action(std::string action)
{
    std_msgs::String msg;
    msg.data = action.c_str();

    ROS_INFO_NAMED(ROS_NAME, "OperatorMessaging::action: %s", msg.data.c_str());

    action_pub_.publish(msg);
}

void OperatorMessaging::warn(std::string warn)
{
    std_msgs::String msg;
    msg.data = warn.c_str();

    ROS_INFO_NAMED(ROS_NAME, "OperatorMessaging::warn: %s", msg.data.c_str());

    warn_pub_.publish(msg);
}