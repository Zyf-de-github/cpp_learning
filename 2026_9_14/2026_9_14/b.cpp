#define _SILENCE_ALL_CXX20_DEPRECATION_WARNINGS
#include "test.h"
using namespace std;

class Solution30 {
public:
    vector<int> secondGreaterElement(vector<int> nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st_first,st_second;
        for (int i = 0; i < n; i++)
        {
            stack<int>temp;
            while (!st_first.empty() && nums[st_first.top()] < nums[i])
            {
                int x = st_first.top();
                temp.push(x);
                st_first.pop();
            }
            st_first.push(i);
            while (!st_second.empty() && nums[st_second.top()] < nums[i])
            {
                ans[st_second.top()] = nums[i];
                st_second.pop();
            }
            while (!temp.empty())
            {
                st_second.push(temp.top());
                temp.pop();
            }
        }
        int x = pow(2,2);
        return ans;
    }
};
class Solution29 {
public:
    int largestRectangleArea(vector<int> heights) {
        int ans = 0;
        stack<int>st;
        int n = heights.size();
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                int temp = st.top();
                st.pop();
                if (st.empty())ans = max(ans, heights[temp] * (i));
                else ans = max(ans, heights[temp] * (i - 1 - st.top()));
            }
            st.push(i);
        }
        while (!st.empty())
        {
            int temp = st.top();
            st.pop();
            if (st.empty())ans = max(ans, heights[temp] * n);
            else ans = max(ans, heights[temp] * (n - 1 - st.top()));
        }
        return ans;
    }
};
class Solution28_1 {
public:
    int maximumScore(vector<int> heights, int k) {
        int ans = 0;
        stack<int>st;
        int n = heights.size();
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                int temp = st.top();
                st.pop();
                if (st.empty() && i > k)ans = max(ans, heights[temp] * (i));
                else if(!st.empty() && i > k && st.top() < k) ans = max(ans, heights[temp] * (i - 1 - st.top()));
            }
            st.push(i);
        }
        while (!st.empty())
        {
            int temp = st.top();
            st.pop();
            if (st.empty())ans = max(ans, heights[temp] * n);
            else if(!st.empty() && st.top() < k) ans = max(ans, heights[temp] * (n - 1 - st.top()));
        }
        return ans;
    }
};
class Solution28_2 {
public:
    int maximumScore(vector<int> nums, int k) {
        int cur_num = nums[k], rptr = k, lptr = k, ans = 0, n = nums.size();
        while (lptr>=0||rptr<n)
        {
            if (rptr < n && nums[rptr] >= cur_num)rptr++;
            else if (lptr >= 0 && nums[lptr] >= cur_num)lptr--;
            else if ((rptr >= n || nums[rptr] < cur_num) && (lptr < 0 || nums[lptr] < cur_num))
            {
                ans = max(ans, cur_num * (rptr - lptr - 1));
                if (lptr < 0)
                {
                    cur_num = nums[rptr];
                    rptr++;
                }
                else if (rptr >= n)
                {
                    cur_num = nums[lptr];
                    lptr--;
                }
                else
                {
                    if (nums[rptr] > nums[lptr])
                    {
                        cur_num = nums[rptr];
                        rptr++;
                    }
                    else if (nums[rptr] < nums[lptr])
                    {
                        cur_num = nums[lptr];
                        lptr--;
                    }
                    else
                    {
                        cur_num = nums[rptr];
                        rptr++;
                        lptr--;
                    }
                }
                
            }
        }
        ans = max(ans, n * cur_num);
        return ans;
    }
};
// 1 3 5 5 2 5 5 1


int main()
{
    Solution s;
    //vector<int> v;
    //v = s.secondGreaterElement({ 2,4,0,9,6 });
    //for (auto it : v)cout << it << ' ';
    cout << s.maximumScore({ 2 },0);
	return 0;
}