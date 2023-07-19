#include<bits/stdc++.h>
using namespace std;
   //day-90
   //MS001;


 bool getPutCows(int mid,int k,vector<int>&pos){
    int prev=-100000008;int rem=k;
   for(int i=0;i<pos.size();i++){

        if((pos[i]-prev)>=mid){
            rem--;
     
            if(rem==0){
                return true;
            }
            prev=pos[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
  
    int n=stalls.size(),ans=0;
    sort(stalls.begin(),stalls.end());
  
    int low=1,high=stalls[n-1]-stalls[0];
    while(low<=high){
        int mid=low+((high-low)/2);
        bool putCows =getPutCows(mid,k,stalls);

        if(putCows){
            ans=mid;
            low=mid+1;
        } else {
          high = mid - 1;
        }
    }
    return ans; 

}
 
int main(){

vector<int>nums ={1,3,4,16,18,12,16};
int ans =aggressiveCows(nums,4);
cout<<ans<<"\n";
return 0;
}
