#include "bits/stdc++.h"
using namespace std;

void func1(vector<int>& v,int ptr)
{
    if(ptr>=v.size())return;
    cout<<v[ptr]<<' ';
    func1(v,ptr*2);
    func1(v,ptr*2+1);
}
void func2(vector<int>& v,int ptr)
{
    if(ptr>=v.size())return;
    func2(v,ptr*2);
    cout<<v[ptr]<<' ';
    func2(v,ptr*2+1);
}
void func3(vector<int>& v,int ptr)
{
    if(ptr>=v.size())return;
    func3(v,ptr*2);
    func3(v,ptr*2+1);
    cout<<v[ptr]<<' ';
}
int main() {
    int i=0;
    vector<int> v;
    v.emplace_back(0);
    // while(cin>>i)v.emplace_back(i);
    v={0,8 ,3 ,10 ,1 ,6 ,14, -1};
    cout<<"前序遍历结果："<<endl;
    func1(v,1);
    cout<<endl;
    cout<<"中序遍历结果："<<endl;
    func2(v,1);
    cout<<endl;
    cout<<"后序遍历结果："<<endl;
    func3(v,1);
    return 0;
}
//    8
//  3   10
// 1 6 14 -1
// 64 位输出请用 printf("%lld")