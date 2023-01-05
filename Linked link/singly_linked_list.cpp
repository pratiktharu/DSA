#include <iostream>
#define SIZE 100
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
        node<T> *temp = start;
        start = new node<T>();
        start->data = item;
        start->next = temp;
    }
    void delAtStart()
    {
        node<T> *temp = start;
        start = start->next;
        delete temp;
    }
    void insAtEnd(T item)
    {
        if (start->next == NULL)
        {
            start = new node<T>();
            start->data = item;
            start->next - NULL;
        }
        else
        {
            node<T> *preptr = start;
            while (preptr->next != NULL)
                preptr = preptr->next;
            node<T> *ptr;
            preptr->next = ptr;
            ptr->data = item;
            ptr->next = NULL;
        }
    }
    void delAtEnd()
    {
        if (start->next == NULL)
            delAtStart();
        else
        {
            node<T> *ptr, *preptr;
            ptr = start;
            while (ptr->next != NULL)
            {
                preptr = ptr;
                ptr = ptr->next;
            }
            preptr->next = NULL;
            delete ptr;
        }
    }
    void insertAfter(T item, T after)
    {
        if (!start)
        {
            std::cout << "List empty" << std::endl;
            return;
        }
        node<T> *ptr = start;
        while (ptr->data != after)
        {
            ptr = ptr->next;
            if (!ptr)
            {
                std::cout << "No such element" << std::endl;
                return;
            }
        }
        node<T> *temp = ptr->next;
        ptr->next = new node<T>();
        ptr->next->data = item;
        ptr->next->next = temp;
    }
    void deleteAfter(T after)
    {
        if (!start)
        {
            std::cout << "List empty" << std::endl;
            return;
        }
        node<T> *ptr = start;
        while (ptr->data != after)
        {
            ptr = ptr->next;
            if (!ptr)
            {
                std::cout << "No such element" << std::endl;
                return;
            }
        }
        node<T> *p;
        ptr->next = ptr->next->next;
        delete p;
    }
    void insertBefore(T item, T before)
    {
        if (!start)
        {
            std::cout << "List empty" << std::endl;
            return;
        }
        node<T> *ptr = start, *preptr = start;
        while (ptr->data != before)
        {
            preptr = ptr;
            ptr = ptr->next;
            if (!ptr)
            {
                std::cout << "No such element" << std::endl;
                return;
            }
        }
        node<T> *temp = new node<T>;
        temp->data = item;
        temp->next = ptr;
        preptr->next = temp;
    }
    void print()
    {
        node<T> *p = start;
        while (p != NULL)
        {
            std::cout << p->data;
            p = p->next;
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
    list.deleteAfter(2);
    list.print();
    return 0;
}