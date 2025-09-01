#if 1

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;



class Solution1 {
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
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> myMap;
        int size = nums.size();
        for (auto it : nums)
        {
            if ((++myMap[it]) > size / 2)return it;
        }
        return 0;
    }
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        int mid = 0;
        for (int i = size - 1 - 1; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                mid = i;
                break;
            }
            if (i == 0)
            {
                sort(nums.begin(), nums.end());
                return;
            }
        }
        //找后面所有比mid大的最小的数
        int j = size - 1;
        while (j)
        {
            if (nums[j] > nums[mid])break;
            j--;
        }
        swap(nums[j], nums[mid]);
        sort(nums.begin() + mid+1, nums.end());
        return;
    }
};

class Solution {
private:
    vector<vector<int>> result;
    int size = 0;
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
#if 0
        sort(nums.begin(), nums.end());
#endif
        size = nums.size();
        finding(nums, {});
        return result;
    }
    void finding(vector<int> nums, vector<int> choose)
    {
        if (nums.size() == 0)
        {
            result.push_back(choose);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
#if 0 //开关，打开是去重版本
            if (i > 0 && nums[i] == nums[i - 1]) continue;
#endif
            vector<int> temp = nums;//传入待选数组
            vector<int> x = choose;
            x.push_back(temp[i]);
            temp.erase(temp.begin() + i);
            finding(temp, x);
        }
    }
};


int main()
{
    //vector<vector<int>> a = { {1,3},{2,6},{8,10},{15,18} };
    //vector<int> a = { 1,2,3 };
    //Solution test;
    ////test.merge(a);
    //test.nextPermutation(a);



	return 0;
}

#endif