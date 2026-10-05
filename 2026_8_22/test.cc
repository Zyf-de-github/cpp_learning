#include "bits/stdc++.h"
using namespace std;

bool func(string str)
{
    int s_ptr,e_ptr,x_ptr,door_ptr;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='s')s_ptr=i;
        if(str[i]=='e')e_ptr=i;
        if(str[i]=='x')x_ptr=i;
        if(str[i]=='|')door_ptr=i;
    }
    if((s_ptr<door_ptr&&door_ptr<e_ptr&&door_ptr<x_ptr)||
        (s_ptr>door_ptr&&door_ptr>e_ptr&&door_ptr>x_ptr))return false;
    return true;
}

int main() {
    int n;
    vector<bool> v;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        string s;
        cin>>x>>s;
        v.push_back(func(s));
    }
    for(auto it:v)
    {
        if(it)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}