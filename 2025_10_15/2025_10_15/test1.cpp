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
using namespace std;

class Solution0 {
public:
    string toLowerCase(string s) {
        for (int i = 0; i < s.size(); i++)
        {
            if ((int)s[i] <= 90 && (int)s[i] >= 65)
            {
                char a = s[i];
                a = (char)((int)a + 32);
                s[i] = a;
            }
        }
        return s;
    }
};
class Solution1 {
public:
    int calPoints(vector<string>& operations) {
        vector<int> v;
        for (int i = 0; i < operations.size(); i++)
        {
            if (operations[i] == "C")v.erase(v.begin() + i);
            else if (operations[i] == "D")v.push_back(2 * v[v.size() - 1]);
            else if (operations[i] == "+")v.push_back(v[v.size() - 2] + v[v.size() - 1]);
            else v.push_back(stoi(operations[i]));
        }
        int ans = 0;
        for (auto it : v)
        {
            ans += it;
        }
        return ans;
    }
};
class Solution2 {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for (auto it : moves)
        {
            if (it == 'R')x++;
            else if (it == 'L')x--;
            else if (it == 'U')y++;
            else y--;
        }
        return x == 0 && y == 0;
    }
};
class Solution3 {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<int>> arr(3, vector<int>(3, 0));
        for (int i = 0; i < moves.size(); i++)
        {
            if (i % 2 == 0)arr[moves[i][0]][moves[i][1]] = 1;
            if (i % 2 == 1)arr[moves[i][0]][moves[i][1]] = 2;
            int temp = finding(arr);
            if (temp == 1)return "A";
            if (temp == 2)return "B";
        }
        if (moves.size() < 9)return "Pending";
        return "Draw";
    }
    int finding(vector<vector<int>>& arr)
    {
        if (arr[0][0] != 0 && arr[0][0] == arr[0][1] && arr[0][1] == arr[0][2])return arr[0][0];
        if (arr[1][0] != 0 && arr[1][0] == arr[1][1] && arr[1][1] == arr[1][2])return arr[1][0];
        if (arr[2][0] != 0 && arr[2][0] == arr[2][1] && arr[2][1] == arr[2][2])return arr[2][0];
        if (arr[0][0] != 0 && arr[0][0] == arr[1][0] && arr[1][0] == arr[2][0])return arr[0][0];
        if (arr[0][1] != 0 && arr[0][1] == arr[1][1] && arr[1][1] == arr[2][1])return arr[0][1];
        if (arr[0][2] != 0 && arr[0][2] == arr[1][2] && arr[1][2] == arr[2][2])return arr[0][2];
        if (arr[0][0] != 0 && arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2])return arr[0][0];
        if (arr[0][2] != 0 && arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0])return arr[0][2];
        return 0;
    }
};
class Solution4 {
public:
    bool isRobotBounded(string instructions) {
        int state = 0;//0北 1东 2南 3西
        int x = 0, y = 0;
        for (int i = 0; i < instructions.size(); i++)
        {
            if (instructions[i] == 'L')
            {
                state = state + 4 - 1;
                state %= 4;
            }
            else if (instructions[i] == 'R')
            {
                state = state + 1;
                state %= 4;
            }
            else if (instructions[i] == 'G')
            {
                if (state == 0)y++;
                if (state == 1)x++;
                if (state == 2)y--;
                if (state == 3)x--;
            }
        }
        return !((x != 0 || y != 0) && state == 0);
    }
};
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;
        for (int i = 0; i < accounts.size(); i++)
        {
            int temp = 0;
            for (int j = 0; j < accounts[0].size(); j++)
            {
                temp += accounts[i][j];
            }
            ans = max(ans, temp);
        }
        return ans;
    }
};
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans = 0;
        int size = mat.size();
        for (int i = 0; i < size; i++)
        {
            ans += mat[i][i];
            ans += mat[i][size - 1 - i];
        }
        if (size % 2)ans -= mat[size / 2][size / 2];
        return ans;
    }
};
class Solution {
public:
    int countOdds(int low, int high) {
        return (high + 1) / 2 - low / 2;
    }
};
class Solution {
public:
    double average(vector<int>& salary) {
        int nmax = INT_MIN;
        int nmin = INT_MAX;
        int ans = 0;
        for (auto it : salary)
        {
            nmin = min(nmin, it);
            nmax = max(nmax, it);
            ans += it;
        }
        return (ans - nmin - nmax) / (salary.size() - 2.0);
    }
};
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int m5 = 0;
        int m10 = 0;
        int m20 = 0;
        for (auto it : bills)
        {
            if (it == 5)m5++;
            else if (it == 10)
            {
                m10++;
                m5--;
            }
            else
            {
                m20++;
                if (m10 > 0)
                {
                    m10--;
                    m5--;
                }
                else
                {
                    m5 -= 3;
                }
            }
            if (m5 < 0 || m10 < 0 || m20 < 0)return false;
        }
        return true;
    }
};
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        for (int i = size - 1; i >= 2; i--)
        {
            if (nums[i - 1] + nums[i - 2] > nums[i])return nums[i - 1] + nums[i - 2] + nums[i];
        }
        return 0;
    }
};
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (coordinates[0][0] == coordinates[1][0])
        {
            for (int i = 2; i < coordinates.size(); i++)
            {
                if (coordinates[i][0] != coordinates[0][0])return false;
            }
            return true;
        }
        if (coordinates[0][1] == coordinates[1][1])
        {
            for (int i = 2; i < coordinates.size(); i++)
            {
                if (coordinates[i][1] != coordinates[0][1])return false;
            }
            return true;
        }
        double x1 = coordinates[0][0];
        double y1 = coordinates[0][1];
        double x2 = coordinates[1][0];
        double y2 = coordinates[1][1];
        double k = (y1 - y2) / (x1 - x2);
        double b = y1 - k * x1;
        for (int i = 2; i < coordinates.size(); i++)
        {
            if (coordinates[i][1] != k * coordinates[i][0] + b)return false;
        }
        return true;
    }
};














#endif