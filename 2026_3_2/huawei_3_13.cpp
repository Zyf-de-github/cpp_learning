// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;
//
//
// class task
// {
// private:
//     vector<vector<char>> v;
//     int x=0,y=0;
//     int begin_x=-1,begin_y=-1,super_x1=-1,super_y1=-1,super_x2=-1,super_y2=-1;
//     void dfs(vector<vector<char>> v,int x,int y,int total)
//     {
//         if (v[x][y]=='E')ans=min(total,ans);
//         if (make_pair(x,y)==make_pair(super_x1,super_y1)&&v[x][y]=='2')
//         {
//             v[x][y]='1';
//             v[super_x2][super_y2]='1';
//             dfs(v,super_x2,super_y2,total);
//         }
//         if (make_pair(x,y)==make_pair(super_x2,super_y2)&&v[x][y]=='2')
//         {
//             v[x][y]='1';
//             v[super_x1][super_y1]='1';
//             dfs(v,super_x1,super_y1,total);
//         }
//         if (x-1>=0&&v[x-1][y]!='1')
//         {
//             v[x][y]='1';
//             dfs(v,x-1,y,total+1);
//         }
//         if (x+1<this->x&&v[x+1][y]!='1')
//         {
//             v[x][y]='1';
//             dfs(v,x+1,y,total+1);
//         }
//         if (y-1>=0&&v[x][y-1]!='1')
//         {
//             v[x][y]='1';
//             dfs(v,x,y-1,total+1);
//         }
//         if (y+1<this->y&&v[x][y+1]!='1')
//         {
//             v[x][y]='1';
//             dfs(v,x,y+1,total+1);
//         }
//     }
//
// public:
//     int ans=INT_MAX;
//     void task_init()
//     {
//         char temp;
//         cin>>x>>y;
//         v.resize(x,vector<char>(y));
//         int times=0;
//         for(int i=0;i<x;i++)
//         {
//             for(int j=0;j<y;j++)
//             {
//                 cin>>temp;
//                 v[i][j]=temp;
//                 if (temp=='S')begin_x=i,begin_y=j;
//                 if (temp=='2'&&times==0)super_x1=i,super_y1=j,times++;
//                 else if (temp=='2'&&times==1)super_x2=i,super_y2=j,times++;
//             }
//         }
//         dfs(v,begin_x,begin_y,0);
//     }
// };
// int main() {
//
//     task t;
//     t.task_init();
//     cout<<t.ans<<endl;
//     return 0;
// }
// // 64 位输出请用 printf("%lld")




// #include <bits/stdc++.h>
// using namespace std;
//
// int main()
// {
//     // map<char,int>m;
//     // string s,ans;
//     // cin>>s;
//     // for (auto it:s)
//     // {
//     //     m[it]++;
//     // }
//     // for (int i=48;i<=57;i++)
//     // {
//     //     if (m.find((char)i)!=m.end())
//     //     {
//     //         int x=m[(char)i];
//     //         for (int j=0;j<x;j++)
//     //         {
//     //             ans=ans+(char)(i);
//     //         }
//     //     }
//     // }
//     // for (int i=65;i<=90;i++)
//     // {
//     //     if (m.find((char)i)!=m.end())
//     //     {
//     //         int x=m[(char)i];
//     //         for (int j=0;j<x;j++)
//     //         {
//     //             ans=ans+(char)(i);
//     //         }
//     //     }
//     // }
//     // for (int i=97;i<=122;i++)
//     // {
//     //     if (m.find((char)i)!=m.end())
//     //     {
//     //         int x=m[(char)i];
//     //         for (int j=0;j<x;j++)
//     //         {
//     //             ans=ans+(char)(i+'0');
//     //         }
//     //     }
//     // }
//     // cout<<ans<<endl;
//     string s;
//     cin>>s;
//     sort(s.begin(), s.end(),[&](char a,char b)
//     {
//         return a<b;
//     });
//     cout<<s<<endl;
//     return 0;
// }



// #include <bits/stdc++.h>
// using namespace std;
//
// class task
// {
// private:
//     vector<int> ans;
//     int m,n;
//
// public:
//     void calculate()
//     {
//         cin>>m>>n;
//
//
//
//     }
//
//
//
// };
//
// int main()
// {
//     task t;
//     int n;
//     cin>>n;
//     for (int i=0;i<n;i++)
//     {
//         t.calculate();
//     }
//     return 0;
// }





// #include <bits/stdc++.h>
// using namespace std;
//
//
// int main()
// {
//     long long m,n,t;
//     long long ans=LONG_LONG_MAX;
//     cin>>n>>m;
//     vector<long long> v;
//     for (int i=0;i<n;i++)
//     {
//         cin>>t;
//         v.push_back(t);
//     }
//     sort(v.begin(), v.end(),[&](long long a,long long b)
//     {
//         return a<b;
//     });
//     for (int i=0;i+m-1<n;i++)
//     {
//         ans=min((v[m-1+i]+v[i])*(v[m-1+i]-v[i]),ans);
//     }
//     cout<<ans<<endl;
//     return 0;
// }