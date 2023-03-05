#include<bits/stdc++.h>
using namespace std;

class Heap{
    public:
    //declare an array and size variable
    int arr[100];
    int size;

    Heap(){
        arr[0] = -1;
        size = 0;
    }

    //for MAX HEAP
    //function to insert element into heap
    void insert(int data){
        //step 1 - insert at end
        size += 1;
        int idx = size;
        arr[idx] = data;

        //step 2 - take it to its correct position by comparing with parent and swapping them
        while(idx > 1){
            int parent = idx/2;
            if(arr[parent] < arr[idx]){
                swap(arr[parent], arr[idx]);
                idx = parent;
            }
            else{
                return;
            }
        }
    }

    void print(){
        for(int i = 1; i <= size; i++){
            cout<< arr[i] <<" ";
        }
        cout<<endl;
    }

    void deleteFromHeap(){
        if(size == 0){
            cout<<"Empty Heap"<<endl;
        }

        //step 1 - replace the root node with last node
        arr[1] = arr[size];

        //step 2 - remove last node
        size--;

        //step 3 - propagate root node to its correct location
        int idx = 1; 
        while (idx < size){
            int leftChild = 2*idx;
            int rightChild = 2*idx + 1;
            
            if(leftChild < size && arr[idx] < arr[leftChild]){
                swap(arr[idx], arr[leftChild]);
                idx = leftChild;
            }
            else if(rightChild < size && arr[idx] > arr[rightChild]){
                swap(arr[idx], arr[rightChild]);
                idx = rightChild;
            }
            else{
                return;
            }
        }
    }
};

void heapify(int arr[], int size, int idx){
    //for max heap

    int largest = idx;
    int leftChild = 2*idx;
    int rightChild = 2*idx + 1;

    if(leftChild <= size && arr[largest] < arr[leftChild]){
        largest = leftChild;
    }
    if(rightChild <= size && arr[largest] < arr[rightChild]){
        largest = rightChild;
    }

    if(largest != idx){
        swap(arr[largest], arr[idx]);
        heapify(arr, size, largest);
    }
}

void heapSort(int arr[], int n){

    int size = n; // last index

    while(size > 1){

        //step 1 - swap root and last node
        swap(arr[size], arr[1]);

        //step 2 - remove the last node
        size--;

        //step 3 - heapify using root node
        heapify(arr, size, 1);

    }

}


int main(){
    
    Heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();

    h.deleteFromHeap();
    h.print();

    int arr[] = {-1, 54, 53, 55, 53, 50};
    int n = 5;

    //heap creation
    for(int i = n/2; i > 0; i--){
        heapify(arr , n, i);
    }

    for(int i = 1; i <= n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    //heap sort
    heapSort(arr, n);

    for(int i = 1; i <= n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}