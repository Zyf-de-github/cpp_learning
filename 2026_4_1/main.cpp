#include <bits/stdc++.h>
using namespace std;



int main()
{
    // M_PI
    // int m=1,n=1;
    // vector<vector<pair<int,int>>> v(m,vector<pair<int,int>>(n,{0,0}));
    int n,c,m;
    cin>>n>>c>>m;
    vector v(n,vector(4,0));
    for (int i=0;i<n;i++)
    {
        int ci,mi,vi;
        cin>>ci>>mi>>vi;
        v.push_back({1,ci,mi,vi});//是否选择 cpu 内存 价值
    }
    vector dp(n,vector(c,vector(m,vector<vector<int>>{})));


    return 0;
}

// int main()
// {
//     int n,m;
//     vector<int> t,b;
//     cin>>n>>m;
//     for (int i=0;i<n;i++)
//     {
//         int x;
//         cin>>x;
//         t.push_back(x);
//     }
//     for (int i=0;i<n;i++)
//     {
//         int x;
//         cin>>x;
//         b.push_back(x);
//     }
//
//     priority_queue<pair<int,int>> q;
//     for  (int i=0;i<n;i++)
//     {
//         int temp = t[i]-max(t[i]%2==1?t[i]/2+1:t[i]/2,b[i]);
//         q.push(make_pair(temp,i));
//         t[i]-=temp;
//     }
//
//     for (int i=0;i<m;i++)
//     {
//         auto it=q.top();
//         q.pop();
//         int temp = t[it.second]-max(t[it.second]%2?t[it.second]/2+1:t[it.second]/2,b[it.second]);
//         q.push(make_pair(temp,it.second));
//         t[it.second]-=temp;
//     }
//
//     int sum=0;
//     while (q.empty()==false)
//     {
//         sum+=q.top().first;
//         q.pop();
//     }
//     for (int i=0;i<n;i++)sum+=t[i];
//     cout<<sum<<endl;
//     return 0;
// }





// int main()
// {
//     int n;
//     vector<int> v,b;
//     cin>>n;
//     if (n<0)v.push_back(1);
//     else v.push_back(0);
//
//     string str,temp;
//     getline(cin,str);
//     getline(cin,str);
//     stringstream ss(str);
//     while (ss>>temp)b.push_back(stoi(temp));
//
//     n=abs(n);
//     for (auto it:b)
//     {
//         v.push_back(n%it);
//         n/=it;
//     }
//
//     string ans;
//     for (int i=0;i<v.size();i++)
//     {
//         char l = char(v[i]+'a');
//         ans=ans+l;
//     }
//
//     int x_max=-1;
//     vector<string> x;
//     for (int i=0;i<ans.size();i++)
//     {
//         int temp=0;
//         while (i-temp>=0&&i+temp<ans.size()&&ans[i-1-temp]==ans[i+1+temp]){if (i+1+temp==ans.size())break;temp++;}
//         if (temp>x_max)
//         {
//             x_max=temp;
//             x.clear();
//             x.push_back(ans.substr(i-temp,2*temp+1));
//         }
//         else if (temp==x_max)x.push_back(ans.substr(i-temp,2*temp+1));
//     }
//     sort(x.begin(),x.end());
//
//     int y_max=-1;
//     vector<string> y;
//     for (int i=0;i<ans.size();i++)
//     {
//         int temp=0;
//         while (i-temp>=0&&i+1+temp<ans.size()&&ans[i-temp]==ans[i+1+temp]){if (i+1+temp==ans.size())break;temp++;}
//         if (temp>y_max)
//         {
//             y_max=temp;
//             y.clear();
//             y.push_back(ans.substr(i+1-temp,2*temp));
//         }
//         else if (temp==y_max)y.push_back(ans.substr(i+1-temp,2*temp));
//     }
//     sort(y.begin(),y.end());
//     if (x_max*2+1>y_max*2)
//     {
//         cout<<x[0];
//         if (x[0].size()==ans.size())cout<<"(palindrome)";
//     }
//     else
//     {
//         cout<<y[0];
//         if (y[0].size()==ans.size())cout<<"(palindrome)";
//     }
//     return 0;
// }
// 0
// 17 3 23 5 15 14 11 2

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



