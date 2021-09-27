    /*
    Duration
    Allowing the user to perform various operations of Duration
    Albert Hung
    */
    #include <iostream>//importing the necessary preprocessor directives
    #include <string>
    #include <cstring>
    #include <sstream>
    #include<time.h>
    using namespace std;//choosing a namespace so I don't have to type out std 
    int inputMin, inputSec, inputHours, holder, inputOption, input, inputC, inputMin2, inputSec2, inputHours2 = 0;
    bool rerun = true;
    #ifndef DURATION_H
    #define DURATION_H
    class Duration
    {
        private:
            int hours, mins, secs;
        public:
            Duration (int h = 0, int m = 0, int s = 0);
            void setHours(int h);
            int getHours();
            void setMins(int m);
            int getMins();
            void setSeconds(int s);
            int getSeconds();
            Duration checkDuration();
            Duration randomize();
            Duration operator + (Duration other);
            Duration operator - (Duration other);
            Duration operator * (int a);
            Duration operator / (int a);
            double operator / (Duration other);
            operator const char*();
    };
            Duration::Duration(int h, int m, int s)
            {
                hours = h;
                mins = m;
                secs = s;
            }
            void Duration :: setHours(int h)
            {
                hours = h;//setting input to hours 
            }
            int Duration :: getHours()//returning the current hour
            {
                return hours;
            }
            void Duration :: setMins(int m)//setting input to mins
            {
                mins = m;
            }
            int Duration :: getMins()//returning current minutes
            {
                return mins;
            }
            void Duration :: setSeconds(int s)//setting input to secs
            {
                secs = s;
            }
            int Duration :: getSeconds()//returns current seconds
            {
                return secs;
            }
            Duration Duration :: checkDuration()//making sure that the duration is a possible time value 
            {
                int temp, temp2, tempM, tempM2;
                if(getSeconds() > 59)//does not allow for seconds over 60 seconds
                {
                    temp = getSeconds()/60;//finding out how many minutes based off the number of seconds 
                    temp2 = getSeconds()%60;//finding out how many seconds there should be 
                    setMins(getMins() + temp);//increasing the minutes by the previously found amount
                    setSeconds(temp2);//setting the seconds to the correct value
                }
                if(getMins() > 59)//does not allow for minutes over 60
                {
                    tempM = getMins()/60;//finding out how many hours there are based off the current number of minutes
                    tempM2 = getMins()%60;//finding out how many minutes are left over
                    setHours(getHours() + tempM);//adding the current hours to the new calculated amount
                    setMins(tempM2);//setting the minutes to their correct amount
                }
                if(getHours() >24)//does not allow for hours over 24
                {
                    setHours(getHours()%24);//making sure the value for hours is less than 24
                }
                if(getSeconds() < 0)//does not allow for negative values in seconds 
                {
                    setMins(getMins()-1);//converting one minutes into 60 seconds
                    setSeconds(getSeconds() +60);
                }
                if(getMins() < 0)//does not allow for negative values in minutes 
                {
                    setMins(getMins() + 60);//converting an hour into 60 minutes
                    setHours(getHours() - 1);
                }
                if(getHours()<0)//if there is a negative amount of hours, the duration should be set to 00:00:00
                {
                    setMins(0);
                    setHours(0);
                    setSeconds(0);
                }
                return *this;
            }
            Duration Duration :: operator + (Duration other)//adding two durations
            {
                return Duration (getHours()+other.getHours(), getMins()+other.getMins(),getSeconds()+other.getSeconds());
            } 
            Duration Duration :: operator - (Duration other)//subtracting two durations
            {
                return Duration (getHours()-other.getHours(), getMins() - other.getMins(), getSeconds()-other.getSeconds());
            }
            Duration Duration :: operator * (int a)//multiplying duration by a constant
            {
                return Duration (a*getHours(), a*getMins(), a*getSeconds());
            }
            Duration Duration :: operator / (int a)//dividing duration by a constant
            {
                return Duration (getHours()/a, getMins()/a, getSeconds()/a);
            }
            double Duration :: operator / (Duration other)//dividing a duration by another duration
            {
                return (double)(getHours()*3600 +getMins() *60 +getSeconds())/(double)(other.getHours()*3600 + other.getMins() *60 + other.getSeconds());
            }
            Duration Duration :: randomize()//generating a random duration
            {
                setHours(rand()%24 +1);
                setMins(rand()%60);
                setSeconds(rand()%60);
                return *this;//generating a random number between 1-24 for the hours and a random number 0-59 for both seconds and minutes
            }
            Duration :: operator const char* ()//printing the duration in proper form 
            {
                ostringstream output;
                string fOutput = "";
                checkDuration();
                if(getHours() < 10)//printing a 0 before all values such that the output is HH:MM:SS
                {
                    output << "0";
                    fOutput = output.str();
                }
                output << getHours();//adding the hours value to the string
                 fOutput = output.str();
                output << ":";//adding a colon
                 fOutput = output.str();
                if(getMins() < 10)
                {
                    output << "0";
                     fOutput = output.str();
                }
                output << getMins();//adding the minutes value to the string
                 fOutput = output.str();
                output << ":";
                 fOutput = output.str();
                if(getSeconds() < 10)
                {
                    output << "0";
                     fOutput = output.str();
                }
                output << getSeconds();//adding the seconds value to the string
                 fOutput = output.str();
                return fOutput.c_str();//returning the string 
            }
    #endif