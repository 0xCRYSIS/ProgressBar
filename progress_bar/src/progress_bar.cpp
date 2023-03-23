#include<ros/ros.h>
#include<unistd.h>

int msg_count = 2917;
int PBID = 2917/25; // progress bar integer div
int PBMD = 2917%25; // progress bar modulus div
int PID = 2917/100;
int PMD = 2917%100;

int msg_pointer = 0;
int bar_count = 0;
bool bar_flag = true;

std::string LC = "\033[1;32m";
std::string RC = "\033[0m";

std::vector<std::string> progress_bar{"[",LC," ",RC,
                                          LC," ",RC,
                                          LC," ",RC,
                                          LC," ",RC,
                                          LC," ",RC,
                                          LC," ",RC,
                                          LC," ",RC,
                                          LC," ",RC,
                                          LC," ",RC,
                                          LC," ",RC,
                                          LC," ",RC,
                                          LC," ",RC,
                                          LC," ",RC,
                                          LC," ",RC,
                                          LC," ",RC,
                                          LC," ",RC,
                                          LC," ",RC,
                                          LC," ",RC,
                                          LC," ",RC,
                                          LC," ",RC,
                                          LC," ",RC,
                                          LC," ",RC,
                                          LC," ",RC,
                                          LC," ",RC,
                                          LC," ",RC,
                                          LC," ",RC,"]"};

std::map<int,int> map_bar = {{0,2},{1,5},{2,8},{3,11},{4,14},{5,17},{6,20},{7,23},{8,26},{9,29},{10,32},
                             {11,35},{12,38},{13,41},{14,44},{15,47},{16,50},{17,53},{18,56},{19,59},{20,62},{21,65},
                             {22,68},{23,71},{24,74},{25,77}};

std::string get_progress_bar(int bar_pos = -1)
{
    std::string pb;
    
    if(bar_pos == -1)
    {
        for(auto i : progress_bar)
        {
            pb += i;
        }
    }
    
    else
    {
        progress_bar[map_bar[bar_pos]] = "|";
        for(auto i : progress_bar)
        {
            pb += i;
        }
    }


    return pb;
}

int main(int argc,char **argv)
{
    ros::init(argc,argv,"ProgressBarNode");
    ros::NodeHandle n;
    ROS_INFO("--------------- Progress bar ------------");

    std::cout << get_progress_bar() << std::endl;

    // iterate over msg count
    for(int MSG_COUNT=0 ; MSG_COUNT <= msg_count ; MSG_COUNT++)
    {

        // std::cout << get_progress_bar(i) << "\r" << std::flush;
        if(msg_pointer%PBID==0 && bar_flag)
        {
            std::cout << get_progress_bar(bar_count) << "\r" << msg_pointer <<std::flush;
            bar_count += 1;
        }

        // check if inter parts are covered
        if(bar_count == 25){bar_flag = false;}

        // // check if msg pointer has reached the end
        // if()

        // std::cout << get_progress_bar() << msg_pointer << "\r" <<std::flush;

        msg_pointer += 1;
        // sleep(1);
    }

    std::cout << std::endl;

    ros::spin();

    return 0;
}