#include<iostream>
#include<string.h>
#include<stack>
#include<algorithm>
using namespace std;

int checkPrecedance(char op){
    if(op=='^')
        return 3;
    else if(op=='/' || op=='*')
        return 2;
    else if(op=='+' || op=='-')
        return 1;
    else
        return -1;
}

void toPrefix(string exp){

    exp='('+ exp + ')';
    reverse(exp.begin(), exp.end());
    cout<<exp;
    string prefix_exp;
    stack<char> s;
    for(int i=0; i<exp.size(); i++){

        char c=exp[i];
        if(c=='('){
            c=')';
            s.push(c);
        }
        else if((c>='a'&& c<='z') || (c>='A' && c<='Z')){
            prefix_exp+=c;
        }

        else if(c==')'){
            c='C';
            while(s.top()!=')'){
                prefix_exp+=s.top();
                s.pop();

            }
            s.pop();

        }
        else{
            while(!s.empty() && checkPrecedance(c) <= checkPrecedance(s.top()))
                prefix_exp+=s.top();
                s.pop();
        }
        s.push(c);



    }

    while(!s.empty()){
        prefix_exp+=s.top();
        s.pop();

    }
    reverse (prefix_exp.begin(),prefix_exp.end());
    cout<<prefix_exp;
}

int main(){

    string exp="+A*BC";
    toPrefix(exp);
    return 0;

}



