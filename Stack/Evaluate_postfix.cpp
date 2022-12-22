//program to evaluate the Postfix Expression.

#include<iostream>
#include<string.h>
#include<stack>
using namespace std;

int evaluate(string expression){
    stack<char> s;
    int a,b;
    for(int i=0; i<expression.size(); i++){

        if(isdigit(expression[i])){
            s.push(expression[i]);
        }
        else if(expression[i]=='+'){
            a=s.top();
            cout<<s.top()<<endl;
            s.pop();
            int b=s.top();
            s.pop();
            s.push(a+b);
            cout<<a+b;
        }
        else{
            cout<<"hello world";
        }
    }
}

int main(){

    evaluate("12+234");
    return  0;

}