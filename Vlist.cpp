#include <iostream>
#include <string>
#include "video.h"

using namespace std;

Video::Video(string t, string u, string d, float l, int r)
{
    bool temp = false;

    title = t;
    url = u;
    description = d;
    length = l;
    rating = r;

}

void Video::print()
{
    int temp = rating;
    
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
