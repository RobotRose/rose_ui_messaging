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
#ifndef OPERATOR_MESSAGING_HPP
#define OPERATOR_MESSAGING_HPP

#include "ros_name/ros_name.hpp"                    // For using ROS_NAME

#include "ui_messaging_base/ui_messaging_base.hpp"  // The base class

class OperatorMessaging : public UiMessagingBase
{
  public:
    OperatorMessaging();
    OperatorMessaging(ros::NodeHandle n );
    ~OperatorMessaging();    

    /**
     * Send a message to the GUI. This if just for informational messages, the user does not have to do anything with such a message
     * @param message The message to be delivered to the operator
     */
    void message(std::string message);

    /**
     * Request an action from the operator via the GUI. There is no guarantee the operator will see or act upon this message.
     * @param action The action for the operator to perform
     */
    void action(std::string action);

    /**
     * Send a warning message to the operator GUI. 
     * @param warn warning message
     */
    void warn(std::string warn);

private:
    /**
     * Initialize the message publishers
     */
    void initPublishers();

  private:
    ros::Publisher  message_pub_;
    ros::Publisher  action_pub_;
    ros::Publisher  warn_pub_;
};

#endif //OPERATOR_MESSAGING_HPP