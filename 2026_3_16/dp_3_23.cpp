#include <bits/stdc++.h>
#define NUM 1000000007
using namespace std;

class Solution11 {
public:
    // int maximumCostSubstring(string s, string chars, vector<int>& vals) {
    //     map<char,int> m;
    //     int s_size=s.size(),chars_size=chars.size();
    //     for (int i=0;i<chars_size;i++) m[chars[i]] = vals[i];
    //     vector<vector<int>> dp(s_size, vector<int>(s_size+1, 0));
    //     int max_num=0;
    //     for (int i=0;i<s_size;i++) {
    //         for (int j=0;j<=s_size;j++) {
    //             if (j<=i)continue;;
    //             if (i==0)dp[i][j]=dp[i][j-1] + (m.find(s[j-1])!=m.end()?m[s[j-1]]:s[j-1]-'a'+1);
    //             else dp[i][j]=dp[i-1][j] - (m.find(s[i-1])!=m.end()?m[s[i-1]]:s[i-1]-'a'+1);
    //             max_num=max(max_num,dp[i][j]);
    //         }
    //     }
    //     return max_num;
    // }
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        map<char,int> m;
        int s_size=s.size(),chars_size=chars.size();
        for (int i=0;i<chars_size;i++) m[chars[i]] = vals[i];
        int ans=0,temp=0;
        for (int i=0;i<s_size;i++) {
            temp=max(temp + (m.find(s[i])==m.end()?s[i]-'a'+1:m[s[i]]),0);
            ans=max(temp,ans);
        }
        return ans;
    }
};
class Solution12 {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int nums_size=nums.size();
        int min_num=0,max_num=0,min_ans=0,max_ans=0;
        for (int i=0;i<nums_size;i++) {
            min_num=min(0,min_num+nums[i]);
            max_num=max(0,max_num+nums[i]);
            min_ans=min(min_num,min_ans);
            max_ans=max(max_num,max_ans);
        }
        return -min_ans>max_ans ? -min_ans : max_ans;
    }
};
class Solution13 {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        if (k<3) return k_times(arr,k);
        else {
            long long ans=k_times(arr,2);
            int x=k_times(arr,2);
            vector<long long> v(arr.size()+1,0);
            for (int i=1;i<=arr.size();i++) v[i]=v[i-1]+arr[i-1];
            int size_v=v.size();
            if (v[size_v-1]>0)for (int i=0;i<k-2;i++) ans=(ans+v[size_v-1])%NUM;
            return ans;
        }
    }
    int k_times(vector<int>& arr, int k) {
        int arr_size=arr.size();
        long long x=(long long)arr_size*(long long)k;
        int num=0,num_max=0,jinwei=0,jinwei_max=0;
        for (long long i=0;i<x;i++) {
            int temp = num+arr[(int)(i%arr_size)];
            while (temp>=NUM) {
                temp-=NUM;
                jinwei++;
            }
            while (temp<0&&jinwei>0) {
                temp+=NUM;
                jinwei--;
            }
            if (temp>=NUM) {
                int a=1;
            }
            num=max(0,temp);
            if (jinwei_max==jinwei) {
                jinwei_max=jinwei;
                num_max=max(num,num_max);
            }
            else if (jinwei_max<jinwei) {
                jinwei_max=jinwei;
                num_max=num;
            }
        }
        return num_max;
    }
};
class Solution14 {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int nums_size=nums.size();
        int min_num=0,max_num=0,min_ans=0,max_ans=0,max_nums=nums[0],total=0;
        for (int i=0;i<nums_size;i++) {
            min_num=min(0,min_num+nums[i]);
            max_num=max(0,max_num+nums[i]);
            min_ans=min(min_num,min_ans);
            max_ans=max(max_num,max_ans);
            max_nums=max(max_nums,nums[i]);
            total+=nums[i];
        }
        return max_nums<0?max_nums:max(total-min_ans,max_ans);
    }
};
class Solution15 {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for (auto it:nums)sum+=it;
        if (sum%2)return false;
        sum/=2;
        vector<vector<bool>> memo(nums.size()+1,vector<bool>(sum+1,false));
        memo[0][0]=true;
        for (int i=0;i<nums.size();i++)
        {
            for (int j=0;j<=sum;j++)
            {
                memo[i+1][j]=(j-nums[i]>=0)&&memo[i][j-nums[i]]||memo[i][j];
            }
        }
        return memo[nums.size()][sum];
    }
};
class Solution16 {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for (auto it:nums)sum+=it;
        sum+=target;
        if (sum<0)sum=sum-target-target;
        if (sum%2)return 0;
        sum/=2;
        vector<vector<int>> memo(nums.size()+1,vector<int>(sum+1,0));
        memo[0][0]=1;
        for (int i=0;i<nums.size();i++)
        {
            for (int j=0;j<=sum;j++)
            {
                if (j-nums[i]>=0)memo[i+1][j]+=memo[i][j-nums[i]];
                memo[i+1][j]+=memo[i][j];
            }
        }
        return memo[nums.size()][sum];
    }

};
class Solution17 {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        vector<vector<pair<bool,int>>> memo(nums.size()+1,vector<pair<bool,int>>(target+1,{false,0}));
        memo[0][0]={true,0};
        for (int i=0;i<nums.size();i++)
        {
            for (int j=0;j<=target;j++)
            {
                memo[i+1][j].first=(j-nums[i]>=0)&&memo[i][j-nums[i]].first||memo[i][j].first;
                if (j-nums[i]<0&&memo[i][j].first)memo[i+1][j].second=memo[i][j].second;
                else if (j-nums[i]>=0)
                {
                    if (memo[i][j-nums[i]].first&&memo[i][j].first)memo[i+1][j].second=max(memo[i][j].second,memo[i][j-nums[i]].second+1);
                    else if (!memo[i][j-nums[i]].first&&memo[i][j].first)memo[i+1][j].second=memo[i][j].second;
                    else if (memo[i][j-nums[i]].first&&!memo[i][j].first)memo[i+1][j].second=memo[i][j-nums[i]].second+1;
                }
            }
        }
        return memo[nums.size()][target].first==true?memo[nums.size()][target].second:-1;
    }
};
class Solution18 {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<int> sub1_2(n,0);
        vector<int> sub2_1(n,0);
        int sum1=0,sum2=0;
        for (int i=0;i<n;i++) {
            sub1_2[i]=nums1[i]-nums2[i];
            sub2_1[i]=nums2[i]-nums1[i];
            sum1+=nums1[i];
            sum2+=nums2[i];
        }
        int ans1=sum1+func(sub2_1);
        int ans2=sum2+func(sub1_2);
        return max(ans1,ans2);
    }
    int func(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,0);
        int sum=0;
        for (int i=1;i<=n;i++) {
            sum+=nums[i-1];
            if (sum<=0) {
                sum=0;
                dp[i]=dp[i-1];
            }
            else {
                dp[i]=max(sum,dp[i-1]);
            }
        }
        return dp[n];
    }
};
class Solution19 {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int max_num=nums[0];
        for (auto it:nums)max_num=max(max_num,it);
        if (max_num<=0)return max_num;
        vector<int> dp(n+1,0);
        int sum=0;
        for (int i=1;i<=n;i++) {
            sum+=nums[i-1];
            if (sum<=0) {
                sum=0;
                dp[i]=dp[i-1];
            }
            else {
                dp[i]=max(dp[i-1],sum);
            }
        }
        return dp[n];
    }
};
class Solution1 {
public:
    int countPathsWithXorValue(vector<vector<int>>& grid, int a) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<vector<int>>> v(m, vector<vector<int>>(n, vector<int>(16, 0)));
        v[0][0][grid[0][0]]=1;
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                for (int k=0;k<16;k++) {
                    if (v[i][j][k]) {
                        if (i==m-1) {
                            if (j<n-1) {
                                v[i][j+1][k^grid[i][j+1]]+=v[i][j][k];
                                v[i][j+1][k^grid[i][j+1]]%=NUM;
                            }
                        }
                        else if (j==n-1) {
                            v[i+1][j][k^grid[i+1][j]]+=v[i][j][k];
                            v[i+1][j][k^grid[i+1][j]]%=NUM;
                        }
                        else {
                            v[i+1][j][k^grid[i+1][j]]+=v[i][j][k];
                            v[i+1][j][k^grid[i+1][j]]%=NUM;
                            v[i][j+1][k^grid[i][j+1]]+=v[i][j][k];
                            v[i][j+1][k^grid[i][j+1]]%=NUM;
                        }
                    }
                }
            }
        }
        return v[m-1][n-1][a];
    }
};
class Solution2 {
public:
    long long minCost(int m, int n, vector<vector<int>> waitCost) {
        vector<vector<long long>> dp(m,vector<long long>(n,0));
        dp[0][0]=1;
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (i==0&&j==0)continue;
                if (i==0) {
                    dp[i][j]=dp[i][j-1]+waitCost[i][j]+(i+1)*(j+1);
                }
                else if (j==0) {
                    dp[i][j]=dp[i-1][j]+waitCost[i][j]+(i+1)*(j+1);
                }
                else {
                    dp[i][j]=min(dp[i][j-1],dp[i-1][j])+waitCost[i][j]+(i+1)*(j+1);
                }
            }
        }
        return dp[m-1][n-1]-waitCost[m-1][n-1];
    }
};
//错误
class Solution3 {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m=coins.size(),n=coins[0].size();
        vector dp(m,vector<tuple<int,int,int>>(n,{0,0,0}));
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (i==0&&j==0)coins[0][0]>0?get<0>(dp[0][0])=coins[0][0]:get<1>(dp[0][0])=-coins[0][0];
                else if (i==0&&j!=0) {
                    if (coins[i][j]>=0) {
                        get<0>(dp[i][j])=get<0>(dp[i][j-1])+coins[i][j];
                        get<1>(dp[i][j])=get<1>(dp[i][j-1]);
                        get<2>(dp[i][j])=get<2>(dp[i][j-1]);
                    }
                    else {
                        if (!(get<1>(dp[i][j-1])>=-coins[i][j]&&get<2>(dp[i][j-1])>=-coins[i][j])) {
                            get<0>(dp[i][j])=get<0>(dp[i][j-1]);
                            int a=get<1>(dp[i][j-1]);
                            int b=get<2>(dp[i][j-1]);
                            get<0>(dp[i][j])-=min(a,b);
                            a>b?b=-coins[i][j]:a=-coins[i][j];
                            get<1>(dp[i][j])=a;
                            get<2>(dp[i][j])=b;
                        }
                        else {
                            get<0>(dp[i][j])=get<0>(dp[i][j-1])+coins[i][j];
                            get<1>(dp[i][j])=get<1>(dp[i][j-1]);
                            get<2>(dp[i][j])=get<2>(dp[i][j-1]);
                        }
                    }
                }
                else if (i!=0&&j==0) {
                    if (coins[i][j]>=0) {
                        get<0>(dp[i][j])=get<0>(dp[i-1][j])+coins[i][j];
                        get<1>(dp[i][j])=get<1>(dp[i-1][j]);
                        get<2>(dp[i][j])=get<2>(dp[i-1][j]);
                    }
                    else {
                        if (!(get<1>(dp[i-1][j])>=-coins[i][j]&&get<2>(dp[i-1][j])>=-coins[i][j])) {
                            get<0>(dp[i][j])=get<0>(dp[i-1][j]);
                            int a=get<1>(dp[i-1][j]);
                            int b=get<2>(dp[i-1][j]);
                            get<0>(dp[i][j])-=min(a,b);
                            a>b?b=-coins[i][j]:a=-coins[i][j];
                            get<1>(dp[i][j])=a;
                            get<2>(dp[i][j])=b;
                        }
                        else {
                            get<0>(dp[i][j])=get<0>(dp[i-1][j])+coins[i][j];
                            get<1>(dp[i][j])=get<1>(dp[i-1][j]);
                            get<2>(dp[i][j])=get<2>(dp[i-1][j]);
                        }
                    }
                }
                else if (i!=0&&j!=0) {
                    if (coins[i][j]>=0) {
                        if (dp[i-1][j]>dp[i][j-1]) {
                            get<0>(dp[i][j])=get<0>(dp[i-1][j])+coins[i][j];
                            get<1>(dp[i][j])=get<1>(dp[i-1][j]);
                            get<2>(dp[i][j])=get<2>(dp[i-1][j]);
                        }
                        else {
                            get<0>(dp[i][j])=get<0>(dp[i][j-1])+coins[i][j];
                            get<1>(dp[i][j])=get<1>(dp[i][j-1]);
                            get<2>(dp[i][j])=get<2>(dp[i][j-1]);
                        }
                    }
                    else {
                        if (dp[i-1][j]>dp[i][j-1]) {
                            if (!(get<1>(dp[i-1][j])>=-coins[i][j]&&get<2>(dp[i-1][j])>=-coins[i][j])) {
                                get<0>(dp[i][j])=get<0>(dp[i-1][j]);
                                int a=get<1>(dp[i-1][j]);
                                int b=get<2>(dp[i-1][j]);
                                get<0>(dp[i][j])-=min(a,b);
                                a>b?b=-coins[i][j]:a=-coins[i][j];
                                get<1>(dp[i][j])=a;
                                get<2>(dp[i][j])=b;
                            }
                            else {
                                get<0>(dp[i][j])=get<0>(dp[i-1][j])+coins[i][j];
                                get<1>(dp[i][j])=get<1>(dp[i-1][j]);
                                get<2>(dp[i][j])=get<2>(dp[i-1][j]);
                            }
                        }
                        else {
                            if (!(get<1>(dp[i][j-1])>=-coins[i][j]&&get<2>(dp[i][j-1])>=-coins[i][j])) {
                                get<0>(dp[i][j])=get<0>(dp[i][j-1]);
                                int a=get<1>(dp[i][j-1]);
                                int b=get<2>(dp[i][j-1]);
                                get<0>(dp[i][j])-=min(a,b);
                                a>b?b=-coins[i][j]:a=-coins[i][j];
                                get<1>(dp[i][j])=a;
                                get<2>(dp[i][j])=b;
                            }
                            else {
                                get<0>(dp[i][j])=get<0>(dp[i][j-1])+coins[i][j];
                                get<1>(dp[i][j])=get<1>(dp[i][j-1]);
                                get<2>(dp[i][j])=get<2>(dp[i][j-1]);
                            }
                        }
                    }
                }
            }
        }
        return get<0>(dp[m-1][n-1]);
    }
};
//正确
class Solution4 {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        // 因为可能有非常小的负数，初始值设为一个极小值
        const int INF = 1e9;
        // dp[i][j][k] 表示到 (i,j) 且使用了 k 次消除技能的最大收益
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, -INF)));

        // 初始化起点
        dp[0][0][0] = coins[0][0];
        if (coins[0][0] < 0) {
            dp[0][0][1] = 0; // 起点如果是负数，可以选择用掉一次免疫
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < 3; k++) {
                    if (dp[i][j][k] == -INF) continue; // 无效状态跳过

                    // 向右走
                    if (j + 1 < n) {
                        // 不使用免疫技能（或者遇到正数）
                        dp[i][j+1][k] = max(dp[i][j+1][k], dp[i][j][k] + coins[i][j+1]);
                        // 如果是负数，且技能还没用完(k+1 <= 2)，尝试使用免疫技能
                        if (coins[i][j+1] < 0 && k + 1 < 3) {
                            dp[i][j+1][k+1] = max(dp[i][j+1][k+1], dp[i][j][k]);
                        }
                    }

                    // 向下走
                    if (i + 1 < m) {
                        // 不使用免疫技能
                        dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k] + coins[i+1][j]);
                        // 如果是负数，且技能还没用完，尝试使用免疫技能
                        if (coins[i+1][j] < 0 && k + 1 < 3) {
                            dp[i+1][j][k+1] = max(dp[i+1][j][k+1], dp[i][j][k]);
                        }
                    }
                }
            }
        }

        // 最终结果是到达终点时，使用 0次、1次 或 2次 免疫情况下的最大值
        return max({dp[m-1][n-1][0], dp[m-1][n-1][1], dp[m-1][n-1][2]});
    }
};

class Solution5 {
public:
    int change(int amount, vector<int> coins) {
        vector v(coins.size(),vector<unsigned long long>(amount+1,0));
        sort(coins.begin(), coins.end());
        for (int i=0;i<coins.size();i++) {
            for (int j=0;j<=amount;j++) {
                if (j==0)v[i][j]=1;
                else if (i==0) j-coins[i]>=0?v[i][j]+=v[i][j-coins[i]]:0;
                else {
                    v[i][j]+=v[i-1][j];
                    j-coins[i]>=0?v[i][j]+=v[i][j-coins[i]]:0;
                }
            }
        }
        return v[coins.size()-1][amount];
    }
};
class Solution6 {
public:
    int coinChange(vector<int> coins, int amount) {
        vector v(coins.size(),vector<long long>(amount+1,-1));
        for (int i=0;i<coins.size();i++) {
            for (int j=0;j<=amount;j++) {
                if (j==0) v[i][j]=0;
                else if (i==0) {if (j-coins[i]>=0&&v[i][j-coins[i]]!=-1) v[i][j]=v[i][j-coins[i]]+1;}
                else {
                    int a=-1,b=-1;
                    if (j-coins[i]>=0&&v[i][j-coins[i]]!=-1)a=v[i][j-coins[i]]+1;
                    if (v[i-1][j]!=-1)b=v[i-1][j];
                    if (a==-1)v[i][j]=b;
                    else if (b==-1)v[i][j]=a;
                    else v[i][j]=min(a,b);
                }
            }
        }
        return v[coins.size()-1][amount];
    }
};
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector dp(n,vector(target+1,0));
        for (int i=0;i<n;i++) {
            for (int j=1;j<=target;j++) {
                if (i==0) {
                    if (j<=k) dp[i][j]=1;
                }
                else
                {
                    for (int m=1;m<=k;m++) {
                        if (j-m>0){dp[i][j]+=dp[i-1][j-m];dp[i][j]%=NUM;}
                    }
                }
            }
        }
        return dp[n-1][target];
    }
};


int main() {
    Solution s;
    vector<int> v1={60,60,60},v2={10,90,10};
    vector<vector<int>> v3={{-7,12,12,13},{-6,19,19,-6},{9,-2,-10,16},{-4,14,-10,-9}};
    // s.numRollsToTarget(10,10,100);
    s.numRollsToTarget(2,6,12);

    return 0;
}