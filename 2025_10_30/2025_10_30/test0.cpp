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
int main()
{
    Solution1 s;
    vector<int> x = { 0,1,2,1,2,1 };
    s.subarraySum(x, 3);
	return 0;
}


#endif