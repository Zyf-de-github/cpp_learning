#include <bits/stdc++.h>
#define NUM 1000000007
using namespace std;

class Solution1 {
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
class Solution2 {
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
class Solution3 {
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
class Solution {
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

int main() {
    Solution s;
    vector<int> v={5,-2,5};
    s.maxSubarraySumCircular(v);

    return 0;
}