//Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //create a hashmap
            vector<int> ans;
            set<int> mapA, mapB;
            
            
            //fill the first two arr with freq
            
            for(int i = 0; i < n1; i++){
                
                mapA.insert(A[i]);
                
            }
            
            for(int i = 0; i < n2; i++){
                
                if(mapA.count(B[i])){
                    
                    mapB.insert(B[i]);
                }
                
            }
            
            
            for(int i = 0; i < n3; i++){
                
                if(mapB.count(C[i])){
                    
                    if(!count(ans.begin(),  ans.end(), C[i])){
                        
                        ans.push_back(C[i]);
                        
                    }
                        
                }
            }
            
            return ans;
        }

};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}
// } Driver Code Ends