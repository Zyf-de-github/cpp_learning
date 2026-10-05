#include "bits/stdc++.h"
using namespace std;

int main() {
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>>v;
    map<int,vector<int>>mp;
    for(int i=0;i<n;i++)
    {
        vector<int>temp;
        string str;
        cin>>str;
        for(int j=0;j<m;j++)if(str[j]-'0')temp.push_back(j);
        v.push_back(temp);
    }
    for(int i=0;i<n;i++) for(auto it:v[i]) mp[it].push_back(i);
    int ans=0;
    for(auto itt:v)
    {
        int flag=1;
        for(auto it:itt)
        {
            if(mp[it].size()<=k)
            {
                flag=0;
                break;
            }
        }
        if(flag)ans++;
    }
    cout<<ans;
    return 0;
}
// 64 位输出请用 printf("%lld")