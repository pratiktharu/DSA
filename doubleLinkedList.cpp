#include <iostream>
using namespace std;

template <class T>
class node{
public:
    node(){
        this->data = 0;
        this->prev=nullptr;
        this->next=nullptr;
    }
    node(T data){
        this->data = data;
        this->prev=nullptr;
        this->next= nullptr;
    }
    node(T data,node* p,node* n){
        this->data= data;
        this->prev = p;
        this->next = n;
    }
    T data;
    node* next;
    node* prev;
};

template <class T>
class doubleLinkedList{
public:
    node<T>* start;
    node<T>* end;
    doubleLinkedList(T data){
        start = new node<T>(data);
        end=start;
    }
    void insertAtBegining(T data){
        node<T>* temp =  new node<T>(data);
        temp->next = start;       
        start->prev= temp;
        start = temp;
    }
    void insertAtEnd(T data){
        node<T>* temp = new node<T>(data);
        temp->prev = end;
        end->next= temp;
        end = temp;
    }
    void insertAtAGivenPosition(T data,T d){
        node<T>* temp = new node<T>(d);
        node<T>* begin = start;
        while(begin->data != data){
            begin=  begin->next;
        }
        if(begin == nullptr){
            cout<<"The given data does not exists"<<endl;
            return ;
        }else{
            temp->prev = begin;
            temp->next = begin->next;
            begin->next = temp;
        }
    }
    void insertAtAIndex(int n,T d){
        node<T>* begin = start;
        for(int i=0;i<n;i++){
            if(begin == nullptr){
                cout<<"There is no data at the index"<<endl;
            }
            begin = begin->next;
        }
        node<T>* temp = new node<T>(d);
        temp->prev= begin;
        temp->next=begin->next;
        begin->next = temp;
    }
    void removeAtBegin(){
        node<T>* s = start->next;
        free(start);
        start = s;
        s->prev = nullptr;
    }
    void remvoveAtEnd(){
        node<T>* s =  end->prev;
        cout<<"Data is"<<end->prev->data<<endl;
        free(end);
        end = s;
        end->next = nullptr;
    }
    void removeAtPosition(int n){
        node<T>* s = start;
        for(int i=0;i<n;i++){
            s=s->next;
            if(s==nullptr){
                cout<<"NO element in the given index"<<endl;
            }
        }
        s->next->prev = s->prev;
        s->prev->next = s->next;
        free(s);
    }
    void removeAtAGivenPosition(T d){
        node<T>* s = start;
        while(s->data != d){
            s = s->next;
        }
        s->next->prev = s->prev;
        s->prev->next = s->next;
        free(s);
    }
    void printAll(){
        node<T>* begin = start;
        if(begin == nullptr){
            cout<<"The given double linked list is empty"<<endl;
        }
        while (begin != nullptr)
        {
            cout<<begin->data<<endl;
            begin = begin->next;
        }
    }
};

int main(){
    doubleLinkedList<int>* l  = new doubleLinkedList<int>(0);
    l->insertAtEnd(5);
    l->insertAtEnd(10);
    l->insertAtBegining(19);
    cout<<"After insertion"<<endl;
    l->printAll();
    l->removeAtPosition(2);
    l->removeAtAGivenPosition(0);
    cout<<"Insertion at a point"<<endl;
    l->printAll()
    l->insertAtAGivenPosition(19,20);
    l->removeAtBegin();
    cout<<"End result"<<endl;
    l->printAll();
    return 0;
}