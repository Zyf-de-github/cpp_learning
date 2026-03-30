// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//     vector<pair<int,int>> v;
//     int n,k;
//     cin>>n>>k;
//     for (int i=0;i<n;i++) {
//         int x,y;
//         cin>>x>>y;
//         v.push_back({x,y});
//     }
//     // sort(v.begin(),v.end(),[&](pair<int, int> a,pair<int, int> b) {
//     //     return a.first>b.first;
//     // });
//     //max(dp[i][j-cost]+current,dp[i-1][j])
//     vector dp(n+1,vector(k+1,pair<int,vector<int>>(0,0)));
//     for (int i=1;i<=n;i++) {
//         for (int j=0;j<=k;j++) {
//             if (j-v[i-1].first>=0 && dp[i-1][j-v[i-1].first].first+v[i-1].second>=dp[i-1][j].first) {
//                 dp[i][j].first=dp[i-1][j-v[i-1].first].first+v[i-1].second;
//                 dp[i][j].second=dp[i-1][j-v[i-1].first].second;
//                 dp[i][j].second.push_back(i);
//                 if (dp[i-1][j-v[i-1].first].first+v[i-1].second==dp[i-1][j].first&&
//                     dp[i][j].second.size()>dp[i-1][j].second.size()) {
//                     dp[i][j].second=dp[i-1][j].second;
//                 }
//             }
//             else {
//                 if (i!=0) {
//                     dp[i][j].first=dp[i-1][j].first;
//                     dp[i][j].second=dp[i-1][j].second;
//                 }
//             }
//         }
//     }
//     int recorder=0;
//     if (dp[n][k].second.empty()) {cout<<-1; return 0;}
//     for (int i=k;i>0;i--) {
//         if (dp[n][i].first>dp[n][i-1].first){recorder=i;break;}
//     }
//     for (auto it:dp[n][recorder].second) {
//         cout<<it<<" ";
//     }
//     return 0;
// }
//
//
// // 5
// // 16
// // 6 40
// // 9 47
// // 3 20
// // 3 20
// // 16 87



#include <bits/stdc++.h>
using namespace std;
#define NUM 1000000007
class Solution1 {
public:
    int waysToReachTarget(int target, vector<vector<int>> types) {
        int n=types.size();
        vector dp(n+1, vector(target+1,0));
        dp[0][0]=1;
        for (int i=1;i<=n;i++) {
            for (int j=0;j<=target;j++) {
                if (j==0) {dp[i][j]=1;continue;}
                for (int k=0;k<=types[i-1][0];k++) {
                    if (j-k*types[i-1][1]>=0) {
                        dp[i][j]+=dp[i-1][j-k*types[i-1][1]];
                        dp[i][j]%=NUM;
                    }
                }
            }
        }
        return dp[n][target];
    }
};
class Solution2 {
public:
    int minimizeTheDifference(vector<vector<int>> mat, int target) {
        int m=mat.size(),n=mat[0].size();
        vector dp(m,vector(2500,0));
        for (int i=0;i<n;i++)dp[0][mat[0][i]]=1;
        for (int i=1;i<m;i++) {
            for (int j=0;j<=1600;j++) {
                if (dp[i-1][j]!=0) {
                    for (int k=0;k<n;k++) {if (j+mat[i][k]<1601)dp[i][j+mat[i][k]]=1;}
                }
            }
        }
        int ans=INT_MAX;
        for (int i=target;i<1601;i++) {
            if (dp[m-1][i]!=0) {
                ans=abs(target-i);
                break;
            }
        }
        for (int i=target;i>=0;i--) {
            if (dp[m-1][i]!=0) {
                ans=min(ans,abs(target-i));
                break;
            }
        }
        return ans;
    }
};
int main() {
    Solution s;
    s.minimizeTheDifference({{1,2,3},{4,5,6},{7,8,9}},13);

    return 0;
}