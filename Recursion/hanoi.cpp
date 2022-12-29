// Solve Tower of Hanoi Problem for 'N' Discs

#include<iostream>
using namespace std;

void towerOfHanoi(int n, char source, char des, char aux){

    if(n==1){
        cout<<"\n Move 1 disk from"<<source<<"to"<<des;
        return;
    }

    towerOfHanoi(n-1, source, aux, des);
    cout<<"\n Move 1 disk from"<<source<<"to"<<des;
    towerOfHanoi(n-1, aux, des, source);
}

int main()
{

    towerOfHanoi(3, 'A', 'B', 'C');
    return 0;
}