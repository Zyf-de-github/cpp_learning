#include <bits/stdc++.h>
using namespace std;



// int main()
// {
//     int n,t,m;//num,total cost,max chose
//     cin>>n>>t>>m;
//     vector<pair<int,int>> gold;//time,val
//     for(int i=0;i<n;i++)
//     {
//         int temp1,temp2;
//         cin>>temp1>>temp2;
//         gold.push_back(make_pair(temp1,temp2));
//     }
//     vector v(t+1,vector(n+1,vector(m+1,0)));
//     for (int i=0;i<=t;i++)//价值
//     {
//         for (int j=1;j<=n;j++)//选到第几个
//         {
//             if (gold[j-1].first>30)
//             {
//                 for (int k=0;k<=m;k++)//选了多少大型
//                 {
//                     if (k==0)v[i][j][k]=v[i][j-1][k];
//                     else v[i][j][k]=max(v[i][j-1][k],(i-gold[j-1].first)<0?0:(v[i-gold[j-1].first][j-1][k-1]+gold[j-1].second));
//                 }
//             }
//             else
//             {
//                 for (int k=0;k<=m;k++)//选了多少大型
//                 {
//                     if (k==0)v[i][j][k]=max(v[i][j-1][k],(i-gold[j-1].first)<0?0:(v[i-gold[j-1].first][j-1][k]+gold[j-1].second));
//                     if (k!=0&&i-gold[j-1].first>=0&&v[i-gold[j-1].first][j-1][k]!=0)v[i][j][k]=max(v[i][j-1][k],(i-gold[j-1].first)<0?0:(v[i-gold[j-1].first][j-1][k]+gold[j-1].second));
//                     // v[i][j][k]=max(v[i][j-1][k],(i-gold[j-1].first)<0?0:(v[i-gold[j-1].first][j-1][k]+gold[j-1].second));
//                  }
//             }
//         }
//     }
//     int ans=0;
//     for (int i=0;i<=m;i++)
//     {
//         ans=max(ans,v[t][n][i]);
//     }
//     cout<<ans<<endl;
//     return 0;
// }
// 4 20 1
// 4 50
// 7 60
// 5 30
// 8 70

// int main()
// {
//     int n;
//     cin>>n;
//     float temp;
//     vector<float> dist,speed,time;
//     for (int i=0;i<n;i++)
//     {
//         cin>>temp;
//         dist.push_back(temp);
//     }
//     for (int i=0;i<n;i++)
//     {
//         cin>>temp;
//         speed.push_back(temp);
//         time.push_back(dist[i]/speed[i]);
//     }
//     sort(time.begin(),time.end());
//     int ans=0;
//     for (int i=0;i<n;i++)
//     {
//         if (time[i]<=i)break;
//         ans++;
//     }
//     cout<<ans<<endl;
//     return 0;
// }

// int main()
// {
//     map<int,pair<int,int>> mp;//id,时间戳，次数
//     int n;
//     string temp;
//     getline(cin,temp);
//     stringstream x(temp);
//     x>>n;
//     for (int i=0;i<n;i++)
//     {
//         string str;
//         getline(cin,str);
//         stringstream ss(str);
//         int num;
//         while (ss>>num)
//         {
//             int temp;
//             ss>>temp;
//             if (mp.find(num)==mp.end())mp[num]=make_pair(temp,1);
//             else mp[num].second++;
//         }
//     }
//     vector<tuple<int,int,int>> v;
//     for (auto it : mp)
//     {
//         if (it.second.second!=1)
//             v.push_back(make_tuple(it.second.first,it.first,it.second.second));
//     }
//     sort(v.begin(),v.end(),[&](tuple<int,int,int> a,tuple<int,int,int> b){
//         return get<0>(a)<get<0>(b);
//     });
//     for (auto it : v)
//     {
//         cout<<get<1>(it)<<" "<<get<2>(it)<<" ";
//     }
//     return 0;
// }
// 4
// 999 1 998 2 997 3 996 4 995 5
// 994 6 993 7 992 8 991 9 990 10
// 989 11 988 12 987 13
// 999 1 995 5 986 14



