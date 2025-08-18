
#include <iostream>
#include <vector>
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
};
// {1, 2, 3, 4},
// {5, 6, 7, 8},
// {9, 10,11,12},
// {13,14,15,16}



//1,2,3
//4,5,6
//7,8,9

int main()
{
    Solution s1;
    //vector<vector<int>> matrix = { {1,2,3},{4,5,6},{7,8,9 } };
    //vector<vector<int>> matrix2 = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
    //s1.rotate(matrix2);
    vector<int> v = {2, 3, 1, 1, 4};
    s1.canJump(v);
    return 0;
}
