#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

 bool isVowel(char j){
    if(j=='i'||j=='o'||j=='u'||j=='a' ||j=='e'){
         return true;
    }
    else{
        return false;
     }
}
    int maxVowels(string s, int k) {
        int maxs=INT_MIN;
        int curr=0,strt=0,i=0;
    
  
    for(;i<s.length();i++){
         if(isVowel(s[i])){
                 curr++;
                }
        if(i-strt+1>k){
             if(isVowel(s[strt])){
                 curr--;
                }
            strt++;
        }
       
        maxs=max(maxs,curr);
    }

    return maxs;
    }
int main(){
string s= "iamhereforalltime";

int ans = maxVowels(s,4);
cout<<ans<<endl;

return 0;
}