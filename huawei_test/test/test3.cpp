#include <bits/stdc++.h>
using namespace std;


int dfs(int cur,vector<int>& cost,vector<int>& earn,int n,int ans)
{
    if(n>=cost.size())return ans;
    if(cur>=cost[n]&&earn[n]-cost[n]>=0)
    {
        cur+=earn[n]-cost[n];
        ans++;
        n++;
    }
    else
    {
        if(cur-cost[n]>=0) ans=max(dfs(cur-cost[n]+earn[n],cost,earn,n+1,ans+1),dfs(cur,cost,earn,n+1,ans));
        else ans=dfs(cur,cost,earn,n+1,ans);
    }
    return ans;
}
int main()
{
    int cur;
    vector<int> cost,earn;
    string str;
    getline(cin,str);
    cur=stoi(str);
    getline(cin,str);
    stringstream ss(str);
    while(getline(ss,str,' '))
    {
        cost.push_back(stoi(str));
    }
    getline(cin,str);
    stringstream sss(str);
    while(getline(sss,str,' '))
    {
        earn.push_back(stoi(str));
    }
    cout<<dfs(cur,cost,earn,0,0);
    return 0;
}
