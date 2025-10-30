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


int main()
{
    Solution s;
    vector<int> x = { 1,3,-1,-3,5,3,6,7 };
    s.maxSlidingWindow(x, 3);
	return 0;
}


#endif