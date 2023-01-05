// Find the factorial and fibonacci of given n number using tail recursion. 

#include<iostream>
using namespace std;

long int tailFibonacci(long int n, long int a=1, long int b=1){

    if(n==1)
        return a;
    else if(n==2)
        return b;
    else 
        return tailFibonacci(n-1,b,a+b);

}

long int tailFactorial(long int n, long int result=1){

    if(n==0)
        return result;
    else    
        return tailFactorial(n-1, result*n);
}

int main()
{

    cout<<tailFibonacci(4)<<endl;
    cout<<tailFactorial(4);
    return 0;
}