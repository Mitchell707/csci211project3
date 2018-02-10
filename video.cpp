#include <iostream>
#include <string>
#include "video.h"

#include <stdio.h>
#include <stdlib.h>

using namespace std;

const int ASCIIOFFSET = 48;

Video::Video(string t, string u, string d, string l, string r)
{
    bool temp = false;

    title = t;
    url = u;
    description = d;
    
    while(!temp)
    {
        if(l[l.size() - 1] == '0' || l[l.size() - 1] == '.')
        {
            l.resize(l.size() - 1);
            
        }
        else
        {
            temp = true;
        }
    }
    
    length = l;
    rating = r;

}


void Video::print()
{
    int temp = 0;
    
    temp = rating[0];
    
    temp -= ASCIIOFFSET;

    cout << title << ", " << url << ", " << description << ", " << length << ", ";
    
    for( int i = 0; i < temp; i++)
    {
        cout << "*";

    }
    
    cout << endl;

}

bool Video::longer(Video *other)
{
    return length > other->length;

}

bool Video::ratings(Video *other)
{
    return rating < other->rating;

}

bool Video::titles(Video *other)
{
    return title > other->title;

}
