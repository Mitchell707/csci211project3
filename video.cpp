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

/*
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
*/

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

//===============================================================================================
/*
List::List()
{
    m_head = NULL;
    m_length = 0;
}

List::~List()
{
    while (m_head)
    {
        Node *tmp = m_head;
        m_head = m_head->m_next;
        delete tmp;
    }   
}

void List::insert(Video* video)
{
    if(!m_head)
    {
        m_head = new Node(video, m_head);
    }
    else
    {
        Node *ptr = m_head;
        while(ptr->m_next != NULL)
        {
            ptr = ptr->m_next;
        }
        ptr->m_next = new Node(video, ptr->m_next);
    }
    m_length++;
}

void List::printList()
{
    for(Node *ptr = m_head; ptr; ptr = ptr->m_next)
    {
        cout << ptr->m_value->title << endl;

    }
}
*/
