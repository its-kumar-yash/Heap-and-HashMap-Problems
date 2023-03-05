//Given an input stream of N integers. The task is to insert these numbers into a new stream and find the median of the stream formed by each insertion of X to the new stream.

// Very Important Question

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{   

    // right side element
    public:
    priority_queue<int> maxHeap;// left half elements
    priority_queue<int, vector<int>, greater<int>> minHeap;
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if (maxHeap.empty() || x <= maxHeap.top())
            maxHeap.push(x);
        else
            minHeap.push(x);
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        if (minHeap.size() - maxHeap.size() > 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        else if (maxHeap.size() - minHeap.size() > 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        if (maxHeap.size() == minHeap.size())
            return (minHeap.top() + minHeap.top()) / 2.0;
            
        return maxHeap.top();

    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends