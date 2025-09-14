#if 1

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <new>
#include <stack>
using namespace std;



class Solution1 {
    struct TreeNode 
    {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    };
private:
    int ans = 0;
    int res = 0;
public:
    int deepestLeavesSum(TreeNode* root) {
        finding(root, 0);
        return res;
    }
    void finding(TreeNode* root, int x)
    {
        if (root == nullptr)return;
        x++;
        if (x > ans)
        {
            ans = x;
            res = 0;
            res += root->val;
        }
        else if (x == ans)
        {
            res += root->val;
        }
        finding(root->left, x);
        finding(root->right, x);
        return;
    }
};
class Solution {
    
    struct ListNode1 {
        int val;
        ListNode1* next;
        ListNode1(int x) : val(x), next(NULL) {}
    };
    struct ListNode {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode* next) : val(x), next(next) {}
    };
    unordered_map<int, string> mp;
    int ptr = 0;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        ptr++;
        mp[ptr] = longUrl;
        return "http://tinyurl.com$" + to_string(ptr);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int sum = 0;
        for (int i = shortUrl.find('$')+1; i < shortUrl.size(); i++)
        {
            sum += (int)(shortUrl[i] - '0');
        }
        return mp[sum];
    }


    int minPartitions(string n) {
        int ans = 0;
        for (auto it : n)
        {
            ans = max(ans, (int)(it - '0'));
        }
        return ans;
    }
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> v;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j <= v.size(); j++)
            {
                if (j == v.size())
                {
                    v.push_back({ nums[i] });
                    break;
                }
                auto it = find(v[j].begin(), v[j].end(), nums[i]);
                if (it == v[j].end())
                {
                    v[j].push_back(nums[i]);
                    break;
                }
            }
        }
        return v;
    }
    void deleteNode(ListNode* node) {
        if (node->next == NULL)node = NULL;
        node->val = node->next->val;
        node->next = node->next->next;
    }
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;
        for (; head != nullptr; head = head->next)
        {
            st.push(head);
        }
        for (; !st.empty(); st.pop())
        {
            if (head == nullptr || st.top()->val >= head->val)
            {
                st.top()->next = head;
                head = st.top();
            }
        }
        return head;
    }
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* ans = head;
        while (ans != nullptr)
        {
            if (find(nums.begin(), nums.end(), ans->val) != nums.end())
            {
                if (ans->next == nullptr)
                {
                    ans = nullptr;
                }
                else
                {
                    ans->val = ans->next->val;
                    ans->next = ans->next->next;
                }
            }
            else
            {
                ans = ans->next;
            }
        }
        return head;
    }
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < groupSizes.size(); i++)
        {
            m[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> ans;
        for (auto it : m)
        {
            int temp = it.first;
            vector<int> vtemp;
            for (int i = 0; i < it.second.size(); i++)
            {
                vtemp.push_back(it.second[i]);
                if ((i + 1) % temp == 0)
                {
                    ans.push_back(vtemp);
                    vtemp.clear();
                }
            }
        }
        return ans;
    }
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 1)return grid;
        for (int i = 1; i < n; i++)
        {
            int x = n - 1 - i;
            int y = 0;
            vector<int>temp;
            while (x < n)
            {
                temp.push_back(grid[x][y]);
                x++;
                y++;
            }
            sort(temp.begin(), temp.end());
            x--;
            y--;
            for (int j = 0; j < temp.size(); j++, x--, y--)
            {
                grid[x][y] = temp[j];
            }
        }
        for (int i = 1; i < n - 1; i++)
        {
            int x = 0;
            int y = n - 1 - i;
            vector<int>temp;
            while (y < n)
            {
                temp.push_back(grid[x][y]);
                x++;
                y++;
            }
            sort(temp.begin(), temp.end());
            x--;
            y--;
            for (int j = temp.size() - 1; j >= 0; j--, x--, y--)
            {
                grid[x][y] = temp[j];
            }
        }
        return grid;
    }
    bool isStrictlyPalindromic(int n) {
        return false;
    }
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty())return{};
        vector<string> ans;
        sort(nums.begin(), nums.end());
        int min = nums[0];
        int max = min;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1] + 1)
            {
                if (max == min)
                    ans.push_back(to_string(max));
                else
                    ans.push_back(to_string(min) + "->" + to_string(max));

                min = nums[i];
                max = min;
            }
            else
            {
                max = nums[i];
            }
        }
        if (max == min)
            ans.push_back(to_string(max));
        else
            ans.push_back(to_string(min) + "->" + to_string(max));
        return ans;
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end(), [](int a, int b) {
            return a > b;
            });
        int ans = 0;
        int temp = 0;
        for (auto it : satisfaction)
        {
            temp += it;
            if (temp <= 0)break;
            ans += temp;
        }
        return ans;
    }
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int ptr_m = 0;
        int ptr_p = 0;
        int ptr_g = 0;
        int sum = 0;
        int count_m = 0;
        int count_p = 0;
        int count_g = 0;
        for (int i = 0; i < garbage.size(); i++)
        {
            count_m = 0;
            count_p = 0;
            count_g = 0;
            for (char c : garbage[i])
            {
                if (c == 'M') count_m++;
                if (c == 'P') count_p++;
                if (c == 'G') count_g++;
            }
            if (count_m)
            {
                while (ptr_m < i)
                {
                    sum += travel[ptr_m];
                    ptr_m++;
                }
                sum += count_m;
            }
            if (count_p)
            {
                while (ptr_p < i)
                {
                    sum += travel[ptr_p];
                    ptr_p++;
                }
                sum += count_p;
            }
            if (count_g)
            {
                while (ptr_g < i)
                {
                    sum += travel[ptr_g];
                    ptr_g++;
                }
                sum += count_g;
            }
        }
        return sum;
    }
    int maxCoins(vector<int>& piles) {
        int sum = 0;
        sort(piles.begin(), piles.end());//1 2 2 4 7 8 
        for (int i = piles.size() / 3; i < piles.size(); i += 2)
        {
            sum += piles[i];
        }
        return sum;
    }
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int>pre(size, 1);
        vector<int>les(size, 1);
        vector<int>ans(size, 0);
        for (int i = 1; i < size; i++)
        {
            pre[i] = pre[i - 1] * nums[i - 1];
        }
        for (int i = size - 2; i >= 0; i--)
        {
            les[i] = les[i + 1] * nums[i + 1];
        }
        for (int i = 0; i < size; i++)
        {
            ans[i] = pre[i] * les[i];
        }
        return ans;
    }
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (1 <= nums[i] && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                int j = nums[i] - 1;
                swap(nums[i], nums[j]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != i + 1)
            {
                return i + 1;
            }
        }
        return n + 1;
    }
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        while (tempA != tempB)
        {
            if (tempA == NULL)
            {
                tempA = headB;
            }
            else
            {
                tempA = tempA->next;
            }

            if (tempB == NULL)
            {
                tempB = headA;
            }
            else
            {
                tempB = tempB->next;
            }
        }
        return tempA;
    }
    bool isPalindrome(ListNode* head) {
        deque<int> dq;
        while (head != nullptr)
        {
            dq.push_back(head->val);
            head = head->next;
        }
        while (!dq.empty())
        {
            if (dq.front() != dq.back())return false;
            else if (dq.size() > 1)
            {
                dq.pop_back();
                dq.pop_front();
            }
            else
            {
                return true;
            }
        }
        return true;
    }
};

void main()
{
    Solution s;

    //string temp = s.encode("https://leetcode.com/problems/design-tinyurl");
    //string result = s.decode(temp);
    //s.modifiedList({ 9,2,5 }, { 2,9,10 });
    return;
}


#endif