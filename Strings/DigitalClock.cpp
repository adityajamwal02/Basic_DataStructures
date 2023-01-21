/*
You are building a logic for a clock that requires you convert absolute time in minutes into a format supported by a digital clock. See examples below.
125 minutes can be displayed as 2:05
155 minutes can be displayed as 2:35
(You can assume the maximum value of minutes will be less than 24 X 60)
Input
Input is a single integer.
1180
Output
Output is a string denoting the digital clock time.
19:40
Hint
You can use the to_string(int)  method to convert an integer into string.
*/

#include<string>
using namespace std;

string convert_to_digital_time(int minutes){
    string result;
    int hours=minutes/60;
    int min=minutes%60;
    if(min<10){
        result=to_string(hours)+":0"+to_string(min);
    }else{
        result=to_string(hours)+":"+to_string(min);
    }

    return result;
}
