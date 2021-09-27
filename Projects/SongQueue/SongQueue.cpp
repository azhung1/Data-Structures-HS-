// Albert Hung
//SongQueue
// Keeping track of and allowing the user to create and manipulate his or her song queue
#include <iostream>//importing the necessary libraries
#include <queue>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
class SongQueue
{
private:
   queue<string> songs;//queue of songs

public:
   /* reads the file "songs.txt".  Extracts the song's title
      and stores it in a queue.
      */
   SongQueue *readPlayList()
   {
      string title = "";
      string line;
      ifstream inputFile("songs.txt");//reading each line in the text file 
      while (getline(inputFile, line))
      {
         for (int i = 0; i < line.length(); i++)
         {
            if (line.at(i) != '-')//obtaining the name of the song 
            {
               title += line.at(i);
            }
            else
            {
               break;
            }
         }
         title = title.substr(0, title.length() - 1);//removing the space at the end of the string
         songs.push(title);//adding the name to the queue 
         title = "";
      }
      return this;
   }

   /* processes the character codes A, P, D, Q, a, p, d, q.
      "A" prompts the user to enter the name of the song, 
      adds it to the queue, and displays the whole queue
      after "Your music queue:  " . Do not add the same song twice.

      "P" plays the song, if one exists, by displaying 
      "Now playing: " and its title and then removing it from the queue.
      If there is nothing play, the program displays "Empty queue!"

      "D" displays the queue, prompts the user by showing 
      "Delete which song (exact match)?" and will either delete the 
      song and display the queue or show "Error:  Song not in list."   

      "Q" displays "No more music for you today.  Goodbye!" 
      and ends the program.

      */

   void processRequest(string str)
   {
      string input = "";
      if (str == "Q" || str == "q")
      {
         cout << "No more music for you today. Goodbye!" << endl;
      }
      else
      {
         if (str == "A" || str == "a")
         {
            cout << "Please enter the name of the song you would like to add: " << endl;//prompting the user
            cin >> input;//reading the input 
            songs.push(input);//adding the new song to the queue 
            cout << "Your music queue: ";//printing the current queue 
            printSongList();
         }
         else if (str == "P" || str == "p")
         {
            if (!songs.empty())
            {
               cout << "Now playing: " << songs.front() << endl;
               songs.pop();//removing the current song from the queue
            }
            else
            {
               cout << "Empty queue!" << endl;
            }
            cout << "Your music queue: ";//printing the current queue 
            printSongList();
         }
         else if (str == "D" || str == "d")
         {
            cout << "Delete which song (exact match)?" << endl;//prompting the user
            cin >> input;//reading the input 
            queue<string> temp = songs;//copying the current queue 
            int pos = 0;
            string curSong = temp.front();
            while (curSong != input && !temp.empty())//searching through the queue for the song that the user desires to be deleted. Will stop when the name is found or if there are no songs left 
            {
               pos++;
               temp.pop();
               curSong = temp.front();
            }
            if (curSong == input)//if the names are matching 
            {
               temp = songs;
               int counter = 0;
               while(!songs.empty())//removing all of the current songs in the queue 
               {
                  songs.pop();
               }
               while (!temp.empty())
               {
                  if (counter == pos)//skipping the song that the user wishes to delete
                  {
                     temp.pop();
                  }
                  else//copying the rest of the song queue 
                  {
                     songs.push(temp.front());
                     cout << temp.front() << endl;
                     temp.pop();
                  }
                  counter++;
               }
            }
            else//if the song is not in the queue 
            {
               cout << "Error: Song not in list." << endl;
            }
            cout << "Your music queue: ";//printing the current queue 
            printSongList();
         }
         else//if the user enters an invalid option 
         {
            cout << "Invalid. Try Again." << endl;
         }
      }
   }
   /* prints the songs in the queue, separated by commas.
      */
   void printSongList()
   {
      queue<string> temp = songs;
      string result = "";
      while (!temp.empty())//printing the current queue
      {
         result += temp.front() + ", ";
         temp.pop();
      }
      cout << result.substr(0, result.length() - 2) << endl;//removing the comma from the last song in the queue 
   }

   /*  standard accessor method.
      */
   SongQueue *getQueue()
   {
      return this;
   }
};
int main()
{
   SongQueue *a = new SongQueue();//creating a new instance of Songqueue
   a->readPlayList();//creading the text file
   a->printSongList();//printing the current queue
   string prompt = "Add song (A), Play song (P), Delete song (D), Quit (Q):  ";
   string str = "";
   do
   {
      cout << prompt << endl;//prompt the user
      cin >> str;//get the choice
      a->processRequest(str);//process it
   } while (str != "Q" && str != "q"); //repeat until quit
}
