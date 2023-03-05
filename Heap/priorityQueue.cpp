#include<bits/stdc++.h>
#include<queue>
using namespace std;


int main(){
    
    //implementing priority queue
    //1. max - heap
    priority_queue<int> pq;

    pq.push(5);
    pq.push(3);
    pq.push(10);
    pq.push(8);

    cout<<"priority queue top" << pq.top()<<endl;
    pq.pop();
    cout<<"priority queue top "<< pq.top()<<endl;

    cout<<"priority queue size "<< pq.size()<<endl;

    //2. min - heap
    priority_queue<int, vector<int>, greater<int>> minHeap;

    minHeap.push(5);
    minHeap.push(3);
    minHeap.push(10);
    minHeap.push(8);

    cout<<"priority queue top" << minHeap.top()<<endl;
    minHeap.pop();
    cout<<"priority queue top "<< minHeap.top()<<endl;

    cout<<"priority queue size "<< minHeap.size()<<endl;


    return 0;
}