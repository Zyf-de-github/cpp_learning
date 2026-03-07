#include <bits/stdc++.h>
#define endl '\n'
using namespace std;



int main()
{
	vector<vector<int>> dp(31,vector<int>(10));
	dp[0][0]=1;
	for(int i=1;i<=30;i++)
	{
		int total=0;
		for(int j =1;j<10;j++)
		{
			total+=dp[i-1][j];
			dp[i][j]=dp[i-1][j-1];
		}
		dp[i][0]=total+dp[i-1][0];
	}
	int ans=0;
	for(int i=0;i<=30;i++)
	{
		ans+=dp[i][7];
	}
	cout<<ans<<endl;
	return 0;
}
