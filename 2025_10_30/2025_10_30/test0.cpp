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

class Solution0 {
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
// https://www.bilibili.com/video/BV1gN411E7Zx/?spm_id_from=333.337.search-card.all.click&vd_source=b5cc04f324fc9d6ee48a5febd77392fc
};

struct ListNode 
 {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution2 {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* before = new ListNode();
        before->next = head;
        head = before;
        for (int x = 1; x < left; x++)
        {
            before = before->next;
        }
        ListNode* list = new ListNode();
        ListNode* last = before->next;
        int time = right;
        while (time <= left)
        {
            list->val = last->val;
            ListNode* temp = new ListNode();
            temp->next = list;
            list = temp;
            last = last->next;
            time++;
        }
        before->next = list->next;
        while (before->next)
        {
            before = before->next;
        }
        before->next = last;
        return head->next;
    }
};
class Solution3 {
public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode* temp = new ListNode(0, head);
        ListNode* find = temp;
        head = temp;
        while (true)
        {
            for (int i = 0; i < k; i++)
            {
                find = find->next;
                if (find == nullptr)return head->next;
            }
            reverseBetween(temp, k);
            for (int i = 0; i < k; i++)
            {
                temp = temp->next;
            }
            find = temp;
        }
        return head->next;
    }
    void reverseBetween(ListNode* pre, int k)
    {
        ListNode* cur = pre->next;
        for (int i = 0; i < k - 1; i++)
        {
            ListNode* next = cur->next;
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
        }
        return;
    }
};
class Solution4 {
public:
    int longestValidParentheses(string s) {
        int lptr = 0, rptr = 0;  //左右指针
        int a = 0, b = 0;        //左右括号的数量
        int ans = 0;          //最大匹配数
        int n = s.size();
        while (lptr != n || rptr != n)
        {
            if (a >= b && rptr < n)
            {
                if (a == b)ans = max(ans, a);
                if (s[rptr] == '(')a++;
                else if (s[rptr] == ')')b++;
                rptr++;
            }
            else
            {
                if (a == b)ans = max(ans, a);
                if (s[lptr] == '(')a--;
                else if (s[lptr] == ')')b--;
                lptr++;
            }
        }
        return ans * 2;
    }
};
class Solution5 {
public:
    ListNode* sortList(ListNode* head) {
        ListNode* ans = new ListNode();
        ListNode* x = ans;
        int maxnum = INT_MAX, curnum = INT_MIN;
        while (true)
        {
            ListNode* ptr = head;
            while (ptr)
            {
                if (ptr->val > curnum)
                {
                    maxnum = min(maxnum, ptr->val);
                }
                ptr = ptr->next;
            }
            if (maxnum == INT_MAX)break;
            ListNode* temp = new ListNode(maxnum);
            x->next = temp;
            x = x->next;
            curnum = maxnum;
            maxnum = INT_MAX;
        }
        return ans->next;
    }
};
class Solution6 {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> v;
        while (head)
        {
            v.push_back(head->val);
            head = head->next;
        }
        sort(v.begin(), v.end());
        ListNode* ans = new ListNode();
        ListNode* ptr = ans;
        for (auto it : v)
        {
            ListNode* temp = new ListNode(it);
            ptr->next = temp;
            ptr = temp;
        }
        return ans->next;
    }
};
class Solution7 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())return nullptr;
        int n = lists.size();
        vector<priority_queue<int>> num(n);
        for (int i = 0; i < n; i++)
        {
            ListNode* head = lists[i];
            while (head)
            {
                num[i].push(-head->val);
                head = head->next;
            }
        }
        for (int i = 0; i < num.size();)
        {
            if (num[i].empty())num.erase(num.begin() + i);
            else i++;
        }
        if (num.empty())return nullptr;

        ListNode* ans = new ListNode();
        ListNode* ptr = ans;
        while (!num.empty())
        {
            int min_num = INT_MIN;
            int x = 0;
            for (int i = 0; i < num.size(); i++)
            {
                if (min_num < num[i].top())
                {
                    x = i;
                    min_num = num[i].top();
                }
            }
            ListNode* temp = new ListNode(-min_num);
            num[x].pop();
            if (num[x].empty())num.erase(num.begin() + x);
            ptr->next = temp;
            ptr = temp;
        }
        return ans->next;
    }
};
class Solution8 {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n - 1, 0);
        dp1[0] = nums[0];
        vector<int> dp2(n, 0);
        dp2[1] = nums[1];
        for (int i = 2; i < n - 1; i++)
        {
            dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i]);
        }
        for (int i = 2; i < n; i++)
        {
            dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i]);
        }
        return max(dp2[n - 1], dp1[n - 2]);
    }
};
class Solution9 {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        set<int> lines;
        for (auto x : buildings)
        {
            lines.insert(x[0]);
            lines.insert(x[1]);
        }
        sort(buildings.begin(), buildings.end(), [&](vector<int> a, vector<int> b)
            {
                return a[0] < b[0];
            });
        int i = 0, n = buildings.size();
        vector<vector<int>> ans;
        int height_temp = 0, line_temp = 0;
        priority_queue<pair<int, int>> q;//<height,i>
        for (int line : lines)
        {
            while (!q.empty() && line >= buildings[q.top().second][1])q.pop();

            for (; i < n && line >= buildings[i][0] && line < buildings[i][1]; i++)
            {
                q.push({ buildings[i][2],i });
            }

            if (!q.empty() && height_temp != q.top().first)
            {
                ans.push_back({ line_temp,height_temp });
                height_temp = q.top().first;
                line_temp = line;
            }
            else if (q.empty())
            {
                ans.push_back({ line_temp,height_temp });
                height_temp = 0;
                line_temp = line;
            }
        }
        ans.push_back({ height_temp,line_temp });
        ans.erase(ans.begin());
        return ans;
    }
};

int main()
{
    Solution9 s;
    vector<vector<int>> a = { {1,2,1} ,{1,2,2},{1,2,3}};
    s.getSkyline(a);
	return 0;
}


#endif