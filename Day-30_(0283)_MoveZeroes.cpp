#include<bits/stdc++.h>
using namespace std;

  void moveZeroes(vector<int>& a) {
    int cnt = 0, j = a.size() - 1;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == 0) {
            cnt++;
          
        } else {
            a[i - cnt] = a[i];
        }
    }
  int ind = (a.size() - cnt)-1;
    while (j > ind) {
       
        a[j--]=0;
      
    }
    }
int main(){
vector<int>nums={1,2,3,0,9,0,3,0,2,0,44,0,89,0,21};

 moveZeroes(nums);
for(auto &x:nums){
  
        cout<<x<<" ";
    }
cout<<endl;


return 0;
}
