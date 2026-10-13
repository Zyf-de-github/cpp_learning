#include "bits/stdc++.h"
using namespace std;

int main() {
    char c;
    bool state=false;
    vector<int>v1,v2,ans;
    while(cin>>c)
    {
        if(state==true&&(c>='0'&&c<='9'))v1.emplace_back(c-'0');
        else if(c=='{')state=true;
        else if(c=='}')break;
    }
    state=false;
    while(cin>>c)
    {
        if(state==true&&(c>='0'&&c<='9'))v2.emplace_back(c-'0');
        else if(c=='{')state=true;
    }

    // v1={1,3,5,7,9};
    // v2={2,3,4,5,6,8};
    int ptr1=0,ptr2=0,size1=v1.size(),size2=v2.size();
    while(ptr1<size1||ptr2<size2)
    {
        if(ptr1==size1)ans.emplace_back(v2[ptr2++]);
        else if(ptr2==size2)ans.emplace_back(v1[ptr1++]);
        else
        {
            if(v1[ptr1]>v2[ptr2])ans.emplace_back(v2[ptr2++]);
            else if(v1[ptr1]<v2[ptr2])ans.emplace_back(v1[ptr1++]);
            else 
            {
                ans.emplace_back(v1[ptr1++]);
                ptr2++;
            }
        }
    }
    cout<<'[';
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i];
        if(i!=ans.size()-1)cout<<', ';
        else cout<<']';
    }
    return 0;
}
// 64 位输出请用 printf("%lld")