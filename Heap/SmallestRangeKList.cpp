//Given K sorted lists of integers, KSortedArray[] of size N each. The task is to find the smallest range that includes at least one element from each of the K lists. If more than one such range's are found, return the first such range found.

//Microsoft Flipkart

#include<bits/stdc++.h>
using namespace std;
#define N 1000


// } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class Solution{
    public:
    
    class Node{
        public: 
        int val;
        int row;
        int col;
        
        Node(int d, int r, int c){
            this -> val = d;
            this -> row = r;
            this -> col = c;
        }
    };


    class cmp{
        public:
        bool operator()(Node* a, Node* b){
            return a -> val > b -> val;
        }

    };

    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k){
    //initialize lower and upper bound of smallest range
        int mini = INT_MAX;
        int maxi = INT_MIN;
        //create a min Heap of node type
        priority_queue<Node*, vector<Node*>, cmp> pq;
        //Step 1 -> 
        //push first element from every arr in nums
        // also update minRange and maxRange values
        
        for(int i = 0; i < k; i++){
            
            int elem = KSortedArray[i][0];
            mini = min(mini, elem);
            maxi = max(maxi, elem);
            pq.push(new Node(elem, i, 0));
        }
        
        int start_index = mini;
        int end_index = maxi;
        // step 2 -> element in the heap till any one of the list exhaust
        while(!pq.empty()){
            
            Node* temp = pq.top();
            
            pq.pop();
            //update mini 
            mini = temp -> val;
            //update range
            if(maxi - mini < end_index - start_index){
                
                start_index = mini;
                end_index = maxi;
            }
            
            if(temp -> col + 1 < n){
                maxi = max(maxi, KSortedArray[temp -> row][temp -> col + 1]);
                pq.push(new Node(KSortedArray[temp -> row][temp -> col + 1], temp -> row, temp -> col + 1));

            }
            else
                break;
        }

        return {start_index, end_index};

    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}


// } Driver Code Ends