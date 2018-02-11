#include <iostream>
#include <string>
#include "video.h"

using namespace std;

//initializing the variables for turn-in

string sort =        "";
string title =       "";
string url =         "";
string description = "";

float length = 0.00;
int rating = 0;
int counter = 0;
int const MAX = 100;

int main()
{

    cin >> sort;
    
    if(sort != "length" && sort != "rating" && sort != "title" && sort != "Length" && sort != "Rating" && sort != "Title" sort != "LENGTH" && sort != "RATING" && sort != "TITLE") //makes sure sort input is acceptable
    {
        cerr << sort << " is not a legal sorting method, giving up." << endl;
        return 1;
    }

    cin.ignore();

    Video *vid[MAX]; //sets array to 100
    
    while(cin.peek() != -1) //Goes until input has ended
    {

        getline(cin, title);
        
        getline(cin, url);

        getline(cin, description);

        cin >> length;

        cin >> rating;
        
        vid[counter] = new Video(title, url, description, length, rating);

        cin.ignore();

        counter++;

        if(counter > 100)
        {
            cerr << "Too many videos, giving up." << endl;
            return 1;
        }
    }
    
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
    
    return 0;

}
