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
class Solution9 {
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
class Solution10 {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (int i = 0; i < stones.size(); i++)
        {
            pq.push(stones[i]);
        }
        while (pq.size() >= 2)
        {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            pq.push(abs(a - b));
        }
        return pq.top();
    }
};
class Solution11 {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<tuple<int, int, int>> pq;
        int m = nums1.size(), n = nums2.size();
        for (int i = 0; i < m; i++)
        {
            pq.push({ -nums1[i] - nums2[0],-i,0 });
        }

        vector<vector<int>> ans;
        while (k--)
        {
            int i = -get<1>(pq.top());
            int j = -get<2>(pq.top());
            ans.push_back({ nums1[i],nums2[j] });
            pq.pop();
            if (j + 1 < n)
            {
                pq.push({ -nums1[i] - nums2[j + 1],-i,-j - 1 });
            }
        }
        return ans;
    }
};
class Solution12 {
public:
    string maskPII(string s) {
        int case_state = 0;
        string ans;
        int n = s.size();
        for (int i = 0; i < n; i++)if (s[i] == '@')case_state = 1;
        if (case_state)
        {
            int i = 0;
            if (s[0] >= 'A' && s[0] <= 'Z')ans.push_back(s[0] - 'A' + 'a');
            else ans.push_back(s[0]);
            for (int i = 0; i < 5; i++)ans.push_back('*');
            while (i++ < n)
            {
                if (s[i] == '@')
                {
                    if (s[i - 1] >= 'A' && s[i - 1] <= 'Z')ans.push_back(s[i - 1] - 'A' + 'a');
                    else ans.push_back(s[i - 1]);
                    ans.push_back(s[i]);
                    break;
                }
            }
            while (i++ < n)
            {
                if (s[i] >= 'A' && s[i] <= 'Z')ans.push_back(s[i] - 'A' + 'a');
                else ans.push_back(s[i]);
            }
        }
        else
        {
            int j = n - 1;
            int times = 0;
            while (j-- && j >= 0 && times < 4)
            {
                if (s[j] >= '0' && s[j] <= '9')
                {
                    s.push_back(s[j]);
                    times++;
                }
            }
            s.push_back('-');
            while (j-- && j >= 0 && times < 3)
            {
                if (s[j] >= '0' && s[j] <= '9')
                {
                    s.push_back('*');
                    times++;
                }
            }
            s.push_back('-');
            while (j-- && j >= 0 && times < 3)
            {
                if (s[j] >= '0' && s[j] <= '9')
                {
                    s.push_back('*');
                    times++;
                }
            }
            while (j-- && j >= 0)
            {
                if (s[j] >= '0' && s[j] <= '9')
                {
                    s.push_back(s[j]);
                }
            }
        }
        return ans;
    }
};

class Solution13 {
public:
    int countElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0, n = nums.size();
        int temp = 1;
        for (int i = 0; i < n-1; i++)
        {
            if (nums[i] != nums[i + 1] && n - i - 1 >= k)
            {
                ans += temp;
                temp = 1;
            }
            else if (nums[i] == nums[i + 1])temp++;
        }
        return k > 0 ? ans : ans + temp;
    }
};
class Solution14 {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> m;
        int ans = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            string s = to_string(nums[i]);
            int x = stoi(s);
            if (m.count(x))
            {
                ans = min(ans, i - m[x]);
            }
            reverse(s.begin(), s.end());
            x = stoi(s);
            m[x] = i;
        }
        //m.clear();
        //for (int i = nums.size()-1; i >=0;i--)
        //{
        //    string s = to_string(nums[i]);
        //    int x = stoi(s);
        //    if (m.count(x))
        //    {
        //        ans = min(ans, m[x]-i);
        //    }
        //    reverse(s.begin(), s.end());
        //    x = stoi(s);
        //    m[x] = i;
        //}
        return ans==INT_MAX?-1:ans;
    }
};
class Solution15 {
    public:
        int maxDistinct(string s) {
            int ans = 0;
            vector<bool> v(26, false);
            for (int i = 0; i < s.size(); i++)
            {
                if (!v[s[i] - 'a'])
                {
                    v[s[i] - 'a'] = true;
                    ans++;
                }
            }
            return ans;
        }
};

class Solution16 {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        vector<int> per(n + 1, 0);
        unordered_map<int, int>m;
        int ans = INT_MAX;
        int flag = 0;//判断数组是否全为空才成立
        for (int i = 0; i < n; i++)per[i + 1] = (nums[i] + per[i]) % p;
        if (per[n] % p == 0)return 0;
        for (int i = 0; i <= n; i++)
        {
            if (i != 0 && per[i] % p == 0)
            {
                flag = 1;
                m.clear();
                m[per[i] % p] = i;
                continue;
            }
            int temp = (per[i] - per[n] + p) % p;
            if (i == n && !flag)continue;
            if (m.count(temp))
            {
                ans = min(ans, i - m[temp]);
            }
            m[per[i] % p] = i;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
class Solution17 {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        //1 2 3 4 5 4 3 2 1
        int n = arr.size(), lptr = 0, rptr = n - 2;
        while (lptr < rptr)
        {
            int mid = (lptr + rptr) / 2;
            if (arr[mid] < arr[mid + 1])lptr = mid + 1;
            else rptr = mid - 1;
        }
        return rptr;
    }
};

class Solution20 {
public:
    bool completePrime(int num) {
        string s = to_string(num);
        int n = s.size();
        int pre = 0, last = 0;
        for (int i = 0; i < n; i++)
        {
            pre = stoi(s.substr(0, i + 1));
            last = stoi(s.substr(n - 1 - i, n - 1 + 1));
            if ((!is_num(pre)) || (!is_num(last)))return false;
        }
        return true;
    }
    bool is_num(int x)
    {

        if (x == 2)return true;
        if (x < 2 || x % 2 == 0)return false;
        int temp = pow(x, 0.5);
        for (int i = 3; i <= temp + 1; i += 2)
        {
            if (!(x % i))return false;
        }
        return true;
    }
}; 
class Solution21 {
public:
    vector<int> minOperations(vector<int>& nums) {
        vector<int>back;
        for (int i = 0; i < 5200; i++)
        {
            string s;
            int temp = i;
            do
            {
                s.push_back((temp & 1) + '0');
                temp >>= 1;
            } while (temp);
            int n = s.size();
            for (int j = n / 2; j >= 0; j--)
            {
                if (s[j] != s[n - 1 - j])break;
                else if(j==0) back.push_back(i);
            }
        }
        vector<int>ans(5001, 0);
        int before = back[0];
        int after = back[1];
        int ptr = 2;
        int n = back.size();
        for (int i = 0; i <= 5000; i++)
        {
            while (i > after && ptr < n)
            {
                before = after;
                after = back[ptr];
                ptr++;
            }
            ans[i] = min(i - before, after - i);
        }
        vector<int>x;
        for (int i = 0; i < nums.size(); i++)
        {
            x.push_back(ans[nums[i]]);
        }
        return x;
    }
};

class Solution22 {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        int n = technique1.size();
        vector<int>v(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (technique1[i] > technique2[i])
            {
                k--;
                v[i] = 1;
            }
        }
        if (k > 0)
        {
            priority_queue<pair<int, int>>q;
            for (int i = 0; i < n; i++)
            {
                if (v[i])continue;
                q.push({ technique2[i] - technique1[i],i});
                if (q.size() > k)q.pop();
            }
            while (!q.empty())
            {
                v[q.top().second] = 1;
                q.pop();
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i])ans += technique1[i];
            else ans += max(technique1[i], technique2[i]);
        }
        return ans;
    }
}; 
int main()
{
    Solution22 s;
    vector<int>  nums1 = { 1,2,3};
    vector<int>  nums2 = { 4,5,6};
    int k = 0;
    vector<vector<int>>  queries = { {0,1},{1,2},{0,2} };
    //cout << s.minOperations(nums);
    cout << s.maxPoints(nums1, nums2,0);
	return 0;
}

