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

#include "ui_messaging_base/ui_messaging_base.hpp"

UiMessagingBase::UiMessagingBase()
{
	n_ = ros::NodeHandle();
}

UiMessagingBase::UiMessagingBase( ros::NodeHandle n )
	: n_(n)
{
}

UiMessagingBase::~UiMessagingBase()
{
    
}