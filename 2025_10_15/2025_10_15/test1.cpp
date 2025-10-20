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
using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};


class Solution0 {
public:
    int smallestDifference(vector<int>& a, vector<int>& b) {
        int size1 = a.size();
        int size2 = b.size();
        int ptr1 = 0, ptr2 = 0;
        long ans = abs((long)a[size1 - 1] - (long)b[size2 - 1]);
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        while (ptr1 != size1 - 1 || ptr2 != size2 - 1)
        {
            long diff = (long)a[ptr1] - (long)b[ptr2];
            ans = min(ans, abs(diff));
            if (a[ptr1] < b[ptr2])
            {
                if (ptr1 < size1 - 1)ptr1++;
                else ptr2++;
            }
            else
            {
                if (ptr2 < size2 - 1)ptr2++;
                else ptr1++;
            }
        }
        return (int)ans;
    }
};
class Solution1 {
public:
    int maximum(int a, int b) {
        long long temp = (long)a - (long)b;
        if ((temp >> 63) & 1)return b;
        return a;

    }
};
class Solution2 {
public:
    int maxAliveYear(vector<int>& birth, vector<int>& death) {
        sort(birth.begin(), birth.end());
        sort(death.begin(), death.end());
        vector<int>v;
        int live = 0, ptr_l = 0, ptr_d = 0;
        int size = birth.size();
        for (int i = 1900; i <= 2000; i++)
        {
            if (ptr_l < size && birth[ptr_l] == i)
            {
                while (ptr_l < size&&birth[ptr_l] == i )
                {
                    live++;
                    ptr_l++;
                }
            }
            if (ptr_d < size && death[ptr_d] + 1 == i)
            {
                while (ptr_d < size && death[ptr_d]+1 == i )
                {
                    live--;
                    ptr_d++;
                }
            }
            v.push_back(live);
        }
        int ptr = 0;
        int max_num = 0;
        for (int i = 0; i <= 100; i++)
        {
            if (v[i] > max_num)
            {
                ptr = i;
                max_num = v[i];
            }
        }
        return ptr + 1900;
    }
};
class Solution3 {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        for (int i = 0; i < candidates.size(); i++)
        {
            vector<int> temp;
            dfs(temp, i, target, candidates);
        }
        return ans;
    }
    void dfs(vector<int> temp, int i, int target, vector<int>& candidates)
    {
        if (candidates[i] > target)return;
        temp.push_back(candidates[i]);
        target -= candidates[i];
        if (target == 0)
        {
            ans.push_back(temp);
            return;
        }
        for (int j = 0; j + i < candidates.size(); j++)
        {
            if (candidates[i + j] > target)break;
            dfs(temp, i + j, target, candidates);
        }
        return;
    }
};
class Solution4 {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        dfs(path, 0, target, candidates);
        return ans;
    }
    void dfs(vector<int>& path, int start, int target, vector<int>& candidates)
    {
        if (target == 0)
        {
            ans.push_back(path);
            return;
        }
        for (int i = start; i < candidates.size(); i++)
        {
            if (candidates[i] > target)break;
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            path.push_back(candidates[i]);
            dfs(path, i + 1, target - candidates[i], candidates);
            path.pop_back();
        }
        return;
    }
};
class Solution5 {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end(), [&](vector<int> a, vector<int> b)
            {
                return a[0] < b[0];
            });
        vector<vector<int>> ans;
        int begin = intervals[0][0];
        int end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] <= end && intervals[i][1] > end)
            {
                end = intervals[i][1];
            }
            else if (intervals[i][0] > end)
            {
                ans.push_back({ begin,end });
                begin = intervals[i][0];
                end = intervals[i][1];
            }
        }
        ans.push_back({ begin,end });
        return ans;
    }
};
class MinStack {
    stack<pair<int, int>> st;

public:
    MinStack() {
        st.push({ 0, INT_MAX });
    }

    void push(int val) {
        st.push({ val, min(getMin(), val) });
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
};


int main()
{
    Solution2 s;
    vector<int> v1 = { 1900,1901,1950 };
    vector<int> v2 = { 1948,1951,2000 };
    s.maxAliveYear(v1, v2);
    return 0;
}


#endif