#if 1

#include <vector>
#include <algorithm>
#include <vector>
using namespace std;

//struct TreeNode {
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
//     };
//
//class Solution1 {
//private:
//    vector<int> x;
//public:
//    TreeNode* sortedArrayToBST(vector<int>& nums)
//    {
//        x = nums;
//        return build(0, nums.size() - 1);
//    }
//    TreeNode* build(int begin, int end)
//    {
//        if (begin > end)return nullptr;
//        TreeNode* root = new TreeNode(x[(begin + end) / 2]);
//        root->left = build(begin, (begin + end) / 2 - 1);
//        root->right = build((begin + end) / 2 + 1, end);
//        return root;
//    }
//};
//
//class Solution2 {
//public:
//    vector<int> findClosedNumbers(int num) {
//        int small = num;
//        if (num == 1) small = -1;
//        int big = num;
//        if (num == 2147483647) big = -1;
//
//        if (big != -1) {
//            for (int i = 1; i < 32; i++) {
//                if ((!(num & (1 << i))) && (num & (1 << (i - 1)))) {
//                    big |= 1 << i;
//                    big &= ~(1 << (i - 1));
//
//                    int ones = __builtin_popcount(num & ((1 << (i - 1)) - 1));
//                    big &= ~((1 << (i - 1)) - 1);
//                    big |= (1 << ones) - 1;
//                    break;
//                }
//            }
//        }
//
//        if (small != -1) {
//            for (int i = 30; i >= 0; i--) {
//                if ((!(num & (1 << i))) && (num & (1 << (i + 1)))) {
//                    small |= 1 << i;
//                    small &= ~(1 << (i + 1));
//
//                    int ones = __builtin_popcount(num & ((1 << i) - 1));
//                    small &= ~((1 << i) - 1);
//                    small |= ((1 << ones) - 1) << (i - ones);
//                    break;
//                }
//            }
//        }
//        return { big, small };
//    }
//};
//
//class Solution3 {
//public:
//    vector<int> findClosedNumbers(int num)
//    {
//        int larger = findLarger(num);
//        int smaller = findSmaller(num);
//
//        return { larger,smaller };
//    }
//    int exchangeBits(int num) {
//        int c0 = 0;
//        int c1 = 0;
//        int c = 0;
//        for (int i = 0; i < 32; i += 2)
//        {
//            c0 |= num & (1 << i);
//            c1 |= num & (1 << (i + 1));
//            int temp = 0;
//            temp |= 1 << i;
//            temp |= 1 << (i + 1);
//
//            num &= (~temp);
//            num |= c0 << 1;
//            num |= c1 >> 1;
//        }
//        return num;
//    }
//private:
//    int findLarger(int num) {
//        int c = num;
//        int c0 = 0;
//        int c1 = 0;
//
//        while (((c & 1) == 0) && (c != 0)) {
//            c0++;
//            c >>= 1;
//        }
//        while ((c & 1) == 1) {
//            c1++;
//            c >>= 1;
//        }
//
//        if (c0 + c1 == 31 || c0 + c1 == 0) {
//            return -1;
//        }
//
//        int pos = c0 + c1;
//
//        num |= (1 << pos);
//        num &= ~((1 << pos) - 1);
//        num |= ((1 << (c1 - 1)) - 1);
//
//        return num;
//    }
//    int findSmaller(int num)
//    {
//        int c = num;
//        int c1 = 0;
//        int c0 = 0;
//
//        while ((c & 1) == 1)
//        {
//            c1++;
//            c >>= 1;
//        }
//
//        if (c == 0) return -1;
//
//        while (((c & 1) == 0) && (c != 0))
//        {
//            c0++;
//            c >>= 1;
//        }
//
//        int pos = c0 + c1;
//
//        num &= ~((1 << (pos + 1)) - 1);
//        int mask = (1 << (c1 + 1)) - 1;
//        num |= mask << (c0 - 1);
//
//        return num;
//    }
//};

class Solution {
    vector<vector<int>> finding;
    vector<vector<int>> temp;
    int m;
    int n;
    int flag = 0;
public:
    vector<vector<int>> pathWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0] == 1)
        {
            return {};
        }
        temp = obstacleGrid;
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        finding.assign(m, vector<int>(n, 0));
        dfs(0, 0);
        if (flag == 0)return {};
        int i = 0, j = 0;
        vector<vector<int>> ans;
        while (!(i == m - 1 && j == n - 1))
        {
            ans.push_back({ i,j });
            if (i + 1 < m && finding[i + 1][j]==1)i = i + 1;
            else if (j + 1 < n && finding[i][j + 1]==1)j = j + 1;
        }
        ans.push_back({ i,j });
        return ans;
    }

    void dfs(int i, int j)
    {
        if (i >= m || j >= n || temp[i][j] == 1||finding[i][j]==-1)
        {
            return;
        }
        finding[i][j] = 1;
        if (i == m - 1 && j == n - 1)
        {
            flag = 1;
            return;
        }
        if (i + 1 < m)dfs(i + 1, j);
        if (flag)return;
        if (j + 1 < n)dfs(i, j + 1);
        if (flag)return;
        finding[i][j] = -1;
        return;
    }

    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = nums[0];
        int times = 0;
        int temp = 1;
        int only = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
            {
                temp++;
            }
            else
            {
                if (times < temp)
                {
                    times = temp;
                    temp = 1;
                    ans = nums[i - 1];
                    only = 1;
                }
                else if (times == temp)
                {
                    only = 0;
                }
            }
        }

        if (times < temp)
        {
            times = temp;
            temp = 1;
            ans = nums[nums.size() - 1];
            only = 1;
        }
        else if (times == temp)
        {
            only = 0;
        }

        if (only)return ans;
        return -1;
    }
};

int main()
{
    Solution x;
    vector<vector<int>> y = { { 0,0,0 }, { 0,1,0 }, { 0,1,0 } };
    x.pathWithObstacles(y);
    return 0;
}

#endif