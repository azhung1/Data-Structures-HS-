/*
TimeTracker.cpp
Adding and subtracting various time objects
Albert Hung
*/
#include <iostream>//importing the necessary preprocessor directives
using namespace std;//choosing a namespace so I don't have to type out std 
int input = 0;//Initializing variables
bool secOnly = true;
bool rerun = true;
int holder = 0;
int inputH, inputM, inputS, inputH2, inputM2, inputS2;
class Time
{
    private://making the hours, min, and sec private 
    int hours, min, sec;
    public:
       Time(int s)//constructer for seconds only
        {
            sec = s;
            hours = 0;
            min = 0;
        }
        Time (int hr, int mn, int sc)//constructer for hours, mins, and secs
        {
            hours = hr;
            min = mn;
            sec = sc;
        }
        int getHours()//accessor 
        {
            return hours;
        }
        int getMins()
        {
            return min;
        }
        int getSec()
        {
            return sec;
        }
        void setHour(int hr)//mutator
        {
            hours = hr % 24;//setting hours to a value less than 24
        }
        void setMin(int mn)
        {
            if(min > 60)//if there value for mins is greater than 60 
            {
                holder = mn/60;//finding out how many hours represented in the current min of the time object
                setHour(hours + holder);//increasing the hours if min greater than 60
                min = mn % 60;//keeping the remainder as the current min for the time object 
            }
            else if(mn < 0)//if there is a negative value for min
            {
                setHour(getHours() -1);//removing one hour from the hour value of the time object 
                setMin(60 + mn);//increasing the min value by 60 
            }
            else
            {
                min = mn;//setting the arugment equal to the min value for the time object 
            }
        }
        void setSec(int sc)
        {
            if(sec > 60)// if the value for seconds is greater than 60 
            {
            holder = sc/60;//find out how many minutes there are when the seconds value is greater than 60 
            setMin(min + holder);//incrementing the min value
            sec = sc % 60;//keeping the remainder equal to the seconds value for the time object 
            }
            else if(sc < 0)//if there is a negative value for seconds 
            {
                setMin(getMins() -1 );//taking one min away from the min value of the Time object 
                setSec(60 + sc);//increasing the seconds by 60 
            }
            else
            {
                sec = sc;//settign the argument equal to the seconds value for the time object 
            }
        }
        Time add(Time other)//adding two times together
        {
            hours += other.getHours();//adding the 2 values of the inputted hours together 
            min += other.getMins();//adding the 2 values of the inputted mins together
            sec += other.getSec();//adding the 2 values of the inputted seconds together 
            Time output (hours, min, sec);//creating a new Time object with the new time
            output.setSec(output.getSec());//making sure that the values(hours, min, and sec) are all correct i.e. not greater than 24, 60 and 60 respectively
            output.setMin(output.getMins());
            output.setHour(output.getHours());
            holder = 0;
            return output;//returning the created time object
        }
        Time subtract(Time other)
        {
            hours -= other.getHours();//subtracting the 2 values of the inputted hours 
            min -= other.getMins();//subtracting the 2 values of the inputted min 
            sec -= other.getSec();//subtracting the 2 value of th inputted sec 
            Time output (hours, min, sec);//creating a new result ime object 
            output.setMin(output.getMins());//calling the set method to make sure that min and sec are not in seconds 
            output.setSec(output.getSec());
            output.setHour(output.getHours());//calling the set method to make sure that only the hours are negative 
            return output;//returning the final time object 
        }
        Time increaseBy(int h, int m, int s)//increasing the current time object by hours, mins, and secs and returning a new time object
        {
            hours += h;//adding the inputted value for hours to the current hours of the current time object
            min += m;//adding the inputted value for minutes to the current minutes of the current time object
            sec += s;//adding the inputted value for seconds to the current seconds of the current time object
            setSec(sec);//checking to make sure the value in seconds is valid 
            setMin(min);//checking to make sure the value in mins in valid
            setHour(hours);//checking to make sure the value in hours is valid 
            Time output (getHours(), getMins(),  getSec());//creating a new time object with the same final values 
            holder = 0;
            return output;//returning the created time object 
        }
        Time increaseBy(int s)//increasing the current time object by secs and returning a new time object 
        {
            sec += s;//increasing the seconds of the current time object by the inputted value 
            setSec(sec);//checking to make sure the value in seconds is valid 
            setMin(min);
            setHour(hours);
            Time output (getHours(), getMins(),  getSec());//creating a new time object with the same values as the final vlaues 
            holder = 0;
            return output;//returning the created time object 
        }
        ~Time()//destructor 
        {
        }
};
int main()
{
    while(rerun)
    {
        Time *a, *b, *finalOutput;//initializing pointer to time objects
        cout << "1. Add time \n2. Subtract time \n3. Increase time(hours, min, sec) \n4. Increase time(sec)" << endl;//printing a menu and allowing the user to select an option 
        cin >> input;
        cout<< "Would you like to input the times in hours, minutes, seconds(0) or just seconds(1)? " << endl;//prompting a menu which allows the user to choose whether 
        //to create the time object in just seconds or in hours, mins, and sec
        cin >> secOnly;
        if(input == 1 || input == 2)//for the time add and time subtract functions, the inputs for 2 time objects need to be inputted 
        {
            if(secOnly)//takes values that initialize the time object with only seconds 
            {
                cout << "Enter the first time in seconds: " << endl;
                cin >> inputS;
                a = new Time (inputS);//initializes a new time object with the user inputs
                cout << "Enter the other time in seconds: " << endl;
                cin >> inputS2;
                b = new Time (inputS2);//initializes a new time object with the user inputs 
                finalOutput = new Time (0);//initializes the final output time 
            }
            else//takes values that initializes the time objects with hours, mins and seconds 
            {
                cout << "Enter the hours for the first time: " << endl;
                cin >> inputH;
                cout << "Enter the minutes for the first time: " << endl;
                cin >> inputM;
                cout << "Enter the seconds for the first time: " << endl;
                cin >> inputS;
                a = new Time (inputH, inputM, inputS);//initializes a new time obeject with the user inputs
                cout << "Enter the hour for the second time: " << endl;
                cin >> inputH2;
                cout << "Enter the minutes for the second time: " << endl;
                cin >> inputM2;
                cout << "Enter the seconds for the second time: " << endl;
                cin >> inputS2;
                b = new Time (inputH2, inputM2, inputS2);//initializes a new time object with the user inputs 
                finalOutput = new Time (0,0,0);//initializes the final output time 
            }
        }
        else//the increase by functions only require 1 time input 
        {
            if(secOnly)//takes values that initialize the time object with only seconds 
            {
                cout << "Enter the first time in seconds: " << endl;
                cin >> inputS;
                a = new Time (inputS);//initializing a new time object for the user inputs 
                finalOutput = new Time (0);//initialzies a new time object for the final output 
            }
            else//takes values that initializes the time object with hours, mins and seconds 
            {
                cout << "Enter the hours for the first time: " << endl;
                cin >> inputH;
                cout << "Enter the minutes for the first time: " << endl;
                cin >> inputM;
                cout << "Enter the seconds for the first time: " << endl;
                cin >> inputS;
                a = new Time (inputH, inputM, inputS);//initializes a new time onject for the user inputs 
                finalOutput = new Time (0,0,0);//initializes a new time objet for the final output
            }
            if(input == 3)//menu option 3 requires the input of hours, mins and sec
            {
                cout << "Enter the number of hours you want to increase the time by: " << endl;
                cin >> inputH2;
                cout << "Enter the number of minutes you want to increase the time by: " << endl;
                cin >> inputM2;
                cout << "Enter the number of seconds you want to increase the time by: " << endl;
                cin >> inputS2;
            }
            else if(input == 4)//menu option 4 only requires input of seconds 
            {
                cout << "Enter the number of seconds you want to increase the time by: " << endl;
                cin >> inputS2;
            }
        }
        if(input == 1)//calling the corresponding function that the user inputted from the first menu 
        {
            *finalOutput = b->add(*a);
        }
        else if(input == 2)//calling the corresponding function that the user inputted from the first menu 
        {
            *finalOutput = a->subtract(*b); 
        }
        else if(input == 3)//calling the corresponding function that the user inputted from the first menu 
        {
            *finalOutput = a->increaseBy(inputH2, inputM2, inputS2);
        }
        else//calling the corresponding function that the user inputted from the first menu 
        {
            *finalOutput = a->increaseBy(inputS2);
        }
        cout << "The final time is " << finalOutput->getHours() << " : " << finalOutput->getMins() <<  " : " << finalOutput->getSec() << endl;//printing the final output 
        cout << "Would you like to rerun the program (Enter 1 for yes and 0 for no)?" << endl;//prompts the user if he or she would like to rerun the program 
        cin >> rerun;
        delete a, b, finalOutput;//deleting the pointers 
    }
}