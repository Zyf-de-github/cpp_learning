// #include <bits/stdc++.h>
// using namespace std;
//
// vector<pair<int,int>> func(vector<int> &v,int lptr,int rptr,int &ans_length)
// {
//     int i=lptr;
//     set<int> s;
//     vector<pair<int,int>> ans;
//     while (i<=rptr)
//     {
//         s.insert(v[i]);
//         int max_num=*s.rbegin();
//         int min_num=*s.begin();
//         if (max_num-min_num<=4)
//         {
//             if (i-lptr>ans_length)
//             {
//                 ans.clear();
//                 ans_length=i-lptr;
//             }
//             if (i-lptr>=ans_length)ans.push_back(make_pair(lptr,i));
//         }
//         else
//         {
//             s.erase(v[lptr]);
//             lptr++;
//         }
//         i++;
//     }
//     return ans;
// }
// int main()
// {
//     int n;
//     cin>>n;
//     vector<int> v(n+1);
//     vector<pair<int,int>> ans;
//     int ans_length=0;
//     for (int i=0;i<n;i++)cin>>v[i];
//     v[n]=0;
//     int lptr=-1,rptr=0;
//     while (rptr<=n)
//     {
//         if (v[rptr]>24||v[rptr]<18)
//         {
//             if (lptr!=-1)
//             {
//                 vector<pair<int,int>> temp=func(v,lptr,rptr-1,ans_length);
//                 if (!ans.empty()&&ans[0].second-ans[0].first<ans_length)ans.clear();
//                 for (auto it:temp)ans.push_back(it);
//             }
//             lptr=-1;
//             rptr++;
//         }
//         else
//         {
//             if (lptr==-1)lptr=rptr;
//             rptr++;
//         }
//     }
//     for (auto it:ans)cout<<it.first<<" "<<it.second<<endl;
//     return 0;
// }



// #include <bits/stdc++.h>
// using namespace std;
//
//
// int func(int times,string x,string be_test)
// {
//     int m=x.size(),n=be_test.size();
//     vector<vector<int>> dp(m+1,vector(n+1,0));
//     for(int i=0;i<=m;i++)
//     {
//         dp[i][0]=i;
//     }
//     for(int i=0;i<=n;i++)
//     {
//         dp[0][i]=i;
//     }
//     for(int i=1;i<=m;i++)
//     {
//         for(int j=1;j<=n;j++)
//         {
//             dp[i][j]=x[i-1]==be_test[j-1]?dp[i-1][j-1]:min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]})+1;
//         }
//     }
//     return dp[m][n]>times?-1:dp[m][n];
// }
//
// int main()
// {
//     int D,n;
//     cin>>D;
//     cin>>n;
//     vector<string> s(n);
//     vector<set<string>>ans(6,set<string>());
//     for(int i=0;i<n;i++)
//     {
//         string temp;
//         cin>>temp;
//         s[i]=temp;
//     }
//     string be_test;
//     cin>>be_test;
//     for (auto it:s)
//     {
//         int x = func(D,it,be_test);
//         if (x!=-1)ans[x].insert(it);
//     }
//     if (ans.empty())cout<<"None";
//     else
//     {
//         if (ans[0].empty()&&
//             ans[1].empty()&&
//             ans[2].empty()&&
//             ans[3].empty()&&
//             ans[4].empty()&&
//             ans[5].empty())cout<<"None";
//         else if (!ans[0].empty())cout<<*ans[0].begin();
//         else
//         {
//             for (int i=1;i<=5;i++)
//             {
//                 for (auto it:ans[i])cout<<it<<" ";
//             }
//         }
//     }
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;
int main()
{

    return 0;
}