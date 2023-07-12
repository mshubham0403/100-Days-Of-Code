#include<bits/stdc++.h>
using namespace std;
   //day-73
   //MS001;


 int frogJump(int n, vector<int> &heights)
{
    
    
    int twoBack=0;
    int oneBack=abs(heights[0]-heights[1]);
    for(int i=2;i<n;i++){
       int currVal=min( (abs(heights[i-1]-heights[i])+oneBack) , ( abs ( heights[i]-heights[i-2] ) + twoBack )  );
        twoBack=oneBack;
        oneBack =currVal;
    }
    return oneBack;
}
int main(){


vector<int>nums= {2,13,5,67,54,33,15,68,12,24,88,64};
int ans = frogJump(12,nums);
cout<<ans<<"\n";
 cout<<endl;
return 0;
}
