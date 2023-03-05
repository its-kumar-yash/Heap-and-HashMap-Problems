//Given an array of n elements, where each element is at most k away from its target position, you need to sort the array optimally.

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int num, int K){
        vector<int> ans;
        //create min heap
        priority_queue<int, vector<int>, greater<int>> pq;
        
        //push first k element into heap
        for(int i = 0; i <= K; i++){
            pq.push(arr[i]);
        }
        
        for(int i = K + 1; i < num; i++){
            //release
            ans.push_back(pq.top());
            pq.pop();
            
            //accquire
            pq.push(arr[i]);
        }
        
        //pop till element in heap
        while(pq.size() > 0){
            ans.push_back(pq.top());
            pq.pop();
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    Solution ob;
	    vector <int> res = ob.nearlySorted(arr, num, K);
	    for (int i = 0; i < res.size (); i++)
	        cout << res[i] << " ";
	        
	    cout<<endl;
	}
	
	return 0;
}

// } Driver Code Ends