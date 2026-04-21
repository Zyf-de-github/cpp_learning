// #include <bits/stdc++.h>
// using namespace std;
// class Solution1
// {
// public:
//     int trap(vector<int> &height)
//     {
//         int size = height.size();
//         int lptr = 0, rptr = size - 1, lmax = height[lptr], rmax = height[rptr], ans = 0;
//         while (lptr < rptr)
//         {
//             if (lmax > rmax)
//             {
//                 rptr--;
//                 if (height[rptr] > rmax)
//                     rmax = height[rptr];
//                 else
//                     ans += rmax - height[rptr];
//             }
//             else
//             {
//                 lptr++;
//                 if (height[lptr] > lmax)
//                     lmax = height[lptr];
//                 else
//                     ans += lmax - height[lptr];
//             }
//         }
//         return ans;
//     }
// };
// class Solution 
// {
// public:
//     int ans_max=0,ans_num=0;
//     set<vector<int>> s;
//     vector<vector<string>> solveNQueens(int n)
//     {
//         vector<int> v(n,-255);
//         for(int i=0;i<n;i++)
//         {
//             v[0]=i;
//             dfs(v,1,1);
//         }
//         vector<vector<string>> x;
//         if(ans_max!=n)return x;
//         for(auto it:s)
//         {
//             vector<string> temp;
//             for(int i=0;i<n;i++)
//             {
//                 string str;
//                 for(int j=0;j<n;j++)
//                 {
//                     if(it[i]==j)str=str+"Q";
//                     else str=str+".";
//                 }
//                 temp.push_back(str);
//             }
//             x.push_back(temp);
//         }
//         return x;
//     }
//     void dfs(vector<int> v,int i,int ans)
//     {
//         if(ans>ans_max)
//         {
//             s.clear();
//             s.insert(v);
//             ans_max=ans;
//             ans_num=1;
//         }
//         else if(ans==ans_max)
//         {
//             s.insert(v);
//             ans_num++;
//         }
//         if(i>=v.size())return;
//         set<int> s_len,left_len,right_len;
//         for(int j=0;j<v.size();j++)
//         {
//             if(v[j]!=-255)
//             {
//                 s_len.insert(v[j]);
//                 left_len.insert(v[j]+j);
//                 right_len.insert(j-v[j]);
//             }
//         }
//         for(int j=0;j<v.size();j++)
//         {
//             if(s_len.find(j)==s_len.end()&&
//                left_len.find(i+j)==left_len.end()&&
//                right_len.find(i-j)==right_len.end())
//             {
//                 v[i]=j;
//                 dfs(v,i+1,ans+1);
//                 v[i]=-255;
//             }
//         }
//         dfs(v,i+1,ans);
//     }
// };
// int main()
// {
//     Solution s;
//     s.solveNQueens(2);
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// int func(vector<int>& v,int begin,int end)
// {
//     if(end-begin==1)return 1;
//     else if(end-begin==2)
//     {
//         if(v[begin]==v[begin+1])return 2;
//         return 3;
//     }
//     vector<int>num,ptr;
//     int cur=1,state=0,begin_state;
//     ptr.push_back(0);
//     num.push_back(cur);
//     for(int i=begin+1;i<end;i++)
//     {
//         if(state==1&&v[i]<v[i-1])
//         {
//             ptr.push_back(i-1-begin);
//             state=-1;
//         }
//         else if(state==-1&&v[i]>v[i-1])
//         {
//             ptr.push_back(i-1-begin);
//             state=1;
//         }
//         else if(state==0)
//         {
//             if(v[i]>v[i-1])state=1,begin_state=1;
//             else if(v[i]<v[i-1])state=-1,begin_state=-1;
//         }
//         if(v[i]>v[i-1])num.push_back(++cur);
//         else if(v[i]==v[i-1])num.push_back(cur);
//         else num.push_back(--cur);
//     }
//     ptr.push_back(end-1-begin);
//     for(int i=0;i<ptr.size();i++)
//     {
//         if(begin_state==1)
//         {
//             int temp=1-num[ptr[i]];
//             if(i+1<ptr.size()){for(int j=ptr[i]+1;j<=ptr[i+1];j++)num[j]+=temp;}
//             if(i-1>=0){for(int j=ptr[i]-1;j>=ptr[i-1];j--)num[j]+=temp;}
//             num[ptr[i]]=1;
//             i++;
//         }
//         else
//         {
//             i++;
//             if(i>=ptr.size())break;
//             int temp=1-num[ptr[i]];
//             if(i+1<ptr.size())for(int j=ptr[i]+1;j<=ptr[i+1];j++)num[j]+=temp;
//             if(i-1>=0)for(int j=ptr[i]-1;j>=ptr[i-1];j--)num[j]+=temp;
//             num[ptr[i]]=1;
//         }
//     }
//     int ans=0;
//     for(int i=0;i<ptr.size();i++)
//     {
//         if(begin_state==1)
//         {
//             i++;
//             if(i>=ptr.size())break;
//             if(ptr[i]-1>0&&ptr[i]+1<num.size())num[ptr[i]]=max(num[ptr[i]+1],num[ptr[i]-1])+1;
//             else if(ptr[i]-1<0) num[ptr[i]]=num[ptr[i]+1]+1;
//             else if(ptr[i]+1>=num.size()) num[ptr[i]]=num[ptr[i]-1]+1;
//         }
//         else
//         {
//             if(ptr[i]-1>0&&ptr[i]+1<num.size())num[ptr[i]]=max(num[ptr[i]+1],num[ptr[i]-1])+1;
//             else if(ptr[i]-1<0) num[ptr[i]]=num[ptr[i]+1]+1;
//             else if(ptr[i]+1>=num.size()) num[ptr[i]]=num[ptr[i]-1]+1;
//             i++;
//         }
//     }
//     for(auto it:num)ans+=it;
//     return ans;
// }
// int main()
// {
//     string str,temp;
//     getline(cin,str);
//     stringstream ss(str);
//     vector<int> v;
//     int begin=-1,ans=0;
//     while(getline(ss,temp,','))v.push_back(stoi(temp));
//     for(int i=0;i<v.size();i++)
//     {
//         if(v[i]<=0&&begin!=-1)
//         {
//             ans+=func(v,begin,i);
//             begin=-1;
//         }
//         else if(begin==-1)begin=i;
//     }
//     if(begin!=-1)ans+=func(v,begin,v.size());
//     cout<<ans;
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     string s;
//     map<string,tuple<int,int,int,int,int,int>>m;//level-num-w-h-x-y
//     int num=0;
//     vector<vector<string>>v;
//     set<pair<int,string>> set_;
//     set<tuple<int,int,int,int,int,int,string>> set__;//level-num-w-h-x-y-name
//     int w=0,h=0;
//     while(getline(cin,s))
//     {
//         stringstream ss(s);
//         string str;
//         int state;
//         string s1,s2,s3,s4,s5,s6;
//         int para=-1;
//         while(getline(ss,str,' '))
//         {
//             if(para==-1)
//             {
//                 if(str=="init")state=0;
//                 else if(str=="createWindow")state=1;
//                 else if(str=="removeWindow")state=2;
//                 else if(str=="resize")state=3;
//                 else if(str=="move")state=4;
//                 else if(str=="queryVisibility")state=5;
//                 else if(str=="queryAllVisibleWindows")state=6;
//                 para++;
//             }
//             else if(para==0){s1=str;para++;}
//             else if(para==1){s2=str;para++;}
//             else if(para==2){s3=str;para++;}
//             else if(para==3){s4=str;para++;}
//             else if(para==4){s5=str;para++;}
//             else if(para==5){s6=str;para++;}
//         }
//         switch(state)
//         {
//         case 0:
//             if(stoi(s1)<=0||stoi(s2)<=0)cout<<"false"<<endl;
//             else 
//             {
//                 w=stoi(s1);
//                 h=stoi(s2);
//                 cout<<"true"<<endl;
//             }
//         break;
//         case 1:
//             if(m.find(s1)!=m.end())cout<<"false"<<endl;
//             else
//             {
//                 if(para==6)
//                 {
//                     if(stoi(s4)<=0||stoi(s5)<=0)
//                     {
//                         cout<<"false"<<endl;
//                         break;
//                     }
//                     m[s1]={stoi(s6),num++,stoi(s4),stoi(s5),stoi(s2),stoi(s3)};
//                 }
//                 else if(para==5)
//                 {
//                     if(stoi(s4)<=0)
//                     {
//                         cout<<"false"<<endl;
//                         break;
//                     }
//                     m[s1]={stoi(s5),num++,stoi(s4),stoi(s4),stoi(s2),stoi(s3)};
//                 }
//                 cout<<"true"<<endl;
//             }
//         break;
//         case 2:
//             if(m.find(s1)==m.end())cout<<"false"<<endl;
//             else 
//             {
//                 m.erase(s1);
//                 cout<<"true"<<endl;
//             }
//         break;
//         case 3:
//             if(stoi(s2)<=0||stoi(s3)<=0||m.find(s1)==m.end())cout<<"false"<<endl;
//             else
//             {
//                 get<2>(m[s1])=stoi(s2);
//                 get<3>(m[s1])=stoi(s3);
//                 cout<<"true"<<endl;
//             }
//         break;
//         case 4:
//             if(m.find(s1)==m.end())cout<<"false"<<endl;
//             else
//             {
//                 get<4>(m[s1])=stoi(s2);
//                 get<5>(m[s1])=stoi(s3);
//                 cout<<"true"<<endl;
//             }
//         break;
//         case 5:
//             if(w<=0||h<=0)cout<<"false"<<endl;
//             else
//             {
//                 v.assign(h+1,vector<string>(w+1,"NULL"));
//                 set__.clear();//level-num-w-h-x-y-name
//                 for(auto it=m.begin();it!=m.end();it++)
//                 {
//                     set__.insert({-get<0>(it->second),
//                                 -get<1>(it->second),
//                                 get<2>(it->second),
//                                 get<3>(it->second),
//                                 get<4>(it->second),
//                                 get<5>(it->second),
//                                 it->first});
//                 }
//                 for(auto it=set__.begin();it!=set__.end();it++)
//                 {
//                     for(int i=get<5>(*it);i<=get<5>(*it)+get<3>(*it);i++)
//                     {
//                         for(int j=get<4>(*it);j<=get<4>(*it)+get<2>(*it);j++)
//                         {
//                             if(0<=i&&i<=h&&0<=j&&j<=w&&v[i][j]=="NULL")v[i][j]=get<6>(*it);
//                         }
//                     }
//                 }
//                 for(int i=0;i<=h;i++)
//                 {
//                     for(int j=0;j<=w;j++)
//                     {
//                         if(v[i][j]==s1)
//                         {
//                             cout<<"true"<<endl;
//                             goto out;
//                         }
//                     }
//                 }
//                 cout<<"false"<<endl;
//                 out:;
//             }
//         break;
//         case 6:
//             if(w<=0||h<=0)cout<<"false"<<endl;
//             else
//             {
//                 v.assign(h+1,vector<string>(w+1,"NULL"));
//                 set__.clear();//level-num-w-h-x-y-name
//                 set_.clear();
//                 for(auto it=m.begin();it!=m.end();it++)
//                 {
//                     set__.insert({-get<0>(it->second),
//                                 -get<1>(it->second),
//                                 get<2>(it->second),
//                                 get<3>(it->second),
//                                 get<4>(it->second),
//                                 get<5>(it->second),
//                                 it->first});
//                 }
//                 for(auto it=set__.begin();it!=set__.end();it++)
//                 {
//                     for(int i=get<5>(*it);i<=get<5>(*it)+get<3>(*it);i++)
//                     {
//                         for(int j=get<4>(*it);j<=get<4>(*it)+get<2>(*it);j++)
//                         {
//                             if(0<=i&&i<=h&&0<=j&&j<=w&&v[i][j]=="NULL")v[i][j]=get<6>(*it);
//                         }
//                     }
//                 }
//                 for(int i=max(0,stoi(s2));i<=min(h,stoi(s2)+stoi(s4));i++)
//                 {
//                     for(int j=max(0,stoi(s1));j<=min(w,stoi(s1)+stoi(s3));j++)
//                     {
//                         if(v[i][j]!="NULL")set_.insert({-get<0>(m[v[i][j]]),v[i][j]});
//                     }
//                 }
//                 if(set_.empty())cout<<"NoVisibleWindow"<<endl;
//                 else
//                 {
//                     for(auto it=set_.begin();it!=set_.end();it++)
//                     {
//                         if(it==set_.begin())cout<<it->second;
//                         else cout<<";"<<it->second;
//                     }
//                     cout<<endl;
//                 }
//             }
//         break;
//         default:
//         break;
//         }
//     }
//     return 0;
// }
// init 200 300
// createWindow window1 10 10 100 100 1
// createWindow window2 20 20 40 30 2
// createWindow window3 70 90 50 3
// removeWindow window2
// removeWindow window4
// queryVisibility window1
// queryAllVisibleWindows 10 10 100 100