#if 0

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
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
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp;
        int size = nums.size();
        dp.push_back({ nums[0], 1 });
        for (int i = 1; i < size; i++)
        {
            int temp = 1;
            for (int j = dp.size() - 1; j >= 0; j--)
            {
                if (nums[i] > dp[j][0])
                {
                    temp = max(temp, dp[j][1] + 1);
                }
            }
            dp.push_back({ nums[i],temp });
        }
        int num = 0;
        for (int i = 0; i < dp.size(); i++)
        {
            num = max(num, dp[i][1]);
        }
        return num;
    }
    int findNumberOfLIS(vector<int>& nums) {
        vector<vector<int>> dp;
        int size = nums.size();
        dp.push_back({ nums[0], 1 , 1 });
        for (int i = 1; i < size; i++)
        {
            int len = 1;
            int time = 1;
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > dp[j][0])
                {
                    if (dp[j][1] + 1 > len)
                    {
                        len = dp[j][1] + 1;
                        time = dp[j][2];
                    }
                    else if (dp[j][1] + 1 == len)
                    {
                        time = time + dp[j][2];
                    }
                }
            }
            dp.push_back({ nums[i],len ,time });
        }
        int num = 0;
        for (int i = 0; i < dp.size(); i++)
        {
            num = max(num, dp[i][1]);
        }
        int ans = 0;
        for (int i = dp.size() - 1; i >= 0; i--)
        {
            if (dp[i][1] == num) ans += dp[i][2];
        }
        return ans;
    }
    int pivotIndex(vector<int>& nums) {
        vector<int> ltr;
        vector<int> rtl;
        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            if (i == 0)
            {
                ltr.push_back(nums[i]);
                rtl.push_back(nums[size - i - 1]);
            }
            else
            {
                ltr.push_back(nums[i] + ltr[i - 1]);
                rtl.push_back(nums[size - i - 1] + rtl[i - 1]);
            }
        }
        int ptr = 0;
        while (ptr < size)
        {
            if (ltr[ptr] != rtl[size - 1 - ptr])ptr++;
            else return ptr;
        }
        return -1;
    }
    int findMiddleIndex(vector<int>& nums) {
        vector<int> ltr;
        vector<int> rtl;
        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            if (i == 0)
            {
                ltr.push_back(nums[i]);
                rtl.push_back(nums[size - i - 1]);
            }
            else
            {
                ltr.push_back(nums[i] + ltr[i - 1]);
                rtl.push_back(nums[size - i - 1] + rtl[i - 1]);
            }
        }
        int ptr = 0;
        while (ptr < size)
        {
            if (ltr[ptr] != rtl[size - 1 - ptr])ptr++;
            else return ptr;
        }
        return -1;
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        set<int> x;
        set<int> y;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    x.insert(i);
                    y.insert(j);
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            if (x.find(i) != x.end())
            {
                for (int j = 0; j < n; j++)
                {
                    matrix[i][j] = 0;
                }
            }
            else
            {
                for (int j = 0; j < n; j++)
                {
                    if (y.find(j) != y.end())
                    {
                        matrix[i][j] = 0;
                    }
                }
            }
        }
    }
    int removeDuplicates(vector<int>& nums)
    {
        if (nums.empty()) return 0;
        int i = 1;
        int count = 1;
        for (int j = 1; j < nums.size(); j++)
        {
            if (nums[j] == nums[j - 1])
            {
                count++;
            }
            else
            {
                count = 1;
            }
            if (count <= 2)
            {
                nums[i++] = nums[j];
            }
        }
        return i;
    }
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int min_num = prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            ans = max(ans, prices[i] - min_num);
            min_num = min(min_num, prices[i]);
        }
        return ans;
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int size = numbers.size();
        int r = size - 1;
        while (l < r)
        {
            if (numbers[l] + numbers[r] == target)
            {
                return { l + 1,r + 1 };
            }
            else if (numbers[l] + numbers[r] > target)
            {
                r--;
            }
            else if (numbers[l] + numbers[r] < target)
            {
                l++;
            }
        }
        return { 0,0 };
    }
    bool isPalindrome(string s) {
        string result;
        for (char c : s)
        {
            if (isalnum(static_cast<unsigned char>(c)))
            {
                result += tolower(static_cast<unsigned char>(c));
            }
        }
        string x(result.rbegin(), result.rend());
        if (x == result) return true;
        return false;
    }
    int maxProfit(vector<int>& prices)
    {
        int sum = 0;
        int num = 10000;
        for (int i = 0; i < prices.size(); i++)
        {
            if (num < prices[i])
            {
                sum += prices[i] - num;
                num = 10000;
            }
            if (i + 1 < prices.size() && prices[i] < prices[i + 1])
            {
                num = prices[i];
            }
        }
        return sum;
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
    vector<int> a = { 1,3,5,4,7 };
    Solution1 test;
    test.findNumberOfLIS(a);


	return 0;
}

#endif