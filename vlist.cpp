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
        delete tmp->m_value;
        delete tmp;
    }   
}

/*
int List::length()
{
    return m_length;
}
*/

bool List::remove(string name)
{
    if(m_head == NULL)
    {
        return false;
    }
    else if(name == m_head->m_value->gettitle())
    {
        Node *ptr = m_head;
        m_head = m_head->m_next;
        delete ptr->m_value;            //deletes the value at the list position before deleting the pointer
        delete ptr;
        m_length--;                     //adjusts the length accordingly for reference
    }
    else
    {   
        Node *ptr = m_head;
        while(ptr->m_next != NULL)
        {
            if(ptr->m_next->m_value->gettitle() == name)
            {
                Node * tmp = ptr->m_next;
                ptr->m_next = ptr->m_next->m_next;
                delete tmp->m_value;
                delete tmp;
                m_length--;
                return true;
            }

            ptr = ptr->m_next;

        }

        return false;
    }

    
}

void List::insert(Video* video)
{
    if(!(freeName(video->gettitle())))
    {
        return;
    }
    else if(m_head==NULL || video->gettitle() < m_head->m_value->gettitle())
    {
        m_head = new Node(video, m_head);
        m_length++;
    }
    else
    {
        Node *ptr = m_head;
        while(ptr->m_next != NULL && video->gettitle() > ptr->m_next->m_value->gettitle())
        {
            ptr = ptr->m_next;
        }
        ptr->m_next = new Node(video, ptr->m_next);
        m_length++;
    }
}


void List::print()
{
    Node *ptr = m_head;

    while(ptr != NULL)
    {
        ptr->m_value->print(); 
        ptr = ptr->m_next;
    }    
}

void List::search(string name)
{
    Node *ptr = m_head;

    while(ptr != NULL)
    {
        if(ptr->m_value->gettitle() == name)
        {
           ptr->m_value->print();
           return;
        }
        ptr = ptr->m_next;
    }

    cerr << "Title <" << name << "> not in list." << endl;
    
}

bool List::freeName(string name)
{
    Node *cur = m_head;
    
    while(cur != NULL)
    {
        if(cur->m_value->gettitle() == name)
        {
    
            return false;
            
        }
        else
        {
            cur = cur->m_next;
        }
    }
    
    return true;
}
