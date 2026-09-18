#include "bits/stdc++.h"
using namespace std;


vector<bool> func(int n,vector<pair<int,int>>& v,int d)
{
    vector<bool> butten(n,false);
    vector<int> vd(n,-1);
    for(int i=0;i<v.size();i++)
    {
        for(int j=v[i].first;j<=v[i].second;j++)
        {
            if(vd[j]!=-1&&i-vd[j]<=d)
            {
                vd[j]=-1;
                butten[j]=!butten[j];
            }
            else vd[j]=i;
        }
    }
    return butten;
}
int main() 
{
    int t;
    cin>>t;
    int n,m,d;
    for(int i=0;i<t;i++)
    {
        cin>>n>>m>>d;
        vector<pair<int,int>>v(m,{0,0});
        vector<bool> butten(n,false);
        for(int j=0;j<m;j++)
        {
            int temp1,temp2;
            cin>>temp1>>temp2;
            v[j]={temp1-1,temp2-1};
        }
        butten=func(n,v,d);
        for(auto it:butten)cout<<it<<' ';
        cout<<endl;
    }
    return 0;
}