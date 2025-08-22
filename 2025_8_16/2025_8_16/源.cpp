
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
//public:
//    bool exist(vector<vector<char>>& board, string word) {
//        this->m = board.size();
//        this->n = board[0].size();
//        this->arr = board;
//        this->my_word = word;
//        this->word_size = word.size();
//        for (int i = 0; i < this->m; i++)
//        {
//            for (int j = 0; j < this->n; j++)
//            {
//                finding(i, j, 0);
//            }
//        }
//        if (this->flag)return true;
//        else return false;
//    }
//
//private:
//    int m = 0;
//    int n = 0;
//    int word_size = 0;
//    string my_word;
//    vector<vector<char>> arr;
//    int flag = 0;
//    void finding(int i, int j, int x)
//    {
//        if (this->flag) return;
//        if (x == this->word_size)
//        {
//            flag = 1;
//            return;
//        }
//        if (i >= 0 &&
//            j >= 0 &&
//            i < m &&
//            j < n &&
//            x < word_size &&
//            this->arr[i][j] == this->my_word[x])
//        {
//            this->arr[i][j] = 0;
//            finding(i - 1, j, x + 1);
//            finding(i + 1, j, x + 1);
//            finding(i, j - 1, x + 1);
//            finding(i, j + 1, x + 1);
//            this->arr[i][j] = this->my_word[x];
//        }
//    }
//
//public:
//    void rotate(vector<vector<int>>& matrix) {
//        int size = matrix.size();
//        for (int i = 0; i <= size / 2; i++)
//        {
//            for (int j = 0; j < size - 2 * i-1; j++)
//            {
//                ////×óÐý90¡ã
//                //int temp = matrix[i][i + j];
//                //matrix[i][i + j] = matrix[j][size - 1 - i];
//                //matrix[j][size - 1 - i] = matrix[size - 1 - i][size - 1 - j];
//                //matrix[size - 1 - i][size - 1 - j] = matrix[size - 1 - j][i];
//                //matrix[size - 1 - j][i] = temp;
//                int temp = matrix[i][i + j];                             // top
//                matrix[i][i + j] = matrix[size - 1 - j-i][i];                 // left -> top
//                matrix[size - 1 - j-i][i] = matrix[size - 1 - i][size - 1 - j-i];     // bottom -> left
//                matrix[size - 1 - i][size - 1 - j-i] = matrix[j+i][size - 1 - i];     // right -> bottom
//                matrix[j+i][size - 1 - i] = temp;                             // top -> right
//            }
//        }
//    }
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp;
        int ptr = 0;
        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            if (i == 0)
            {
                dp.push_back(nums[i]);
            }
            else
            {
                if (dp[ptr] <= 0)
                {
                    dp.push_back(nums[i]);
                }
                else
                {
                    dp.push_back(nums[i] + dp[ptr]);
                }
                ptr++;
            }
        }
        size = dp.size();
        int result = -10000;
        for (int i = 0; i < size; i++)
        {
            if (dp[i] > result)result = dp[i];
        }
        return result;
    }
    bool canJump(vector<int>& nums) {
        int max = 0;
        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            if (nums[i] + i > max)max = nums[i] + i;
            if (max < i)return false;
            if (max > size)return true;
        }
        return false;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (obstacleGrid[i][j] == 1)dp[i][j] = 0;
                else
                {
                    if (i == 0 && j == 0)dp[i][j] = 1;
                    else if (i == 0)dp[i][j] = dp[i][j - 1];
                    else if (j == 0)dp[i][j] = dp[i - 1][j];
                    else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
    int fib(int n) {
        if (n == 0)return 0;
        vector<int> dp;
        for (int i = 0; i < n; i++)
        {
            if (i == 0 || i == 1)dp.push_back(1);
            else dp.push_back(dp[i - 1] + dp[i - 2]);
        }
        return dp[n - 1];
    }
    int tribonacci(int n) {
        // if (n == 0)return 0;
        vector<int> dp;
        for (int i = 0; i <= n; i++)
        {
            if (i == 0)dp.push_back(0);
            else if (i == 2 || i == 1)dp.push_back(1);
            else dp.push_back(dp[i - 1] + dp[i - 2] + dp[i - 3]);
        }
        return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp;
        dp.push_back(0);
        dp.push_back(0);
        int x = cost.size();
        for (int i = 2; i <= x; i++)
        {
            if (dp[i - 1] + cost[i - 1] > dp[i - 2] + cost[i - 2])dp.push_back(dp[i - 2] + cost[i - 2]);
            else dp.push_back(dp[i - 1] + cost[i - 1]);
        }
        return dp[x];
    }
    int rob(vector<int>& nums) {
        vector<int> dp;
        int x = nums.size();
        for (int i = 0; i < x; i++)
        {
            if (i == 0)dp.push_back(nums[0]);
            else if (i == 1)dp.push_back(max(nums[0], nums[1]));
            else
            {
                if (nums[i] + dp[i - 2] > dp[i - 1])dp.push_back(nums[i] + dp[i - 2]);
                else dp.push_back(dp[i - 1]);
            }
        }
        if (x == 1)
        {
            return dp[0];
        }
        if (x == 2)
        {
            return dp[0] > dp[1] ? dp[0] : dp[1];
        }
        return dp[x - 1];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp;
        dp.push_back(triangle[0]);
        for (int i = 1; i < m; i++)
        {
            vector<int> temp;
            for (int j = 0; j < triangle[i].size(); j++)
            {
                if (j == 0)temp.push_back(triangle[i][j] + dp[i - 1][j]);
                else if (j == triangle[i].size() - 1)temp.push_back(triangle[i][j] + dp[i - 1][j - 1]);
                else temp.push_back(triangle[i][j] + min(dp[i - 1][j - 1], dp[i - 1][j]));
            }
            dp.push_back(temp);
        }
        return *min_element(dp[m - 1].begin(), dp[m - 1].end());
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> dp;
        dp.push_back(matrix[0]);
        int size = matrix.size();
        for (int i = 1; i < size; i++)
        {
            vector<int> temp;
            for (int j = 0; j < size; j++)
            {
                if (j == 0)temp.push_back(matrix[i][j] + min(dp[i - 1][j], dp[i - 1][j + 1]));
                else if (j == size - 1)temp.push_back(matrix[i][j] + min(dp[i - 1][j - 1], dp[i - 1][j]));
                else temp.push_back(matrix[i][j] + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i - 1][j + 1])));
            }
            dp.push_back(temp);
        }
        return *min_element(dp[size - 1].begin(), dp[size - 1].end());
    }
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int left = 0;
        int right = 0;
        int up = 0;
        int down = 0;
        for (int i = 0; i < m; i++)
        {
            int flag_up = 0;
            int flag_down = 0;
            for (int j = 0; j < n; j++)
            {
                if ((!up) && (grid[i][j]))flag_up = i + 1;
                if ((!down) && (grid[m - 1 - i][j]))flag_down = m - i;
            }
            if (flag_up)up = flag_up;
            if (flag_down)down = flag_down;

        }
        for (int j = 0; j < n; j++)
        {
            int flag_left = 0;
            int flag_right = 0;
            for (int i = 0; i < m; i++)
            {
                if ((!left) && (grid[i][j]))flag_left = j + 1;
                if ((!right) && (grid[i][n - 1 - j]))flag_right = n - j;
            }
            if (flag_left)left = flag_left;
            if (flag_right)right = flag_right;
        }
        return (down - up + 1) * (right - left + 1);
    }
};
// {1, 2, 3, 4},
// {5, 6, 7, 8},
// {9, 10,11,12},
// {13,14,15,16}

class Solution2 {
    int rob(vector<int>& nums) {
        vector<int> dp;
        int x = nums.size();
        for (int i = 0; i < x; i++)
        {
            if (i == 0)dp.push_back(nums[0]);
            else if (i == 1)dp.push_back(max(nums[0], nums[1]));
            else
            {
                if (nums[i] + dp[i - 2] > dp[i - 1])dp.push_back(nums[i] + dp[i - 2]);
                else dp.push_back(dp[i - 1]);
            }
        }
        if (x == 1)
        {
            return dp[0];
        }
        if (x == 2)
        {
            return dp[0] > dp[1] ? dp[0] : dp[1];
        }
        return dp[x - 1];
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        auto mx = max_element(nums.begin(), nums.end());
        vector<int> dp(*mx + 1);
        for (int i : nums)
        {
            dp[i] += i;
        }
        return this->rob(dp);
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return dfs(0, n - 1, s, memo);
    }
    int dfs(int l, int r, string& s, vector<vector<int>>& memo) {
        if (l > r) return 0;
        if (l == r) return 1;
        if (memo[l][r] != -1) return memo[l][r];

        if (s[l] == s[r])
            memo[l][r] = 2 + dfs(l + 1, r - 1, s, memo);
        else
            memo[l][r] = max(dfs(l + 1, r, s, memo), dfs(l, r - 1, s, memo));

        return memo[l][r];
    }
};

//1,2,3
//4,5,6
//7,8,9

int main()
{
    Solution s1;
    //vector<vector<int>> matrix = { {1,2,3},{4,5,6},{7,8,9 } };
    //vector<vector<int>> matrix2 = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
    //s1.rotate(matrix2);
    //vector<int> v = {2, 3, 1, 1, 4};
    //s1.canJump(v);4
    //s1.tribonacci(5);
    //vector<int> matrix = { 10,15,20 };
    //s1.minCostClimbingStairs(matrix);
    vector<int> matrix = { 2, 7, 9, 3, 1 };
    s1.rob(matrix);
    return 0;
}
