#include<bits/stdc++.h>
#include<map>
#include<unordered_map>
using namespace std;


int main(){
    //creation of map
    unordered_map<string, int> m;

    //methods for insertion
    //1.
    pair<string, int> p = make_pair("Hi" , 3);
    m.insert(p);
    
    //2.
    pair<string, int> p2("Hello", 5);
    m.insert(p2);

    //3.
    m["Hola"] = 1;

    // methods for searching
    //1.
    cout<<m["Hi"]<<endl;

    //2.
    cout<<m.at("Hola")<<endl;

    // -> searching unknown key in map
    cout<<m["unKnown"]<<endl; // create an empty entry in the map with value zero

    cout<<m.at("unKnown")<<endl; // throw an error as key does not exist in the map

    //To check presence 
        // -> absent  =  0
        // -> present = 1
    m.count("Hi");

    //erase
        // -> to remove entry from map
    m.erase("unknown");

    // Iterator over map

    //1.
    for(auto i : m){
        cout<<i.first<<" "<<i.second<<endl;
    }

    //2.

    unordered_map<string,int>::iterator it = m.begin();

    while(it != m.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }




    return 0;
}