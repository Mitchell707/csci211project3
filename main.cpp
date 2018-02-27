#include <iostream>
#include <string>
#include "video.h"
#include "vlist.h"

using namespace std;

//initializing the variables for turn-in

string command =     "";
string title =       "";
string url =         "";
string description = "";

float length = 0.00;
int rating = 0;
int counter = 0;
int const MAX = 100;

void insertVid();

List vid;

int main()
{

    while(getline(cin, command)) //Goes until input has ended
    {
       // cin >> command;
        
        if(command == "insert")
        {
            insertVid();
            
        }
        else if(command == "print")
        {
            vid.print();

        }
        else if(command == "length")
        {
            cout << vid.length() << endl; 

        }
        else if(command == "lookup")
        {
            getline(cin, title);
            vid.search(title);

        }
        else if(command == "remove")
        {
            getline(cin, title);
            if(!vid.remove(title))
            {
                cerr << "<" << title << "< not in list, could not delete." << endl;
            }
        }
        else
        {
            cerr<< "<" << command << "> is not a legal command, giving up." << endl;
            return 1;
        }

    }

    return 0;
}


void insertVid()//(List vid)
{
    title       = "";
    url         = "";
    description = "";
    length      = 0.00;
    rating      = 0;
    
    //cin.ignore();

    getline(cin, title);
        
    getline(cin, url);

    getline(cin, description);

    cin >> length;

    cin >> rating;
      
    cin.ignore();

    if(vid.freeName(title))
    {
        vid.insert(new Video(title, url, description, length, rating));
    
    }
    
}

    /*
    if(sort == "length")
    {
        for(int last = counter - 1; last > 0; last --) //counts backwards from the last item in the array
        {
            for(int cur = 0; cur < last; cur++) 
            {
                if(vid[cur]->longer(vid[cur + 1])) //uses a pointer function to compare the size of two floats
                {
                    swap(vid[cur], vid[cur + 1]); //uses a standard algorithm to swap two values

                }
            }
        }
    }
    else if(sort == "rating")
    {
        for(int last = counter - 1; last > 0; last --)
        {
             for(int cur = 0; cur < last; cur++)
             {
                 if(vid[cur]->ratings(vid[cur + 1]))
                 {
                    swap(vid[cur], vid[cur + 1]);
                 }
             }
         }
    }
    else //makes the default sorting by title.
    {
        for(int last = counter - 1; last > 0; last--)
        {
            for(int cur = 0; cur < last; cur++)
            {
                if(vid[cur]->titles(vid[cur + 1]))
                {
                    swap(vid[cur], vid[cur + 1]);
                }
            }
        }
    }


    for(int i = 0; i < counter; i++)
    {
        vid[i]->print();

    }
    */
    
    //vid.printList();
