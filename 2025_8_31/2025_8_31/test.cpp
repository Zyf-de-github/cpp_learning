#if 1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



class Solution {
private:
    struct ListNode 
    {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
 
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
            });

        int size = intervals.size();

        int result_ptr = 0;
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        int max = intervals[0][1];

        for (int i = 1; i < size; i++)
        {
            if (intervals[i][0] > max)
            {
                result.push_back(intervals[i]);
                result_ptr++;
                max = intervals[i][1];
            }
            else
            {
                max = std::max(max, intervals[i][1]);
                result[result_ptr][1] = max;
            }
        }
        return result;
    }
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> result(size);
        for (int i = 0; i < size; i++)
        {
            result[(i + k) % size] = nums[i];
        }
        nums = result;
        return;
    }
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    bool hasCycle(ListNode* head) {
        int num = 0;
        while (head)
        {
            if (num == 10000)return true;
            num++;
            head = head->next;
        }
        return false;
    }

};




int main()
{
    vector<vector<int>> a = { {1,3},{2,6},{8,10},{15,18} };
    Solution test;
    test.merge(a);
	return 0;
}

#endif