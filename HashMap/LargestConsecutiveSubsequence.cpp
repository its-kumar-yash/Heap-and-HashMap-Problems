//Given an array of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.


// amazon flipkart 

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {   
        //here bool - represent that key is starting point of subsequence
        unordered_map<int, bool> mp;
        
        // first for loop to fill hashmap with all true values
        for(int i = 0; i < N; i++){
            mp[arr[i]] = true;
        }
        
        // second for loop to check if arr[i] - 1 exist in the map or not
        for(int i = 0; i < N; i++){
            if(mp.count(arr[i] - 1)){
                mp[arr[i]] = false;
            }
        }
        
        //third for loop to process the remaining start points
        int msp = 0; // max start point
        int ml = 0; // max length
        
        for(int i = 0; i < N; i++){
            if(mp[arr[i]] == true){
                int tl = 1; // temp length
                int tsp = arr[i]; // temp start point
                
                while(mp.count(tsp + tl)){
                    tl++;
                }
                
                if( tl > ml ){
                    msp = tsp;
                    ml = tl;
                }
            }
        }
        
        return ml;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends