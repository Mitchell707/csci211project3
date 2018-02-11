#ifndef _VIDEO_H_
#define _VIDEO_H_

#include <iostream>
#include <string>

using namespace std;

class Video
{
    private:
        string title;
        string url;
        string description;
        float length;
        int rating;

    public:
        
        Video(string, string, string, float, int);
 
        void print();
        
        bool longer(Video*);
        bool ratings(Video*);
        bool titles(Video*);

};

#endif
