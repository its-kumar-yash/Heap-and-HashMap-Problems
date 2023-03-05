// Given a string str. The task is to find the maximum occurring character in the string str. If more than one character occurs the maximum number of time then print the lexicographically smaller character.

//FLipkart

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        unordered_map<char, int> mp;
        
        for(int i = 0; i < str.length(); i++){
            mp[str[i]]++;
        }
        
        int maxi = 0;
        char ch = 'z';
        
        for(auto i : mp){
            if(maxi < i.second){
                maxi = i.second;
                ch = i.first;
            }
            else if(maxi == i.second){
                if(i.first < ch){
                    ch = i.first;
                }
            }
        }
        
        
        return ch;
    }

};

//{ Driver Code Starts.

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}
// } Driver Code Ends