#if 1

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;



class Solution1 {
private:
    vector<vector<char>> x;
    int n;
    int m;
public:
    int numIslands(vector<vector<char>>& grid)
    {
        int num = 0;
        x = grid;
        m = grid.size();
        n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (x[i][j] == '0' || x[i][j] == '2')continue;
                else
                {
                    num++;
                    finding(i, j);
                }
            }
        }
        return num;
    }
    void finding(int i, int j)
    {
        if (x[i][j] == '1')
        {
            x[i][j] = '2';
            if (i + 1 < m) finding(i + 1, j);
            if (j + 1 < n) finding(i, j + 1);
            if (i - 1 >= 0) finding(i - 1, j);
            if (j - 1 >= 0) finding(i, j - 1);
        }
        return;
    }
};
class Solution2 {
private:
    int m, n;
    vector<vector<int>> grid;
public:
    int orangesRotting(vector<vector<int>>& x) {
        grid = x;
        m = grid.size();
        n = grid[0].size();

        int total = 0;

        while (true) {
            bool change = false; // �����Ƿ��б仯
            bool hasFresh = false; // �Ƿ�����������

            // ���ִ�Ⱦ
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 2) {
                        infect(i, j, change);
                    }
                    if (grid[i][j] == 1) {
                        hasFresh = true;
                    }
                }
            }

            if (!change) {            // û�б仯
                if (hasFresh) return -1; // ������������ -> �����ܸ�����
                else return total;       // û���������� -> ȫ�����ã����ؽ��
            }

            // �ѱ������õ����ӣ�3��ת����ʽ�������ӣ�2��
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 3) grid[i][j] = 2;
                }
            }

            total++; // ÿ�ֽ�����ʱ��+1
        }
    }
    void infect(int i, int j, bool& change) {
        if (i + 1 < m && grid[i + 1][j] == 1) { grid[i + 1][j] = 3; change = true; }
        if (i - 1 >= 0 && grid[i - 1][j] == 1) { grid[i - 1][j] = 3; change = true; }
        if (j + 1 < n && grid[i][j + 1] == 1) { grid[i][j + 1] = 3; change = true; }
        if (j - 1 >= 0 && grid[i][j - 1] == 1) { grid[i][j - 1] = 3; change = true; }
    }
};
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int x = nums.size();
        for (int i = 1; i < x; i++)
        {
            if (nums[i] == nums[i - 1])return nums[i];
        }
        return 0;
    }
};


int main()
{

    Solution test;

    return 0;
}

#endif