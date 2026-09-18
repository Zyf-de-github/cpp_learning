#include "bits/stdc++.h"
using namespace std;


int func(string& s,int k)
{
    int same=0,diff=0;
    for(int i=0;i<s.size()-1;i++)
    {
        if(s[i]==s[i+1])same++;
        else diff++;
    }
    while(same>1&&k>0)
    {
        same-=2;
        diff+=2;
        k--;
    }
    return diff;
}
int main() 
{
    int k;
    cin>>k;
    for(int i=0;i<k;i++)
    {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        cout<<func(s,k)<<endl;
    }
    return 0;
}
// 1
// 7 2
// 0110111
// 6 2
// 111111