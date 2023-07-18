#include<bits/stdc++.h>
using namespace std;
   //day-89
   //MS001;

long long getPow(int mid,int n,int m){
   long long nthPow=1;
  for (int i = 1; i <= n; i++) {
    nthPow =nthPow* mid;
    if(nthPow>m){
      return nthPow; 
    }
  }
  return nthPow;
}
int NthRoot(int n, int m) {
  // Write your code here.
  long long low=1,high=m,ans=-1;
  while(low<=high){
    long long mid=low+((high-low)/2);
    long long nthPow=getPow(mid,n,m);
    if(nthPow>m){
      high=mid-1;
     
    }
    else if(nthPow==m){
      return mid;
    }
    else{
      low=mid+1;
    }
  }
  return ans;

}


 
int main(){

int m=729,n=3;
int ans =NthRoot(n,m);
cout<<ans<<"\n";
return 0;
}
