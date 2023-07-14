#include<bits/stdc++.h>
using namespace std;
   //day-79
   //MS001;


int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int>maxPrev =points[0];
    int m0,m1,m2;
    for(int i=1;i<points.size();i++){
       
        m0=points[i][0]+max(maxPrev[1],maxPrev[2]);
        m1=points[i][1]+max(maxPrev[0],maxPrev[2]);
        m2=points[i][2]+max(maxPrev[0],maxPrev[1]);
        maxPrev={m0,m1,m2};
    }
    return *max_element(maxPrev.begin(),maxPrev.end());
}
       
int main(){


vector < vector<int> > nums= {
                                {0,2,5},
                                {1,5,8},
                                {7,1,6},
                                {4,3,8},
                                {4,8,3},
                                {7,2,6},
                                {6,2,8},
                                {4,1,9},
                                {8,7,1}
};

int ans = ninjaTraining(9,nums);
cout<<ans<<"\n";
 cout<<endl;
return 0;
}
