#include <bits/stdc++.h>
using namespace std;

vector<int> func(vector<int> arr)
{
    map<int,vector<int>> m;
    for(int i=0;i<arr.size();i++)
    {
        int temp=arr[i],num=0;
        while(temp)
        {
            if(temp&1==1){num++;}
            temp=temp>>1;
        }
        m[num].push_back(arr[i]);
    }
    vector<int> ans;
    for(auto it:m)
    {
        sort(it.second.begin(),it.second.end());
        for(auto x:it.second)ans.push_back(x);
    }
    return ans;
}

int main()
{
    vector<int> a=func({0,1,2,3,4,5,6,7});
    int b=1;
    return 0;
}
