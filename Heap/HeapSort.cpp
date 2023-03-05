#include<bits/stdc++.h>
using namespace std;




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



//Approach 2 - 0 based indexing

//{ Driver Code Starts
// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// The functions should be written in a way that array become sorted 
// in increasing order when heapSort() is called.

class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
        
        int largest = i;
        int leftChild = 2*i + 1;
        int rightChild = 2*i + 2;
          
        if(leftChild < n && arr[largest] < arr[leftChild]){
            largest = leftChild;
        }
        if(rightChild < n && arr[largest] < arr[rightChild]){
            largest = rightChild;
        }
        
        if(largest != i){
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
        for(int i = n / 2 - 1; i >= 0; i--){
            heapify(arr, n, i);
        }
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {   
        buildHeap(arr, n);
        
        for(int i = n - 1; i > 0 ; i--){
            
            swap(arr[i], arr[0]);
            
            heapify(arr, i, 0);
        }
    }
};




//{ Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    Solution ob;
    ob.heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}

// } Driver Code Ends