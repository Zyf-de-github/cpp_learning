#if 1

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

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> q;
        for (int i = 0; i < n; i++)
        {
            while (!q.empty() && nums[q.back()] < nums[i])
            {
                q.pop_back();
            }
            q.push_back(i);
            if (i - q.front() >= k)q.pop_front();
            if (i >= k - 1)ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};
class Solution1 {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> s(n);
        s[0] = nums[0];
        for (int i = 0; i < n-1; i++)
        {
            s[i + 1] = s[i] + nums[i+1];
        }

        unordered_map<int, int> cnt;
        int ans = 0;
        for (int sj : s)
        {
            ans += cnt.contains(sj - k) ? cnt[sj - k] : 0;
            cnt[sj]++;
        }
        return ans;
    }
};

int main()
{
    Solution1 s;
    vector<int> x = { 0,1,2,1,2,1 };
    s.subarraySum(x, 3);
	return 0;
}


#endif