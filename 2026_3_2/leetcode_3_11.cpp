#include <bits/stdc++.h>
using namespace std;

class Solution2 {
public:
    int numberOfWays(int n, int x) {
        vector<long long> f(n + 1);
        f[0] = 1;
        // 本题数据范围小，pow 的计算结果一定准确
        for (int i = 1; pow(i, x) <= n; i++) {
            int v = pow(i, x);
            for (int s = n; s >= v; s--) {
                f[s] += f[s - v];
            }
            int a=0;
        }
        return f[n] % 1'000'000'007;
    }
};
class Solution1 {
public:
    int numberOfWays(int n, int x) {
        vector<vector<long long>>dp(n+1,vector<long long>(n+1));
        dp[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            long long val=(long long)pow(i,x);
            for(int j=0;j<=n;j++)
            {
                dp[i][j]=dp[i-1][j];
                if(j-val>=0)dp[i][j]=(dp[i][j]+dp[i-1][j-val])%1000000007;
            }
        }
        return dp[n][n];
    }
};
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int size=nums.size();
        vector<int>dp(target+1);
        dp[0]=1;
        for(int i=0;i<=target;i++)
        {
            for(int j=0;j<size;j++)
            {
                if(i-nums[j]>=0)dp[i]+=dp[i-nums[j]];
            }
        }
        return dp[target];
    }
};
int main()
{
    Solution s;
    vector<int> a={1,2,3};
    s.combinationSum4(a,4);
    return 0;
}