// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Stack{
    int count;
    priority_queue<pair<int,int>> pq; // its like key->value
    public:
    Stack():count(0){}
    void push(int n);
    void pop();
    int top();
    bool isEmpty();
    
};

 void Stack:: push(int n){
    count++;
    pq.push({count,n});
}

 void Stack::pop(){
    if(pq.empty()){
        cout<<"No element to pop";
    }
    else{
        count--;
        pq.pop();
    }
}

int Stack::top(){
    if(pq.empty()){
        cout<<"Stack is empty";
        return INT_MIN;
    }
    else{
        auto x= pq.top();
        return x.second;
    }
}

bool Stack::isEmpty(){
    return pq.empty();
}
int main() {
    Stack *s = new Stack();
    s->push(1);
    s->push(2);
    s->push(3);
    
    while(!s->isEmpty()){
        cout<<s->top()<<"\n";
        s->pop();
    }

    return 0;
}