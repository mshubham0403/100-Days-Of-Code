#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

 bool alphaNumeric(char i){
     if((i>='a'&& i<='z') || ( i>='0' && i<='9')||(i>='A' && i<='Z')  ){
            return true;
            }
            return false;
}
    bool isPalindrome(string s) {
        
       int l=0,r=s.length();

       while(l<r){
           while(!alphaNumeric(s[l]) && l<r){
               l++;
           }
           while(!alphaNumeric(s[r]) && r>l){
               r--;
           }
           if(tolower(s[l])!=tolower(s[r])) return false;
           r--;l++;

       }
      
       return true;
    }
int main(){
string s="I,HaVe:AcarRenTal;Can,i drive?";

bool ans = isPalindrome(s);
cout<<ans<<endl;

return 0;
}