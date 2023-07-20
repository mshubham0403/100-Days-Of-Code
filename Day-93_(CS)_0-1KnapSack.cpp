#include<bits/stdc++.h>
using namespace std;
   //day-73
   //MS001;


 int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{	
	vector<vector<int>>dp(n,vector<int>(maxWeight+1,0));
    for(int i=0;i<n;i++) dp[i][0]=0;
	for(int j=0;j<=maxWeight;j++) {
		if(weight[0]<=j){
			dp[0][j]=value[0];
		}
		else{
			dp[0][j]=0;
		}
	}
	for(int i=1;i<n;i++){
		for (int j=0;j<=maxWeight;j++){
			int notTake = dp[i-1][j];
		    int take =notTake;
			if(weight[i]<=j) take= value[i]+dp[i-1][j-weight[i]];
			dp[i][j]=max(take,notTake);
		}
	}
	return dp[n-1][maxWeight];
}
int main(){


vector<int>weights= {2,13,5 ,67,54,33 ,15,68,12 ,24,88,64};
vector<int>values= {32,5,12, 16,54,56, 87,78,99, 132,1290,80};

int ans = knapsack(weights,values,12,34);
cout<<ans<<"\n";
 cout<<endl;
return 0;
}
