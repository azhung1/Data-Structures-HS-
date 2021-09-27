/*
AssemblyLine.cpp
Albert Hung
*/
#include <iostream> //importing the necessary preprocessor directives
#include <queue>
#include <ctime>
#include <cstdlib>
#include <stack>
using namespace std; //choosing a namespace so I don't have to type out std

class Disk //disk class
{
private:
    int r;

public:
    Disk(int radius) //default constructor for the disk class with a given radius
    {
        r = radius;
    }
    int getRadius() //returning the radius of a disk object
    {
        return r;
    }
};

class Pyramid //pyramid class
{
private:
    stack<Disk> val;    //stack for a pyramid(after inversion)
    bool invert = true; //if the pyramid is inverted
    queue<Disk> vals;   //queue for a pyramid(before inversion)

public:
    Pyramid()
    {
    }
    Pyramid(queue<Disk> a)
    {
        vals = a;
    }
    void push(Disk a) //adding a disk to the pyramid
    {
        vals.push(a);
    }
    int firstVal() //getting the top of the pyramid
    {
        return vals.front().getRadius();
    }
    int back() //getting the base of the pyramid
    {
        return vals.back().getRadius();
    }
    void removeFirstVal() //removing the top of the pyramid
    {
        val.pop();
    }
    bool isEmpty() //if the stack is empty
    {
        return val.empty();
    }
    bool isInverted() //if the pyramid is inverted
    {
        return invert;
    }
    Pyramid invertPy() //inverting the pyramid
    {
        while (!vals.empty()) //transferring elements from the queue to the stack
        {
            val.push(vals.front());
            vals.pop();
        }
        invert = false;
        return *this;
    }
    void printPy() //printing the pyramid after it is inverted
    {
        cout << "[";
        stack<Disk> temp = val;
        while (temp.size() > 1)
        {
            cout << temp.top().getRadius() << ", ";
            temp.pop();
        }
        cout << temp.top().getRadius();
        cout << "]";
    }
};
class AssemblyLine //assembly line class
{
private:
    int diskNum = 0;
    int place = 0;
    queue<Disk> assemblyLineIn; //initializing the queues
    queue<Pyramid> assemblyLineOut;
    Pyramid *robotArm;

public:
    AssemblyLine()
    {
        cout << "How many disks would you like?" << endl; //prompting the user for the number of disks
        cin >> diskNum;
        srand(time(0));         //setting the seed
        while (place < diskNum) //generating a random number for the radii for each disk
        {
            assemblyLineIn.push(Disk(rand() %9 + 1));//generating a random number 1-10
            place++;
        }
        inputPrint();             //printing the values
        robotArm = new Pyramid(); //robot arm is initialized to an empty pyramid
    }
    void unloadRobot(Pyramid *a) //unloading the pyramid and adding it to the queue
    {
        assemblyLineOut.push(a->invertPy()); //inverting the pyramid
        while (!a->isEmpty())
        {
            a->removeFirstVal();
        }
    }
    void process() //processing the pyramid by taking the input queue and making the pyramids
    {
        robotArm->push(assemblyLineIn.front()); //adding the first disk to the pyramid
        assemblyLineIn.pop();
        while (!assemblyLineIn.empty())
        {
            if (!robotArm->isEmpty() || (assemblyLineIn.front().getRadius() < robotArm->back())) //if robot arm is not empty and the next disk cannot fit
            {
                unloadRobot(robotArm);
            }
            robotArm->push(assemblyLineIn.front()); //when all disks removed, unload robot arm
            assemblyLineIn.pop();
        }
        unloadRobot(robotArm);
    }
    void inputPrint() //printing the initial input
    {
        queue<Disk> temp = assemblyLineIn;
        cout << "[";
        while (temp.size() > 1)
        {
            cout << temp.front().getRadius() << ", ";
            temp.pop();
        }
        cout << temp.front().getRadius();
        cout << "]" << endl;
    }
    void outputPrint() //printing the output
    {
        queue<Pyramid> temp = assemblyLineOut;
        cout << "[";
        while (temp.size() > 1)
        {
            temp.front().printPy();
            temp.pop();
            cout << ",";
        }
        temp.front().printPy();
        temp.pop();
        cout << "]" << endl;
    }
};
int main()
{
    AssemblyLine *a = new AssemblyLine(); //creating a new instance
    a->process();                         //processing the assembly line
    a->outputPrint();                     //printing the assembly line
}