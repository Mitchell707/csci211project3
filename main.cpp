#include <iostream>
#include <string>
#include "video.h"

using namespace std;

string sort =        "";

string title =       "";
string url =         "";
string description = "";
string length =      "";
string rating =      "";

int counter = 0;
int const MAX = 100;

//Video video;

int main()
{
    //cout << "Sorting Method" << endl;
    cin >> sort;
    
    cin.ignore();

    Video *vid[MAX];
    
    while(cin.peek() != -1)
    {
        //Video * video = new Video[10];

        getline(cin, title);
        
        getline(cin, url);

        getline(cin, description);

        cin >> length;

        cin >> rating;
        
        vid[counter] = new Video(title, url, description, length, rating);

        cin.ignore();

        counter++;
    }
    
    for(int i = 0; i < counter; i++)
    {
        vid[i]->print();

    }
}
