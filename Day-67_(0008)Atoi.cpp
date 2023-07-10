#include<bits/stdc++.h>
using namespace std;

int myAtoi(string s) {
         bool strt=false;
        int sig=1;
        int ans=0;
        int i=0;
        //get rid of leading whitespace
        while(s[i]==' '){  i++;}
        
        for(;i<s.length();i++){
            //accept first sign and indiacate the number has started
            if(!strt && (s[i]=='-' ||s[i]=='+')){
                if(s[i]=='-'){
                    sig=-1;
                }
                strt=true;
            }
            //accept number assume sign + and indiacte the number started
           else if(s[i]>='0' && s[i]<='9'){
                  strt=true;
               //check overflow
                 if(ans>INT_MAX/10 || (ans==INT_MAX/10)&&(s[i]-'0'>7)){
                     return (sig==1)?INT_MAX:INT_MIN ;
                 }
               
                ans = (ans*10)+ (s[i]-'0');
            }
         //if the number started and any value other than 0-9 digits encountered 
           else if((s[i]<'0' || s[i]>'9')){
                break; 
            }
           
        }
        return sig*ans;
    }

int main(){

string s ="  -1223";
int num  = myAtoi(s);
cout<<num<<endl;

return 0;
    }