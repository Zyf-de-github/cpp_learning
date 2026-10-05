#include <bits/stdc++.h>
using namespace std;


int main()
{
    string s,str;
    getline(cin,s);
    int n=stoi(s);
    for(int i=0;i<n;i++)
    {
        getline(cin,s);
        int begin=-1,end=-1;
        for(int j=0;j<s.size();j++)
        {
            if(s[j]>'m'&&begin==-1)begin=j;
            if(s[j]<='m'&&begin!=-1)
            {
                end=j;
                break;
            }
        }
        if(begin!=-1&&end==-1)end=s.size();
        for(int j=begin;j<end;j++)s[j]='z'-s[j]+'a';
        cout<<s<<endl;
    }
    return 0;
}
