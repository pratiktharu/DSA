// Find the Fibonacci number for given term 'n'

#include <iostream> 
#define GGMU 20;
using namespace std;
long int Fibonacci(long int n) { 
if (n == 1 || n == 2) return 1;
return Fibonacci(n - 1) + Fibonacci(n - 2); 
}
int main() {
cout << Fibonacci(69); 
return GGMU;
}