#include <ros/ros.h>
#include <std_msgs/UInt16.h>
#include <sstream>
#include <iostream>

using namespace std_msgs;
using namespace std;


int main(int argc, char **argv)
{
ros::init(argc, argv, "grip");

ros::NodeHandle nh;

ros::Publisher angle = nh.advertise<UInt16>("servo", 100);

string key;

int i = 90;

    cout << "'P'  closes the gripper and 'O' opens the gripper: \n";

while (ros::ok())
    {
    UInt16 msg;

        //read input from terminal
        key = "";

        cin >> key;

        if(key == "o")
            i = 90;
        else if(key == "p")
            i = 10;

    msg.data = i;
    angle.publish(msg);
    ros::spinOnce();
    }

    return 0;
}
