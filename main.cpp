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
                cerr << "Title <" << title << "> not in list, could not delete." << endl;
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


void insertVid()
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
