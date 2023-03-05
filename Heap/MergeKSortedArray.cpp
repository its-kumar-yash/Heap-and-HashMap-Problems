//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++

//Approach 1 - Brute Force


class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int> ans;
        
        for(int i = 0; i < arr.size(); i++){
            for(int j = 0; j < arr[0].size(); j++){
                ans.push_back(arr[i][j]);
            }
        }
        
        sort(ans.begin(), ans.end());
        
        
        return ans;
    }
};

//Aproach 2 - Using Min Heap


class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int> ans;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i = 0; i < arr.size(); i++){
            for(int j = 0; j < arr[0].size(); j++){
                pq.push(arr[i][j]);
            }
        }
        
        while(pq.size() > 0){
            ans.push_back(pq.top());
            pq.pop();
        }
        
        
        return ans;
    }
};

//Approach 3 - Optimized version

class Solution
{
    public:
    //Function to merge k sorted arrays.
    class pair{
        public:
        int arrIdx;
        int dataIdx;
        int val;
      
        pair(int arrIdx, int dataIdx, int val){
            this->arrIdx = arrIdx;
            this->dataIdx = dataIdx;
            this->val = val;
        }
    };
    
    class cmp{
        public:
        bool operator()(pair &a, pair &b){
            return a.val > b.val;   
        }  
    };
    
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<pair, vector<pair>, cmp> pq; // minheap of pair type
        
        
        for(int i = 0; i < K; i++){
            pair p(i, 0, arr[i][0]);
            pq.push(p);
        }
        
        vector<int> ans;
        
        while(!pq.empty()){
            pair top = pq.top();
            pq.pop();
            
            
            ans.push_back(top.val);
            
            if(top.dataIdx < K - 1){
                top.dataIdx++;
                top.val = arr[top.arrIdx][top.dataIdx];
                pq.push(top);
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends