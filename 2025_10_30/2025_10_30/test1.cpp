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
        for (int i = 1; i < n; i++)
        {
            if (nums[i] < nums[i - 1])
            {
                per.push_back({ temp,i - 1 });
                temp = i;
            }
        }
        per.push_back({ temp,n - 1 });//所有单调递增区间下标


        for (int i = 0; i < queries.size(); i++)
        {
            long long add_num = 0;
            temp = 0;
            int lptr = 0;
            int rptr = per.size() - 1;
            while (lptr <= rptr)
            {
                int mid = (lptr + rptr) / 2;
                if (per[mid][1] >= queries[i][0]) rptr = mid - 1;
                else lptr = mid + 1;
            }
            temp = lptr;
            while (temp < per.size() && per[temp][0] <= queries[i][1])
            {
                long long x = min(queries[i][1], per[temp][1]) - max(queries[i][0], per[temp][0]) + 1;
                add_num += x * (x + 1) / 2;
                temp++;
            }
            ans.push_back(add_num);
        }
        return ans;
    }
};
class Solution6 {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            int h = heights[i];
            while (!st.empty() && heights[st.top()] >= h) {
                st.pop();
            }
            if (!st.empty()) {
                left[i] = st.top();
            }
            st.push(i);
        }

        vector<int> right(n, n);
        st = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            int h = heights[i];
            while (!st.empty() && heights[st.top()] >= h) {
                st.pop();
            }
            if (!st.empty()) {
                right[i] = st.top();
            }
            st.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, heights[i] * (right[i] - left[i] - 1));
        }
        return ans;
    }
};

class Solution7 {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        string x_;
        long long sum_ = 0;
        for (auto it : s)
        {
            if (it != '0')
            {
                x_ = x_ + string(1, it);
                sum_ += it - '0'; 
            }
        }
        if (!x_.size())return 0;
        return stoi(x_) * sum_;
    }
};  
class Solution8 {
public:
    struct PairHash
    {
        size_t operator()(const pair<unsigned int, int>& p) const noexcept
        {
            return hash<unsigned int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };

    int maxBalancedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<unsigned int> XOR(n, 0);
        int sin = 0, dou = 0;
        vector<int>equal(n, 0);
        XOR[0] = nums[0];
        nums[0] % 2 ? sin += 1 : dou += 1;
        equal[0] = sin - dou;
        for (int i = 1; i < n; i++)
        {
            nums[i] % 2 ? sin += 1 : dou += 1;
            equal[i] = sin - dou;
            XOR[i] = XOR[i - 1] ^ nums[i];
        }
        unordered_map<pair<unsigned int, int>, int, PairHash> m;
        m[{0, 0}] = -1;
        int length = 0;
        for (int i = 0; i < n; i++)
        {
            if (m.count({ XOR[i], equal[i] }))
            {
                length = max(length, i - m[{XOR[i], equal[i]}]);
            }
            else m[{XOR[i], equal[i]}] = i;
        }
        return length;
    }
}; 
class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries)
    {
        int n = s.size();
        vector<long long> num_sum;
        vector<string> num_x;
        long long temp_sum = 0; string temp_x;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != '0')
            {
                temp_x = temp_x + s[i];
                temp_sum += s[i] - '0';
                temp_sum %= 1000000007;
                num_sum.push_back(temp_sum);
                num_x.push_back(temp_x);
            }
        }
        vector<int> ans;
        for (int i = 0; i < queries.size(); i++)
        {
            string temp = num_x[queries[i][1]].substr(num_x[queries[i][0]].size());
            ans.push_back((stol(temp) % 1000000007 * (num_sum[queries[i][1]] - num_sum[queries[i][0]])) % 1000000007);
        }
        return ans;
    }
}; 
int main()
{
    Solution8 s;
    vector<int>  nums = { 0 };
    vector<vector<int>>  queries = { {0,1},{1,2},{0,2} };
    cout<<s.maxBalancedSubarray(nums);
	return 0;
}

