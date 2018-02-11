#include <iostream>
#include <string>
#include "video.h"

using namespace std;

string sort =        "";

string title =       "";
string url =         "";
string description = "";

float length = 0.00;
int rating = 0;
int counter = 0;
int const MAX = 100;

/*
    Convert rating into *****
    Convert length into a double
    Make sorting methods -> title, length, rating
    
    Make the error messages written in the rubric

*/

int main()
{
    //cout << "Sorting Method" << endl;
    cin >> sort;
    
    if(sort != "length" && sort != "rating" && sort != "title")
    {
        cout << sort << " is not a legal sorting method, giving up." << endl;
        return 1;
    }

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

        if(counter > 100)
        {
            cout << "Too many videos, giving up." << endl;
            return 1;
        }
    }
    
    if(sort == "length")
    {
        for(int last = counter - 1; last > 0; last --)
        {
            for(int cur = 0; cur < last; cur++)
            {
                if(vid[cur]->longer(vid[cur + 1]))
                {
                    swap(vid[cur], vid[cur + 1]);

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
    else
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
