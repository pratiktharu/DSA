#include<iostream>
#include<string.h>
#include<stack>
using namespace std;

int checkPrecedance(char op){
    if(op=='^')
        return=3;

    else if(op=='/' || op=='*')
        return 2;

    else if(op=='+' || op=='-')
     return 1;

    else 
        return -1;

}


void toPostFix(string exp){

    exp='('+ exp + ')';
    string postFix_exp;
    stack<char> s;
    for(int i=0; i<exp.size(); i++)
    {
        char c=exp[i];
    }
    if (c=='('){

        s.push('(');
    }

    else if((c>='a' && c<='z') || (c>='A' && c<='Z')){

        postFix_exp+=c;
    }

    else if(c==')'){
        while(s.top()!='('){
            postFix_exp+=s.top();
            s.pop();

        }
        s.pop();

    }
    else{

        while(!s.empty() && checkPrecendance(c)<=checkPrecedance(s.top()))
        {
            postFix_exp+=s.top();
            s.pop();

        }
        s.push(c);
    }
    while(!s.empty()){
        postFix_exp+=s.top();
        s.pop();
    }

    cout<<postFix_exp;
    
}


int main(){
    string exp="A+B*C-D/E";
    toPostFix(exp);
    return 0;
}

