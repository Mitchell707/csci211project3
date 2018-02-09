#include <iostream>
#include <string>
#include "video.h"

using namespace std;


Video::Video(string t, string u, string d, string l, string r)
{
    title = t;
    url = u;
    description = d;
    length = l;
    rating = r;

}


void Video::print()
{
    cout << title << ", " << url << ", " << description << ", " << length << ", " << rating << endl;

}
