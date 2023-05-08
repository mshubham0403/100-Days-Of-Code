#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

   vector<vector<int>> threeSum(vector<int>& num){
    vector<vector<int>> res; 
        sort(num.begin(), num.end()); 
        
    int i=0,k=0,tmp=0,j=0;
    int n=num.size();
        for (; j <n-2; j++) {
            
            if(j==0 || (j > 0 && num[j] != num[j-1])) {
                
                 i = j+1;
                k = n-1;
                
                while (i<k) {
                    tmp=num[i] + num[k];
                    if (tmp ==((-1)*(num[j])) ) {
                        
                      
                        res.push_back({num[j],num[i],num[k]});
                        
                        while (i < k && num[i] == num[i+1]) i++;
                        while (i < k && num[k] == num[k-1]) k--;
                        
                        i++; k--;
                    } 
                    else if (num[i] + num[k] < ((-1)*(num[j])) ) i++;
                    else k--;
               }
            }
        }
        return res;
    }
int main(){
vector<int>nums={2,1,3,4,5,8,7,9,6,10,13,12,11,14};

vector<vector<int>> ans = threeSum(nums);
for(auto &x:ans){
    for(auto &i:x){
        cout<<i;
    }
    cout<<endl;
}

return 0;
}