#include "Deque.cpp"
#include <iostream>
#include <fstream>
using namespace std;

int main()

{
    Deque d1;
    int out = d1.peekFront();
    cout << out;
    d1.insertFront(1);
     out = d1.peekFront();
    cout << out;
    d1.insertFront(2);
     out = d1.peekFront();
    cout << out;
    d1.insertFront(3);
     out = d1.peekFront();
    cout << out;

    d1.insertBack(0);
    out = d1.peekBack();
    cout << out;

    //Deque d2 = d1;
    //int outsize = d2.size();
   // cout << outsize;
    
    
    // Deque<int> dq1;

    // cout << dq1.empty() << " - 1" << endl;

    // dq1.insertFront(42);

    // dq1.insertBack(216);

    // cout << dq1.peekFront() << " - 42" << endl;

    // cout << dq1.peekBack() << " - 216" << endl;

    // cout << dq1.size() << " - 2" << endl;

    // Deque<int> dq2(dq1);

    // Deque<int> dq3;

    // dq3 = dq1;

    // cout << dq1.removeFront() << " - 42" << endl;

    // cout << dq1.removeBack() << " - 216" << endl;

    // cout << dq2.peekFront() << " - 42" << endl;

    // cout << dq2.peekBack() << " - 216" << endl;

    // cout << dq3.peekFront() << " - 42" << endl;

    // cout << dq3.peekBack() << " - 216" << endl;

    return 0;
}