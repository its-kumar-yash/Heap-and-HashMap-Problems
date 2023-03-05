#include<bits/stdc++.h>
using namespace std;

//1 based indexing
void heapify(int arr[], int size, int idx){
    //for max heap

    int largest = idx;
    int leftChild = 2*idx;
    int rightChild = 2*idx + 1;

    if(leftChild < size && arr[largest] < arr[leftChild]){
        largest = leftChild;
    }
    if(rightChild < size && arr[largest] < arr[rightChild]){
        largest = rightChild;
    }

    if(largest != idx){
        swap(arr[largest], arr[idx]);
        heapify(arr, size, largest);
    }
}


int main(){

    int arr[] = {-1, 54, 53, 55, 53, 50};
    int n = 5;

    for(int i = n/2; i > 0; i--){
        heapify(arr , n, i);
    }


    for(int i = 1; i <= n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;


    return 0;
}