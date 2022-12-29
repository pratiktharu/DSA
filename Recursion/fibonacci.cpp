// Find the Fibonacci number for given term 'n'

#include <iostream> 
using namespace std;

long int Fibonacci(long int n) { 
    if (n == 1 || n == 2) 
        return 1;
    else
        return (Fibonacci(n - 1) + Fibonacci(n - 2)); 
}
int main(){
    cout<<Fibonacci(69); 
    return 0;
}