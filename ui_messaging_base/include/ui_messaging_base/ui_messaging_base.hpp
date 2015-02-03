/***********************************************************************************
* Copyright: Rose B.V. (2014)
*
* Revision History:
*  Author: Loy van Beek
*  Date  : 2014/08/26
*     - File created.
*
* Description:
* This class is an interface to the User Interface. 
* It can send information (as a string) to that GUI. 
* 
***********************************************************************************/
#ifndef UI_MESSAGING_BASE_HPP
#define UI_MESSAGING_BASE_HPP

#include <ros/ros.h>

#include "std_msgs/String.h"
#include "std_msgs/UInt32.h"

class UiMessagingBase
{
public:   
    /**
     * Instantiate a new GuiMessaging-interface.
     * @param n a ROS nodehandle with which to create publishers and subscribers
     */
    UiMessagingBase();
    UiMessagingBase(ros::NodeHandle n );
    ~UiMessagingBase();

protected:
	ros::NodeHandle n_;
};

#endif // UI_MESSAGING_BASE_HPP
