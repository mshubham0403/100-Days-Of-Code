#include<bits/stdc++.h>
using namespace std;
   //day-68
   //MS001;
int fact(int n,vector<int>&factorial){
        if(n<2){
            factorial[n]=1;
            return 1;
        }
        if(factorial[n]!=-1){
            return factorial[n];
        }
        if(factorial[n-1]!=-1){
            return n*factorial[n-1];
        }
        int ans = n*fact(n-1,factorial);
        factorial[n]=ans;
        return ans;
    }
    string getPermutation(int n, int k) {
       string ans="";
        vector<int>taken(n,0);
        vector<int>factorial(n+1,-1);
        factorial[0]=1;
       int lastFact= fact(n,factorial);
        int numbersRem =n;
      int   kthPerm =k-1;
        while(ans.length()<n){
          int  p = (factorial[numbersRem])/numbersRem;
          int  advance =kthPerm/p;
            int i=1,j=1,inc=0;
            while(i<=n && inc<=advance){
                if(taken[i-1]){
                    i++;
                }
                else{
                    j=i++;
                    inc++;
                }
            }
            ans+=to_string(j);
            taken[j-1]=1;
            numbersRem--;
            kthPerm -=p*(advance);
        }
        return ans;
        
    }



int main(){


string  ans = getPermutation(5,56);

for(auto &x:ans){
    
  cout<<x<<" ";
}
 cout<<endl;
return 0;
}
