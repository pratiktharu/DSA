//stack push and pop operation

#include<iostream>
using namespace std;
#define MAX_SIZE 50

template<class T>
class stack{

    private:
        T Stack[MAX_SIZE];
        int top;
    public:
        stack(){
            top==-1;

        }
        T push(T number);
        T pop();
        T displayStackElement();

        //checks if the stack is full

        bool checkFull(){
            if(top==MAX_SIZE-1)
            {
                cout<<"Stack is full";
                return 1;

            }

        }

        //checks if the stack is empty

        bool checkEmpty(){
            if(top==-1)
            {
                cout<<"stack is empty";
                return 1;

            }
        }
};


template<class T>
T stack<T>::push(T number){
    checkFull();
    ++top;
    Stack[top]=number;
    return 0;
}

template<class T>
T stack<T>::pop(){
    checkEmpty();
    return Stack[top--];

}

template<class T>
T stack<T>::displayStackElement(){
    for(int i= 0; i<=top; i++){
        cout<<Stack[i]<<endl;
    }
}


int main(){

    stack<int> items;
    items.push(10);
    items.push(20);
    items.push(50);
    items.push(60);
    items.push(70);
    items.push(80);
    items.pop();
    items.displayStackElement();
    return 0;

}