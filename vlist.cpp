#include <iostream>
#include <string>
#include "video.h"
#include "vlist.h"

using namespace std;

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
    if(!m_head/* || value < m_head->m_value*/)
    {
        m_head = new Node(video, m_head);
    }
    else
    {
        Node *ptr = m_head;
        while(ptr->m_next != NULL/* && value > ptr->m_next->m_value*/)
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
        cout << ptr->m_value->title << ", " << ptr->m_value->url <<  ", " << ptr->m_value->description <<  ", " << ptr->m_value->length <<  ", " << ptr->m_value->rating << endl;

    }
}

bool List::freeName(string name)
{
    Node *cur = m_head;
    
    while(cur != NULL)
    {
        if(cur->m_value->title == name)
        {
            return false;
            
        }
        else
        {
            cur = cur->m_next;
        }
    }
    //cout << "True" << endl;
    return true;
}
