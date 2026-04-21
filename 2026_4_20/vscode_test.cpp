// #include <bits/stdc++.h>
// using namespace std;
// pair<string,int> func(vector<vector<int>>& map_v,vector<pair<string,int>>& v)
// {
//     int ans;
//     string name;
//     vector<int> used(map_v.size(),0);
//     deque<int> dq;
//     for(int i=0;i<map_v.size();i++)
//     {
//         if(used[i]==1)continue;
//         int temp_total=0;
//         string temp_name;
//         int temp_cur_max=0;
//         dq.push_back(i);
//         used[i]=1;
//         while(dq.empty()==false)
//         {
//             int temp=dq.front();
//             dq.pop_front();         
//             temp_total+=v[temp].second;
//             if(temp_cur_max<v[temp].second)
//             {
//                 temp_name=v[temp].first;
//                 temp_cur_max=v[temp].second;
//             }
//             for(int j=0;j<map_v.size();j++)
//             {
//                 if(used[j]==0&&map_v[temp][j]==1)
//                 {
//                     dq.push_back(j);
//                     used[j]=1;
//                 }
//             }
//         }
//         if(ans<temp_total)
//         {
//             ans=temp_total;
//             name=temp_name;
//         }
//     }
//     return {name,ans};
// }
// int main()
// {
//     vector<pair<string,int>> v;
//     int n;
//     cin>>n;
//     for(int i=0;i<n;i++)
//     {
//         int t;
//         string s;
//         cin>>s>>t;
//         v.push_back({s,t});
//     }
//     int size=v.size();
//     vector<vector<int>> map_v(size,vector(size,0));
//     int m;
//     cin>>m;
//     for(int i=0;i<m;i++)
//     {
//         string s1,s2;
//         cin>>s1>>s2;
//         int a=0,b=0;
//         while(v[a].first!=s1)a++;
//         while(v[b].first!=s2)b++;
//         map_v[a][b]=1;
//         map_v[b][a]=1;
//     }
//     auto it = func(map_v,v);
//     cout<<it.first<<" "<<it.second;
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// void func_add(string str,set<pair<int,int>>& s)
// {
//     stringstream ss(str);
//     string temp;
//     while(getline(ss,temp,','))
//     {
//         int a=-1,b=-1,x=0;
//         for(int i=0;i<temp.size();i++)
//         {
//             if(temp[i]!='-')x=x*10+(int)(temp[i]-'0');
//             else
//             {
//                 a=x;
//                 x=0;
//             }
//         }
//         if(a==-1)a=x;
//         else b=x;
//         if(b==-1)
//         {
//             int flag=1;
//             for(auto it:s)
//             {
//                 if(it.first<=a&&it.second>=a)
//                 {
//                     flag=0;
//                     break;
//                 }
//             }
//             if(flag)s.insert({a,a});
//         }
//         else
//         {
//             int flag=1;
//             for(auto it:s)
//             {
//                 if(it.first<=a&&it.second>=a)
//                 {
//                     if(it.second>=b)
//                     {
//                         flag=0;
//                         break;
//                     }
//                     pair<int,int> pair_temp={it.first,b};
//                     s.erase(it);
//                     s.insert(pair_temp);
//                     flag=0;
//                     break;
//                 }
//                 else if(it.first>b+1)break;
//             }
//             if(flag)
//             {
//                 pair<int,int> pair_temp={a,b};
//                 s.insert(pair_temp);
//             }
//         }
//     }
//     for(auto it=s.begin();it!=s.end();)
//     {
//         auto next_it=next(it);
//         if(next_it==s.end())break;
//         if((*it).second>=(*next_it).first-1)
//         {
//             pair<int,int> pair_temp={(*it).first,(*next_it).second};
//             s.erase(it);
//             s.erase(next_it);
//             s.insert(pair_temp);
//             it=s.begin();
//             continue;
//         }
//         it++;
//     }
// }
// void func_sub(string str,set<pair<int,int>>& s)
// {
//     if(s.empty())return;
//     stringstream ss(str);
//     string temp;
//     while(getline(ss,temp,','))
//     {
//         int a=-1,b=-1,x=0;
//         for(int i=0;i<temp.size();i++)
//         {
//             if(temp[i]!='-')x=x*10+(int)(temp[i]-'0');
//             else
//             {
//                 a=x;
//                 x=0;
//             }
//         }
//         if(a==-1)a=x;
//         else b=x;
//         if(b==-1)
//         {
//             for(auto it=s.begin();it!=s.end();)
//             {
//                 if((*it).first<a&&a<(*it).second)
//                 {
//                     if((*it).first<=a-1)
//                     {
//                         pair<int,int> pair_temp={(*it).first,a-1};
//                         s.insert(pair_temp);
//                         pair_temp={a+1,(*it).second};
//                         s.insert(pair_temp);
//                     }
//                     s.erase(it);
//                     break;
//                 }
//                 else if((*it).first==a)
//                 {
//                     if((*it).first+1<=(*it).second)
//                     {
//                         pair<int,int> pair_temp={(*it).first+1,(*it).second};
//                         s.insert(pair_temp);
//                     }
//                     s.erase(it);
//                     break;
//                 }
//                 else if((*it).second==a)
//                 {
//                     if((*it).first<=(*it).second-1)
//                     {
//                         pair<int,int> pair_temp={(*it).first,(*it).second-1};
//                         s.insert(pair_temp);
//                     }
//                     s.erase(it);
//                     break;
//                 }
//                 it++;
//             }
//         }
//         else
//         {
//             for(auto it=s.begin();it!=s.end();)
//             {
//                 if((*it).first>b)break;
//                 else if(a<=(*it).first&&(*it).second<=b)
//                 {
//                     s.erase(it);
//                     it=s.begin();
//                     continue;
//                 }
//                 else if(a<=(*it).first&&(*it).first<=b&&b<(*it).second)
//                 {
//                     if(b+1<=(*it).second)
//                     {
//                         pair<int,int> pair_temp={b+1,(*it).second};
//                         s.insert(pair_temp);
//                     }
//                     s.erase(it);
//                     it=s.begin();
//                     continue;
//                 }
//                 else if((*it).first<a&&a<=(*it).second&&(*it).second<=b)
//                 {
//                     if((*it).first<=a-1)
//                     {
//                         pair<int,int> pair_temp={(*it).first,a-1};
//                         s.insert(pair_temp);
//                     }
//                     s.erase(it);
//                     it=s.begin();
//                     continue;
//                 }
//                 else if((*it).first<a&&b<(*it).second)
//                 {
//                     if((*it).first<=a-1)
//                     {
//                         pair<int,int> pair_temp={(*it).first,a-1};
//                         s.insert(pair_temp);
//                         pair_temp={b+1,(*it).second};
//                         s.insert(pair_temp);
//                     }
//                     s.erase(it);
//                     it=s.begin();
//                     continue;
//                 }
//                 it++;
//             }
//         }
//     }
// }
// int main()
// {
//     int n;
//     cin>>n;
//     string str;
//     cin.ignore();
//     set<pair<int,int>> s;
//     for(int i=0;i<n;i++)
//     {
//         getline(cin,str);
//         stringstream ss(str);
//         if(str[0]=='a')
//         {
//             string temp;
//             while(getline(ss,temp,' '))
//             {
//                 if(temp!="undo"&&temp!="algorithm") func_add(temp,s);
//             }
//         }
//         else
//         {
//             string temp;
//             while(getline(ss,temp,' '))
//             {
//                 if(temp!="undo"&&temp!="algorithm") func_sub(temp,s);
//             }
//         }
//     }
//     for(auto it=s.begin();it!=s.end();it++)
//     {
//         if(it!=s.begin())cout<<",";
//         if((*it).first==(*it).second)cout<<(*it).first;
//         else cout<<(*it).first<<"-"<<(*it).second;
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int size=height.size();
        int lptr=0,rptr=size-1,lmax=height[lptr],rmax=height[rptr],ans=0;
        while(lptr<rptr)
        {
            if(lmax>rmax)
            {
                rptr--;
                if(height[rptr]>rmax)rmax=height[rptr];
                else ans+=rmax-height[rptr];
            }
            else 
            {
                lptr++;
                if(height[lptr]>lmax)lmax=height[lptr];
                else ans+=lmax-height[lptr];
            }
        }
        return ans;
    }
};
int main()
{
    cout<<"Hello wordl!"<<endl;
    return 0;
}

// 10
// a 6587
// b 7928
// c 6659
// d 6957
// e 8524
// f 8692
// g 5801
// h 9341
// i 7467
// j 2438
// 8
// b d
// c d
// c f
// c i
// d i
// e j
// g h
// g i


// 2
// algorithm 1-100
// undo algorithm 20,50-60,55-70,72,100