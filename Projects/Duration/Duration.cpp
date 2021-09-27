    /*
    Duration
    Allowing the user to perform various operations of Duration
    Albert Hung
    */
    #include <iostream>//importing the necessary preprocessor directives
    #include <string>
    #include <cstring>
    #include<time.h>
    using namespace std;//choosing a namespace so I don't have to type out std 
    int inputMin, inputSec, inputHours, holder, inputOption, input, inputC, inputMin2, inputSec2, inputHours2 = 0;
    bool rerun = true;
    class Duration
    {
        private:
            int hours, mins, secs;
        public:
            Duration (int h, int m, int s)//constructor 
            {
                    hours = h;
                    mins = m;
                    secs = s;
            }
            void setHours(int h)
            {
                hours = h;//setting input to hours 
            }
            int getHours()//returning the current hour
            {
                return hours;
            }
            void setMins(int m)//setting input to mins
            {
                mins = m;
            }
            int getMins()//returning current minutes
            {
                return mins;
            }
            void setSeconds(int s)//setting input to secs
            {
                secs = s;
            }
            Duration checkDuration()//making sure that the duration is a possible time value 
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
            int getSeconds()//returns current seconds
            {
                return secs;
            }
            Duration operator + (Duration other)//adding two durations
            {
                return Duration (getHours()+other.getHours(), getMins()+other.getMins(),getSeconds()+other.getSeconds());
            } 
            Duration operator - (Duration other)//subtracting two durations
            {
                return Duration (getHours()-other.getHours(), getMins() - other.getMins(), getSeconds()-other.getSeconds());
            }
            Duration operator * (int a)//multiplying duration by a constant
            {
                return Duration (a*getHours(), a*getMins(), a*getSeconds());
            }
            Duration operator / (int a)//dividing duration by a constant
            {
                return Duration (getHours()/a, getMins()/a, getSeconds()/a);
            }
            double operator / (Duration other)//dividing a duration by another duration
            {
                return (double)(getHours()*3600 +getMins() *60 +getSeconds())/(double)(other.getHours()*3600 + other.getMins() *60 + other.getSeconds());
            }
            Duration randomize()//generating a random duration
            {
                srand(time(0));//using the current time as the seed
                return Duration (rand()%24+1, rand()%60, rand()%60);//generating a random number between 1-24 for the hours and a random number 0-59 for both seconds and minutes
            }
            operator string()//printing the duration in proper form 
            {
                string output;
                checkDuration();
                if(getHours() < 10)//printing a 0 before all values such that the output is HH:MM:SS
                {
                    output += "0";
                }
                output += to_string(getHours());//adding the hours value to the string
                output += ":";//adding a colon
                if(getMins() < 10)
                {
                    output += "0";
                }
                output += to_string(getMins());//adding the minutes value to the string
                output += ":";
                if(getSeconds() < 10)
                {
                    output += "0";
                }
                output += to_string(getSeconds());//adding the seconds value to the string
                return output;//returning the string 
            }
    };
    int main ()
    {
        while(rerun)
        {
        cout << "Please input a number corresponding to the number: \n1. Adding 2 durations \n2. Subtracting 2 durations \n3. Multiplying duration by a constant \n4. Division" 
        << " by a constant \n5. Dividing 2 durations \n6. Randomize "<< endl;//prompting the user for a menu to choose from 
        cin >> input;//reading user input
        Duration a (0,0,0);//creating a duration
        if(input == 6)//if the user wants to generate a random duration
        {
            cout << "The randomized duration is " << string(a.randomize()) << endl;//printing the random duration
        }
        else//prompting the user for input to set as the first duration
        {
        cout<<"Would you like to enter \n1. Hours Minutes Seconds \n2. Hours Minutes \n3. Hours: " << endl;//prompts user for the type of input her or she wants
        cin>>inputOption;
        cout << "Please enter a value for hours: " << endl;//you have to have an hour value for any duration inputted
        cin >> inputHours;
        if(inputOption == 2 || inputOption ==1)//depending on the choice of the user, he or she may be prompted for a minutes value 
        {
        cout << "Please enter a value for minutes: " << endl;
        cin >> inputMin;
        }
        if(inputOption == 1)//depending on the choice of the user, he or she may be prompted for a second value 
        {
        cout << "Please enter a value for seconds: " << endl;
        cin >> inputSec;
        }
        Duration one (inputHours, inputMin, inputSec);//creating a duration with the user inputted values
        if(input == 3 || input ==4)//if the user wants to multiply or divide by a constant
        {
            cout << "Please enter a constant: " << endl;//prompting the user for a constant
            cin >> inputC;//reading the inputted constant
            if(input == 3)//printing the result if the user wants multiply the inputted duration by a constant
            {
                cout << "Multiplying " << string(one) << " by " << inputC << " is " << string (one * inputC) << endl;
            }
            if(input == 4)//printing the result if the user wants to divide the inputted duration by a constant
            {
                cout << "Dividing " << string(one) << " by " << inputC << " is " << string (one/inputC) << endl; 
            }
        }
        if(input == 1 || input == 2 || input == 5)//if the user wanted to either add, subtract, or divide by another duration
        {
        cout << "Please enter a value for the second hours: " << endl;//prompts the user for another duration following the same format as previously selected
        cin >> inputHours2;
        if(inputOption == 2 || inputOption ==1)
        {
        cout << "Please enter a value for the second minutes: " << endl;
        cin >> inputMin2;
        }
        if(inputOption == 1)
        {
        cout << "Please enter a value for the second seconds: " << endl;
        cin >> inputSec2;
        }
        Duration two (inputHours2, inputMin2, inputSec2);//creating a new duration with the inputted values
        if(input == 1)//if the user chooses to add two durations
        {
            cout << "The sum of " << string(one) << " and " << string(two) << " is " << string(one+two) << endl;//printing the output
        }
        if(input == 2)//if the user chooses to subtract two durations
        {
            cout << "The difference of " << string(one) << " and " << string(two) << " is " << string(one-two) << endl;//printing the output
        }
        if(input == 5)//if the user chooses to divide two durations
        {
            cout << "Dividing " << string(one) << " by " << string(two) << " is " << one/two << ":1" << endl;//printing the output
        }
        }
        }
        cout << "Would you like to rerun the program? (Enter 1 for yes and 0 for no)?" << endl;//prompts the user if he or she would like to rerun the program 
        cin >> rerun;
        }
    }