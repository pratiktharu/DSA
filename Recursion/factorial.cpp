// Find the factorial for given number 'n'

#include<iostream>

using namespace std;

long int factorial(long int n){

    if(n==0)
        return 1;

    else
        return n*factorial(n-1);
}


int main(){

    cout<<factorial(4);
    return 0;
}