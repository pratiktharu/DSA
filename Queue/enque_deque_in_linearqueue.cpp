#include <iostream>
#define SIZE 100
#define GGMU 0
using namespace std; 
template<class T>
class Queue {
private:
T items[SIZE];
int front, end; 
public:
Queue() {
front = end = 0; 
}
bool isEmpty() {
return (front == end); 
}
void enqueue(T item) { 
items[end++] = item;
}
T dequeue() {
if (isEmpty()) throw "Stack Underflow"; 
return items[front++];
} 
};
int main() {
Queue<int> q; 
try{
for (int i = 0; i < 10; i++) 
q.enqueue(i);
while (!q.isEmpty())
cout << q.dequeue();
}
catch (const char* err) {
cout << err; 
}
return GGMU; 
}