#if 1

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

class Soultion2
{
public:
	int ans = 0;
	vector<vector<int>> directions = {
	{-1, 0}, {1, 0}, {0, -1}, {0, 1},
	{-1, -1}, {-1, 1}, {1, -1}, {1, 1}
	};
	int m;
	int n;
	int max_square(vector<vector<int>> square)
	{
		ans = 0;
		m = square.size();
		n = square[0].size();

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (square[i][j] == 1)
				{
					bfs(i, j, square);
				}
			}
		}
		return ans;
	}
private:
	void bfs(int i, int j, vector<vector<int>> &square)
	{
		int min_m = i;
		int min_n = j;
		int max_m = i;
		int max_n = j;
		queue<vector<int>> q;
		q.push({ i,j });
		square[i][j] = 0;
		while (!q.empty())
		{
			int mm = q.front()[0];
			int nn = q.front()[1];
			q.pop();

			min_m = min(min_m, mm);
			max_m = max(max_m, mm);
			min_n = min(min_n, nn);
			max_n = max(max_n, nn);

			for (auto& dir : directions) 
			{
				int mmm = mm + dir[0];
				int nnn = nn + dir[1];

				if (mmm >= 0 && mmm < m && nnn >= 0 && nnn < n && square[mmm][nnn] == 1) 
				{
					square[mmm][nnn] = 0;
					q.push({ mmm, nnn });
				}
			}
		}
		ans = max(ans, (max_n - min_n + 1) * (max_m - min_m + 1));
		return;
	}
};


int main()
{
	Soultion2 x;
	vector<vector<int>> grid1 = {
	{0, 0, 0},
	{0, 1, 1},
	{1, 1, 0}
	};
	vector<vector<int>> grid2 = 
	{
		{0, 1, 0, 0},
		{1, 1, 1, 0},
		{0, 1, 0, 0},
		{0, 0, 0, 0}
	};
	vector<vector<int>> grid3 = {
	{1, 1, 1},
	{1, 1, 1},
	{1, 1, 1}
	};
	vector<vector<int>> grid4 = {
		{1,1},
		{0,0}
	};
	vector<vector<int>> grid5 = {
		{1,0},
		{1,0}
	};
	vector<vector<int>> grid6 = {
		{1,0},
		{0,1}
	};
	vector<vector<int>> grid7 = {
	{1,0,0,0,1,1,1,0,1},
	{0,1,0,0,0,0,1,0,0},
	{0,0,0,0,0,0,1,0,0},
	{0,0,0,0,0,0,1,0,0},
	{0,1,0,0,0,0,1,0,0},
	{0,1,0,0,0,0,1,0,0},

	};
	//std::cout << x.max_square(grid4) << endl;
	//std::cout << x.max_square(grid5) << endl;
	std::cout << x.max_square(grid7) << endl;

	return 0;
}

#endif