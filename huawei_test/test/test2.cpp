#include <bits/stdc++.h>
using namespace std;


int main()
{
    int m,n;
    cin>>m>>n;
    if(m<=0&&n<=0)return -1;
    vector<vector<int>> v(m,vector<int>(n,0));
    vector<vector<pair<int,int>>> dp(m,vector<pair<int,int>>(n,{-1,-1}));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>v[i][j];
        }
    }
    dp[0][0]={0,0};
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j>0&&v[i][j-1]==0)
            {
                if(dp[i][j-1].first==-1&&dp[i][j-1].second!=-1)dp[i][j].first=dp[i][j-1].second+1;
                else if(dp[i][j-1].first!=-1&&dp[i][j-1].second==-1)dp[i][j].first=dp[i][j-1].first;
                else if(dp[i][j-1].first!=-1&&dp[i][j-1].second!=-1)dp[i][j].first=min(dp[i][j-1].first,dp[i][j-1].second+1);
            }
            if(i>0&&v[i-1][j]==0)
            {
                if(dp[i-1][j].first==-1&&dp[i-1][j].second!=-1)dp[i][j].second=dp[i-1][j].second;
                else if(dp[i-1][j].first!=-1&&dp[i-1][j].second==-1)dp[i][j].second=dp[i-1][j].first+1;
                else if(dp[i-1][j].first!=-1&&dp[i-1][j].second!=-1)dp[i][j].second=min(dp[i-1][j].first+1,dp[i-1][j].second);
            }
        }
    }
    if(dp[m-1][n-1].first==-1&&dp[m-1][n-1].second!=-1)cout<<dp[m-1][n-1].second;
    if(dp[m-1][n-1].first!=-1&&dp[m-1][n-1].second==-1)cout<<dp[m-1][n-1].first;
    if(dp[m-1][n-1].first!=-1&&dp[m-1][n-1].second!=-1)cout<<min(dp[m-1][n-1].first,dp[m-1][n-1].second);
    if(dp[m-1][n-1].first==-1&&dp[m-1][n-1].second==-1)cout<<"-1";
    return 0;
}
