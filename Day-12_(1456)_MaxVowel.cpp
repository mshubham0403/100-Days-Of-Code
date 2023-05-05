#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

 string predictPartyVictory(string &senate) {
        int radiant=0;
        int dire=0,tmp=0;
        int nl=senate.length();
        queue<int>r;
        queue<int>d;
        for(int i=0;i<senate.length();i++){
            if(senate[i]=='R'){
                r.push(i);
                }
            else{
                  d.push(i);  
        }
        }
        
      
        while(!r.empty() && !d.empty()){
            if(r.front()<d.front()){
                d.pop();
                tmp=r.front();
                r.pop();
                r.push(tmp+nl);
            }
            else{
                r.pop();
                tmp=d.front();
                d.pop();
                d.push(tmp+nl);
            }
        }
        if(!r.empty()){
            return"Radiant";
        }
        else{
            return"Dire";
        }
        
       
    }
int main(){
string senate= "RDRDDDRD";

string ans = predictPartyVictory(senate);
cout<<ans<<endl;

return 0;
}