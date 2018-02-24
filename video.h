#ifndef _VIDEO_H_
#define _VIDEO_H_

#include <iostream>
#include <string>

using namespace std;

class Video
{
    public:
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
/*
class List
{
    public:
        List();
        ~List();

        void insert(Video* video);
        void printList();
        int length() {return m_length;}
        
    private:
        class Node
        {
            public:
                Node(Video* video, Node *next)
                {m_value = video; m_next = next;}
                Video* m_value;
                Node *m_next;
        };

        Node *m_head;
        int m_length;
};
*/
#endif
