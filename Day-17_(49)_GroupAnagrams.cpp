#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

  long long hashS(string & s,vector<long long>&ppow) {
     int p = 31;
     long long mod = 1e9 + 9;
    long long hash_value = 0;
    long long pp = 1;
       
        
    for (char c : s) {
        pp=ppow[(c - 'a')] ;
        hash_value = (hash_value + pp)% mod;
       
    }
    return hash_value;
}
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        long long p=31;
         long long mod = 1e9 + 9;
         vector<long long> ppow;
        for(int i=0;i<26;i++){
            p=(p*31 %mod);
            ppow.push_back(p);
        }
        int n=strs.size();
        unordered_map<long long,vector<string>> coll;
        vector<vector<string>> ans;
        long long hsh=0;
        
        for (int i=0;i<n;i++){
            hsh= hashS(strs[i],ppow);
            coll[hsh].push_back(strs[i]);
        }
        for(auto &pair:coll){
            ans.push_back(pair.second);
        }
        return ans;
    }
int main(){
vector<string>strs={"cat","car","ace","aec","ice","cie","eic"};

vector<vector <string>> ans = groupAnagrams(strs);
for(auto &x: ans){
  for(auto &i:x){
    for(auto &c:i){
      cout<<c;
    }
    cout<<" ";
  }
  cout<<endl;
}

return 0;
}