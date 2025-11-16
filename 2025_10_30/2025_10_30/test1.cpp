#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <random>
using namespace std;
struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution1 {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int ans1 = 0, ans2 = 0;
        set<int> s1, s2;
        for (auto it : nums1)
        {
            s1.insert(it);
        }
        for (auto it : nums2)
        {
            s2.insert(it);
        }
        for (auto it : nums1)
        {
            if (s2.count(it))ans1++;
        }
        for (auto it : nums2)
        {
            if (s1.count(it))ans2++;
        }
        return { ans1,ans2 };
    }
};
class Solution2 {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n - 1] + nums[n - 2] - nums[0];
    }
}; 
class Solution3 {
public:
    int minLengthAfterRemovals(string s) {
        int ptr = 0;
        while (true)
        {
            if (ptr < 0)ptr = 0;
            if (s.empty() || ptr >= s.size() - 1)break;

            if (s[ptr] == 'a' && s[ptr + 1] == 'b')
            {
                s.erase(ptr, 2);
                ptr--;
            }
            else ptr++;
        }
        return s.size();
    }
};
class Solution4 {
public:
    long long countDistinct(long long n) {
        long long ans = 0;
        int flag = 0;
        for (int i = 1; i <= n; i++)
        {
            flag = 1;
            string s = to_string(i);
            for (int j = s.size() - 1; j >= 0; j--)
            {
                if (s[j] == '0')
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)ans++;
        }
        return ans;
    }
}; 
class Solution5 {
public:
    vector<long long> countStableSubarrays(vector<int>& nums, vector<vector<int>>& queries)
    {
        int n = nums.size();
        vector<long long>ans;
        vector<vector<int>> per;
        int temp = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < nums[i - 1])
            {
                per.push_back({ temp,i - 1 });
                temp = i;
            }
        }
        per.push_back({ temp,n - 1 });


        for (int i = 0; i < queries.size(); i++)
        {
            long long add_num = 0;
            int j = 0;
            while (j < per.size() && per[j][0] < queries[i][1])
            {
                if (per[j][1] < queries[i][0])
                {
                    j++;
                    continue;
                }
                long long x = min(queries[i][1], per[j][1]) - max(queries[i][0], per[j][0]) + 1;
                add_num += x * (x + 1) / 2;
                j++;
            }
            ans.push_back(add_num);
        }
        return ans;
    }
};   
int main()
{
    Solution5 s;
    vector<int>  nums = { 3,1,2 };
    vector<vector<int>>  queries = { {0,1},{1,2},{0,2} };
    s.countStableSubarrays(nums, queries);
	return 0;
}

