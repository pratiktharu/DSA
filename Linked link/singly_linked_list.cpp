#include <iostream>

template <class T>
struct node
{
    T data;
    node *next;
};

template <class T>
class LinkedList
{
private:
    node<T> *start;

public:
    LinkedList() { start = NULL; }
    void insAtStart(T item)
    {
        node<T> *temp = new node<T>();
        temp->data = item;
        temp->next = start;
        start = temp;
    }
    void delAtStart()
    {
        if (!start)
        {
            std::cout << "List is empty" << std::endl;
            return;
        }
        node<T> *temp = start;
        start = start->next;
        delete temp;
    }
    void insAtEnd(T item)
    {
        node<T> *ptr = start;
        node<T> *temp = new node<T>();
        temp->data = item;
        temp->next = NULL;
        if (!ptr)
        {
            start = temp;
            return;
        }
        while (ptr->next)
            ptr = ptr->next;
        ptr->next = temp;
    }
    void delAtEnd()
    {
        if (!start)
        {
            std::cout << "List is empty" << std::endl;
            return;
        }
        if (!start->next)
        {
            delete start;
            start = NULL;
            return;
        }
        node<T> *ptr = start;
        while (ptr->next->next)
            ptr = ptr->next;
        delete ptr->next;
        ptr->next = NULL;
    }
    void insertAfter(T item, T after)
    {
        node<T> *ptr = start;
        while (ptr && ptr->data != after)
            ptr = ptr->next;
        if (!ptr)
        {
            std::cout << "No such element" << std::endl;
            return;
        }
        node<T> *temp = new node<T>();
        temp->data = item;
        temp->next = ptr->next;
        ptr->next = temp;
    }
    void deleteAfter(T after)
    {
        node<T> *ptr = start;
        while (ptr && ptr->data != after)
            ptr = ptr->next;
        if (!ptr || !ptr->next)
        {
            std::cout << "No such element or element is last" << std::endl;
        }
        node<T> *temp = ptr->next;
        ptr->next = ptr->next->next;
        delete temp;
    }
    void insertBefore(T item, T before)
    {
        node<T> *ptr = start, *preptr = NULL;
        while (ptr && ptr->data != before)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        if (!ptr)
        {
            std::cout << "No such element";
            return;
        }
        node<T> *temp = new node<T>();
        temp->data = item;
        temp->next = ptr;
        if(preptr)
            preptr->next = temp;
        else
            start = temp;
    }
    void print()
    {
        node<T> *ptr = start;
        while(ptr)
        {
            std::cout << ptr->data << " ";
            ptr = ptr->next;

        }
        std::cout << std::endl;

    }
};

int main()
{
    LinkedList<int> list;
    list.insAtStart(1);
    list.insAtStart(0);
    list.insAtEnd(4);
    list.insertAfter(3, 1);
    list.insertBefore(2, 3);
    list.print();
    list.delAtStart();
    list.delAtEnd();
    list.deleteAfter(0);
    list.print();
    return 0;
}