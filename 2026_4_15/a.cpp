#include <bits/stdc++.h>
using namespace std;


int main()
{
    
    return 0;
}


// int func(vector<int>& v,int i,bool flag,vector<vector<int>>& dp)//flag=0 不选自己，flag=1 选自己
// {
//     if (i>=v.size())return 0;
//     if (dp[i][flag]!=-1) return dp[i][flag];
//     int a = func(v,i*2,0,dp)+func(v,i*2+1,0,dp)+v[i];
//     dp[i][1]=a;
//     int b1 = func(v,i*2,0,dp)+func(v,i*2+1,1,dp);
//     int b2 = func(v,i*2,1,dp)+func(v,i*2+1,1,dp);
//     int b3 = func(v,i*2,1,dp)+func(v,i*2+1,0,dp);
//     dp[i][0]=max(b1,max(b2,b3));
//     if (flag==0)return dp[i][0];
//     return dp[i][1];
// }
// int main()
// {
//     int n;
//     cin>>n;
//     vector<int> v(n+1,-1);
//     vector dp(n+1,vector(2,-1));
//     for (int i=1;i<=n;i++) cin>>v[i];
//     func(v,1,0,dp);
//     cout<<max(dp[1][1],dp[1][0]);
//     return 0;
// }

// int main()
// {
//     int a,b;
//     cin>>a>>b;
//     cout<<a+b;
//     return 0;
// }