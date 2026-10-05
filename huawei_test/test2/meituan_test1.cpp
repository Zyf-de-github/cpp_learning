#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int num;
        long long ans=0;
        cin>>num;
        map<int,pair<int,int>> m;
        for(int j=0;j<num;j++)
        {
            int temp;
            cin>>temp;
            if(m.find(temp)==m.end())m[temp].first=1;
            else m[temp].first++;
        }
        int x=0;
        auto ptr_left=m.begin(),ptr_right=m.begin();
        while(ptr_left!=m.end()||ptr_right!=m.end())
        {
            if(ptr_right!=m.end()&&ptr_right->first<2*ptr_left->first)
            {
                x++;
                ptr_right++;
            }
            else
            {
                ptr_left->second.second=x;
                ptr_left++;
            }
        }
        for(auto it=m.begin();it!=m.end();it++)
        {
            if(it->second.first>2)ans+=it->second.second;
            else if(it->second.first>1)ans+=it->second.second-1;
        }
        cout<<ans<<endl;
    }
    return 0;
}



// 1
// 10
// 1 1 1 3 3 4 4 5 9 10