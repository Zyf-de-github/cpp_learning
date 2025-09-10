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