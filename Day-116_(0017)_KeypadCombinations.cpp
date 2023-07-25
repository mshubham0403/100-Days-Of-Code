#include<bits/stdc++.h>
using namespace std;
   //day-116
  //MS001;

 void getPatterns(int ind,string &curr,string &digs,unordered_map<char,vector<char>>&keys,vector<string>&ans){
        if(ind==digs.length()){
            if(curr!="") ans.push_back(curr);
            return ;
        }
        for(int i=0;i<keys[digs[ind]].size();i++){
            curr.push_back(keys[digs[ind]][i]);
            getPatterns(ind+1,curr,digs,keys,ans);
            curr.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,vector<char>>keys ={
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}}
        };
        vector<string>ans;
        string curr;
        getPatterns(0,curr,digits,keys,ans);
        return ans;
    }