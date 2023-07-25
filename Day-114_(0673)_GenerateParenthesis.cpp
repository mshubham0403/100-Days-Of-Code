#include<bits/stdc++.h>
using namespace std;
   //day-114
  //MS001;

 void getPatterns(int k,int opened,string curr,vector<string>&ans){
        if(k==0){
            while(opened>0){
                curr+=')';
                opened--;
            }
            ans.push_back(curr);
            return; 
        }
        // choices
        // open
        curr+='(';
        getPatterns(k-1,opened+1,curr,ans);
        curr.pop_back();
        //close
        if(opened>0){
            curr+=')';
            getPatterns(k,opened-1,curr,ans);
        }
        return ;
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        getPatterns(n,0,"",ans);
        return ans;
    }