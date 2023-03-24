//RemoveAndReverse - GFG Problem

// Link : https://practice.geeksforgeeks.org/problems/1e2f365be6114b671b915e145ec7dbcfdc432910/1

/*
Given a string S which consists of only lowercase English alphabets, you have to perform the below operations:
If the string S contains any repeating character, remove the first repeating character and reverse the string and again perform the above operation on the modified string, otherwise, you stop.
You have to find the final string.
*/

//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string S) {
        //craete freq map of the string S
        int n = S.size();
        unordered_map<char, int> freq;
        
        for(auto ch : S){
            freq[ch]++;
        }
        
        //intialize two pointer start and end
        int st = 0;
        int end = n - 1;
        
        //initialize direction 
        int dir = 0;
        // 0 - left to right
        // 1 - right to left
        
        
        while(st <= end){
            //seedha chlna hai 
            if(dir == 0){
                //if char is not repeating character
                if(freq[S[st]] == 1){
                    st++;
                }
                else{
                    freq[S[st]]--;
                    S[st] = '*'; //it will tell that this char is removed
                    //also changed the direction after removal
                    st++;
                    dir = 1;
                }
            }
            //piche se chlna hai
            else{
                //if char is not repeating character
                if(freq[S[end]] == 1){
                    end--;
                }
                else{
                    freq[S[end]]--;
                    S[end] = '*';
                    end--;
                    dir = 0;
                }
            }
        }
        
        string ans = "";
        //at the end, push back ch into ans if not *
        for(auto ch : S){
            if(ch != '*'){
                ans.push_back(ch);
            }
        }
        
        //if at the end direction is 1, return the str after reversal
        if(dir == 1){
            reverse(ans.begin(), ans.end());
        }
        
        return ans;
    }
};


class Solution {
  public:
    string removeReverse(string S) {
        string ans;
        map<int,char> mp; // map to store the index corrensponding to each character
        unordered_map<char,int> freq; // map to store the frequency of each character
        
        for(int i=0 ; i<S.length() ; i++){
            mp[i] = S[i];
            freq[S[i]]++;
        }
        
        bool lToR = true;
        while(true){
            // traversing left to right in the map
            if(lToR == true){ 
                auto i = mp.begin();
                for( ; i != mp.end() ; i++){
                    // for the first repeating character delete that index value from map
                    // and decrease its frequency
                    if(freq[i->second] > 1){
                        freq[i->second]--;
                        mp.erase(i->first);
                        break;
                    }
                }
                if(i == mp.end())
                    break;
            }
            
            else{
                // traversing right to left in the map
                auto i = mp.rbegin();
                for( ; i != mp.rend() ; i++){
                    // for the first repeating character delete that index value from map
                    // and decrease its frequency
                    if(freq[i->second] > 1){
                        freq[i->second]--;
                        mp.erase(i->first);
                        break;
                    }
                }
                if(i == mp.rend())
                    break;
            }
            lToR = !lToR;
        }
        
        // store the remaining non repeating characters in ans string
        for(auto i : mp){
            ans.push_back(i.second);
        }
        
        // reverse the string if last traversal was from left to right
        if(!lToR){
            reverse(ans.begin(),ans.end());
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends
