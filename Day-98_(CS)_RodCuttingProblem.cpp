#include<bits/stdc++.h>
using namespace std;
   //day-98
  //MS001;


int cutRod(vector<int> &nums, int n)
{
	vector<int>prev(n+1,-1);
	vector<int>curr(n+1,-1);
	int lenght =n;
	curr[0]=0;
	for(int j=0;j<=lenght;j++){
			int lengthToCut=1;
			prev[j]=(j/lengthToCut)*nums[0];
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<=n;j++){
			int nt = prev[j];
			int pt =0;
			if((i+1)<=j) pt =nums[i]+curr[j-(i+1)];
			curr[j]=max(nt,pt);
		}
		prev=curr;
	}
	int ans =prev[n];
	return ans;
}
int main(){


vector<int>prices= {1,2,3,5,7,12,9,15,10};


int ans = cutRod(prices,9);

 cout<<ans<<"\n";
return 0;
}
