#include<bits/stdc++.h>
using namespace std;
   //day-90
   //MS001;


 int findKthPositive(vector<int>& arr, int k) {
      
       int n = arr.size() ;
       int low = 0,high=n-1;
     
       while (low <= high) {
           int mid = low+((high-low)/2);
          int currMiss=arr[mid] - (1 + mid) ;
            if (currMiss < k)  
                low = mid + 1;
            else
                high = mid-1;
        }
        return low + k;
    }
      
 
int main(){

vector<int>nums ={1,3,4,6,8,12,16};
int ans =findKthPositive(nums,4);
cout<<ans<<"\n";
return 0;
}
