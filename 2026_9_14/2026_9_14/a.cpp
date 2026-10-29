#define _SILENCE_ALL_CXX20_DEPRECATION_WARNINGS
#include "test.h"
using namespace std;



class Solution20 {
public:
	int staffGroup(vector<int>& staff) {
		int num0 = 0, num1 = 0, ans = 0;
		for (auto it : staff)
		{
			if (it == 0)num0++;
			if (it == 1)num1++;
		}
		if (num0 <= num1)return num1;
		int temp = num0 - num1;
		return num1 + (temp % 3 ? temp / 3 + 1 : temp / 3);
	}
};
class Solution19 {
public:
	vector<int> findFluctuations(vector<int> memoryUsage, int k) {
		set<int>s;
		vector<int>ans;
		for (int i = 0; i < memoryUsage.size(); i++)
		{
			s.insert(memoryUsage[i]);
			if (i < k - 1)continue;
			ans.push_back(*s.rbegin() - *s.begin());
			s.erase(memoryUsage[i - k + 1]);
		}
		return ans;
	}
};
class Solution18 {
public:
	bool canEqualDistribution(vector<int> v, int k) {
		priority_queue<int> pq;
		int total = 0,num_max=0;
		sort(v.begin(), v.end(), [&](int a, int b) {return a > b; });
		for (auto it : v)total += it;
		if (total % k)return false;
		total /= k;
		for (int i = 0; i < k; i++)pq.push(0);
		for (auto it : v)
		{
			int temp = pq.top();
			pq.pop();
			temp -= it;
			if (-temp > total)return false;
			pq.push(temp);
		}
		while (!pq.empty())
		{
			int temp = pq.top();
			pq.pop();
			if (-temp != total)return false;
		}
		return true;
	}
};
class Solution17 {
public:
	int minimizeXor(int num1, int num2) {
		int num1_t = num1; int num2_t = num2;
		int cnt1 = 0, cnt2 = 0, ans = 0;
		while (num2_t)
		{
			if (num2_t & 1)cnt2++;
			num2_t >>= 1;
		}
		string num1_s;
		while (num1_t)
		{
			if (num1_t & 1)
			{
				num1_s = num1_s + '1';
				cnt1++;
			}
			else num1_s = num1_s + '0';
			num1_t >>= 1;
		}
		if (cnt1 == cnt2)return num1;

		int size = num1_s.size(), flag = 0;
		if (cnt1 > cnt2)flag = 1;
		int times = abs(cnt1 - cnt2),ptr = 0;
		while (times)
		{
			if	(ptr >= size ||
				(ptr < size && num1_s[ptr] == '1'&&flag==1)||
				(ptr < size && num1_s[ptr] == '0'&&flag==0))
			{
				ans += pow(2, ptr);
				times--;
			}
			ptr++;
		}
		int a = ans ^ num1;
		return a;
	}
};
class Solution16 {
public:
	int countTriplets(vector<int> arr) {
		if (arr.size() <= 1)return 0;
		vector<int> v;
		vector <tuple<int, int, int>>debug;
		v.emplace_back(0);
		int total = 0,ans=0;
		for (auto it : arr)
		{
			total = it ^ total;
			v.emplace_back(total);
		}
		//0 sum1 sum2
		for (int j = 1; j < v.size()-1; j++)
		{
			for (int i = 0; i < j; i++)
			{
				for (int k = j + 1; k < v.size(); k++)
				{
					if ((v[i] ^ v[j]) == (v[j] ^ v[k]))
					{
						ans++;
						debug.emplace_back(make_tuple(i,j,k ));
					}
				}
			}
		}
		return ans;
	}
};
class Solution15 {
public:
	int minOperations(vector<int>& nums, int k) {
		int total = 0, ans = 0;
		for (auto it : nums)total ^= it;
		total ^= k;
		while (total)
		{
			if (total & 1)ans++;
			total >>= 1;
		}
		return ans;
	}
};
class Solution14 {
public:
	bool containsCycle(vector<vector<char>> grid) {
		m = grid.size();
		n = grid[0].size();
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (flag || grid[i][j] == '0')continue;
				else func(grid, i, j, grid[i][j],"begin");
			}
		}
		return flag;
	}
private:
	bool flag = false;
	int m, n;
	void func(vector<vector<char>>& grid, int i, int j, char x,string str)
	{
		if (i<0||i>=m||j<0||j>=n)return;
		if (grid[i][j] == '1')
		{
			flag = true;
			return;
		}
		if (grid[i][j] != x)return;
		grid[i][j] = '1';
		if (!flag && str != "left")func(grid, i, j + 1, x, "right");
		if (!flag && str != "right")func(grid, i, j - 1, x, "left");
		if (!flag && str != "down")func(grid, i + 1, j, x, "up");
		if (!flag && str != "up")func(grid, i - 1, j , x, "down");
		grid[i][j] = '0';
		return;
	}
};
class Solution13 {
public:
	vector<vector<char>> updateBoard(vector<vector<char>> board, vector<int> click) {
		m = board.size();
		n = board[0].size();
		if (board[click[0]][click[1]] == 'M')
		{
			board[click[0]][click[1]] = 'X';
			return board;
		}
		int m_num = finding_num(board, click[0], click[1]);
		if (m_num != 0)board[click[0]][click[1]] = m_num + '0';
		else func(board, click[0], click[1]);
		return board;
	}
private:
	int m, n;
	char finding_num(vector<vector<char>>& board, int i, int j)
	{
		if (i < 0 || i >= m || j<0 || j>=n)return -1;
		int temp = 0;
		for (int _i = -1; _i <= 1; _i++)
		{
			if (i + _i < 0 || i + _i >= m)continue;
			for (int _j = -1; _j <= 1; _j++)
			{
				if (j + _j < 0 || j + _j >= n)continue;
				if (board[i + _i][j + _j] == 'M')temp++;
			}
		}
		return temp;
	}
	void func(vector<vector<char>>& board, int i, int j)
	{
		int num = finding_num(board, i, j);
		if (num == -1)return;
		else if (num != 0)board[i][j] = num + '0';
		else
		{
			board[i][j] = 'B';
			for (int _i = -1; _i <= 1; _i++)
			{
				if (i + _i < 0 || i + _i >= m)continue;
				for (int _j = -1; _j <= 1; _j++)
				{
					if (j + _j < 0 || j + _j >= n)continue;
					if (board[i + _i][j + _j] == 'E')func(board, i + _i, j + _j);
				}
			}
		}
	}
};
class Solution12 {
public:
	int largestIsland(vector<vector<int>> grid) {
		m = grid.size();
		n = grid[0].size();
		v.assign(m, vector<int>(n));
		int ans = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (grid[i][j] == 1)
				{
					id++;
					dfs_func(grid, i, j);
					ans = max(ans, size);
					mp[id] = size;
					size = 0;
				}
			}
		}

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (v[i][j] == 0)
				{
					int temp = 0;
					unordered_map<int, int> um;
					if (i - 1 >= 0 && v[i - 1][j] != 0)um[v[i - 1][j]] = mp[v[i - 1][j]];
					if (j - 1 >= 0 && v[i][j - 1] != 0)um[v[i][j - 1]] = mp[v[i][j - 1]];
					if (i + 1 < m && v[i + 1][j] != 0)um[v[i + 1][j]] = mp[v[i + 1][j]];
					if (j + 1 < n && v[i][j + 1] != 0)um[v[i][j + 1]] = mp[v[i][j + 1]];
					for (auto it : um)temp += it.second;
					ans = max(ans, temp+1);
				}
			}
		}
		return ans;
	}
private:
	int m = 0, n = 0, size = 0, id = 0;
	unordered_map<int, int> mp;
	vector<vector<int>> v;

	void dfs_func(vector<vector<int>>& grid, int i, int j)
	{
		if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0)return;
		else size++;
		grid[i][j] = 0;

		if (i - 1 >= 0)dfs_func(grid, i - 1, j);
		if (j - 1 >= 0)dfs_func(grid, i, j - 1);
		if (i + 1 < m)dfs_func(grid, i + 1, j);
		if (j + 1 < n)dfs_func(grid, i, j + 1);
		v[i][j] = id;
		return;
	}
};
class Solution11 {
public:
	int nearestExit(vector<vector<char>> maze, vector<int> entrance) {
		m = maze.size();
		n = maze[0].size();
		deque<node> dq;
		dq.push_back({ entrance[0],entrance[1],0 });
		maze[entrance[0]][entrance[1]] = '+';
		while (!dq.empty())
		{
			node cur = dq.front();
			dq.pop_front();
			if ((cur.i == 0 || cur.j == 0 || cur.i == m-1 || cur.j == n-1) && (cur.i != entrance[0] || cur.j != entrance[1]))return cur.size;
			if (cur.i - 1 >= 0 && maze[cur.i - 1][cur.j] == '.')
			{
				dq.push_back({ cur.i - 1, cur.j, cur.size + 1 });
				maze[cur.i - 1][cur.j] = '+';
			}
			if (cur.j - 1 >= 0 && maze[cur.i][cur.j - 1] == '.')
			{
				dq.push_back({ cur.i, cur.j - 1, cur.size + 1 });
				maze[cur.i][cur.j - 1] = '+';
			}
			if (cur.i + 1 < m && maze[cur.i + 1][cur.j] == '.')
			{
				dq.push_back({ cur.i + 1, cur.j, cur.size + 1 });
				maze[cur.i + 1][cur.j] = '+';
			}
			if (cur.j + 1 < n && maze[cur.i][cur.j + 1] == '.') 
			{
				dq.push_back({ cur.i, cur.j + 1, cur.size + 1 });
				maze[cur.i][cur.j + 1] = '+';
			}
		}
		return -1;
	}
private:
	typedef struct node
	{
		int i = 0;
		int j = 0;
		int size = 0;
	}node;
	int m = 0, n = 0;
};
class Solution10 {
public:
	int shortestPathBinaryMatrix(vector<vector<int>> grid) {
		if (grid[0][0] == 1)return -1;
		int m = grid.size(), n = grid[0].size();
		vector<vector<int>> v(m,vector<int>(n,-1));
		deque<pair<int, int>> dq;
		dq.push_back({ 0,0 });
		v[0][0] = 1;
		while (!dq.empty())
		{
			pair<int, int> temp = dq.front();
			dq.pop_front();
			for (int i = -1; i <= 1; i++)
			{
				for (int j = -1; j <= 1; j++)
				{
					int cur_i = temp.first + i, cur_j = temp.second + j;
					if (cur_i < 0 || cur_i >= m || cur_j < 0 || cur_j >= n)continue;//超出矩阵范围
					if (grid[cur_i][cur_j] == 1 || v[cur_i][cur_j] != -1)continue;//已经遍历过或者不可达
					v[cur_i][cur_j] = v[temp.first][temp.second] + 1;
					dq.push_back({ cur_i ,cur_j });
				}
			}
		}
		return v[m - 1][n - 1];
	}
};
class Solution9 {
public:
	int shortestBridge(vector<vector<int>> grid) {
		int ans = INT_MAX;
		int m = grid.size(), n = grid[0].size();
		vector<vector<int>> v(m, vector<int>(n, -1));
		pair<int, int> begin_ptr = { -1,-1 };
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (grid[i][j] == 1)
				{
					begin_ptr = { i,j };
					break;
				}
			}
			if (begin_ptr.first != -1)break;
		}
		deque<pair<int, int>>dq, temp;
		dq.push_back(begin_ptr);
		temp.push_back(begin_ptr);
		grid[begin_ptr.first][begin_ptr.second] = 0;
		int cnt = 0;
		while (!temp.empty())
		{
			pair<int, int>cur = temp.front();
			temp.pop_front();
			v[cur.first][cur.second] = cnt;
			if (cnt == 0)
			{
				if (cur.first - 1 >= 0  && grid[cur.first - 1][cur.second] == 1) { v[cur.first - 1][cur.second] = cnt; temp.push_back({ cur.first - 1 ,cur.second }); dq.push_back({cur.first - 1 ,cur.second });grid[cur.first - 1][cur.second] = 0; }
				if (cur.second - 1 >= 0 && grid[cur.first][cur.second - 1] == 1) { v[cur.first][cur.second - 1] = cnt; temp.push_back({ cur.first  ,cur.second - 1}); dq.push_back({cur.first  ,cur.second - 1});grid[cur.first][cur.second - 1] = 0; }
				if (cur.first + 1 < m   && grid[cur.first + 1][cur.second] == 1) { v[cur.first + 1][cur.second] = cnt; temp.push_back({ cur.first + 1 ,cur.second }); dq.push_back({cur.first + 1 ,cur.second });grid[cur.first + 1][cur.second] = 0; }
				if (cur.second + 1 < n  && grid[cur.first][cur.second + 1] == 1) { v[cur.first][cur.second + 1] = cnt; temp.push_back({ cur.first  ,cur.second + 1}); dq.push_back({cur.first  ,cur.second + 1});grid[cur.first][cur.second + 1] = 0; }
			}
		}
		while (!dq.empty())
		{
			pair<int, int>cur = dq.front();
			dq.pop_front();
			if (grid[cur.first][cur.second] == 1)
			{
				int see;
				return v[cur.first][cur.second] - 1;
			}
			if (cur.first - 1 >= 0  && v[cur.first - 1][cur.second] == -1){dq.push_back({ cur.first - 1 ,cur.second }); v[cur.first - 1 ][cur.second    ]=v[cur.first][cur.second]+1;} 
			if (cur.second - 1 >= 0 && v[cur.first][cur.second - 1] == -1){dq.push_back({ cur.first  ,cur.second - 1 });v[cur.first     ][cur.second - 1]=v[cur.first][cur.second]+1;}
			if (cur.first + 1 < m   && v[cur.first + 1][cur.second] == -1){dq.push_back({ cur.first + 1 ,cur.second }); v[cur.first + 1 ][cur.second    ]=v[cur.first][cur.second]+1;}
			if (cur.second + 1 < n  && v[cur.first][cur.second + 1] == -1){dq.push_back({ cur.first  ,cur.second + 1 });v[cur.first     ][cur.second + 1]=v[cur.first][cur.second]+1;}
		}
		return 0;
	}
};
//({{ 1, 1, 1, 1, 1, 0	},
//  { 1, 0, 0, 0, 0, 0	},
//  { 1, 0, 0, 0, 0, 0	},
//  { 1, 0, 0, 0, 0, 1	},
//  { 1, 0, 0, 0, 0, 1	},
//  { 1, 0, 0, 0, 0, 1	}});
//({{ 0, 1, 0},
//  { 0, 0, 0},
//  { 0, 0, 1}});
class Solution8 {
public:
	bool hasValidPath(vector<vector<char>> grid) {
		if (grid[0][0] == ')')return false;
		int m = grid.size(), n = grid[0].size();
		vector<vector<set<int>>> v(m, vector<set<int>>(n, set<int>()));
		v[0][0].insert(1);
		for (int i = 1; i < m; i++)
		{
			for (auto it : v[i-1][0])
			{
				int cur;
				if (grid[i][0] == '(')cur = 1;
				else cur = -1;
				if (cur + it >= 0)v[i][0].insert(cur + it);
			}
		}
		for (int i = 1; i < n; i++)
		{
			for (auto it : v[0][i-1])
			{
				int cur = it;
				if (grid[0][i] == '(')cur += 1;
				else cur -= 1;
				if (cur >= 0)v[0][i].insert(cur);
			}
		}
		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < n; j++)
			{
				int cur = 0;
				if (grid[i][j] == '(')cur = 1;
				else cur = -1;
				for (auto it : v[i][j - 1])
				{
					if (cur + it >= 0)v[i][j].insert(cur + it);
				}
				for (auto it : v[i - 1][j])
				{
					if (cur + it >= 0)v[i][j].insert(cur + it);
				}
			}
		}
		if (v[m - 1][n - 1].find(0) != v[m - 1][n - 1].end())return true;
		return false;
	}
};
//（ （ （
// ）（  ）
//（ （ （
//（ （  ）
class Solution7 {
public:
	bool validPartition(vector<int> nums) {
		int n = nums.size();
		vector<bool> dp(n+1, false);
		dp[0] = true;
		for (int i = 0; i < n; i++)
		{
			if (i >= 1 && nums[i] == nums[i - 1] && dp[i - 1])dp[i + 1] = true;
			if (i >= 2 && nums[i] == nums[i - 1] && nums[i] == nums[i - 2] && dp[i - 2])dp[i + 1] = true;
			if (i >= 2 && nums[i] == nums[i - 1] + 1 && nums[i] == nums[i - 2] + 2 && dp[i - 2])dp[i + 1] = true;
		}
		return dp[n];
	}
};
class Solution6 {
public:
	bool wordBreak(string s, vector<string> wordDict) {
		int n = s.size();
		vector<bool> dp(n + 1, false);
		dp[0] = true;
		for (int i = 0; i < n; i++)
		{
			for (auto it : wordDict)
			{
				int size = it.size();
				if (i + 1 < size)continue;
				string temp = s.substr(i - size + 1, size);
				if (it == temp && dp[i - size + 1])dp[i + 1] = true;
			}
		}
		return dp[n];
	}
};
class Solution5 {
public:
	int minCut(string s) {
		int n = s.size();
		if (n <= 1)return 0;
		vector<int>dp(n + 1, -1);
		dp[0] = 0;
		dp[1] = 0;
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				bool isPal = true;
				for (int l = j, r = i; l < r; ++l, --r)if (s[l] != s[r]) { isPal = false; break; }
				if (isPal && dp[j] != -1)
				{
					if (j == 0)
					{
						dp[i + 1] = 0;
						break;
					}
					else
					{
						if (dp[i + 1] == -1)dp[i + 1] = dp[j] + 1;
						else dp[i + 1] = min(dp[i + 1], dp[j] + 1);
						// dp[i + 1] = dp[j] + 1;
						// break;
					}
				}
			}
		}
		return dp[n];
	}
};
class Solution4 {
public:
	vector<int> nextGreaterElements(vector<int> nums) {
		int n = nums.size();
		stack<int> s;
		vector<int> ans(n,-1);
		for (int i = 0; i < 2 * n - 1; i++)
		{
			while (!s.empty() && nums[s.top()%n] < nums[i%n])
			{
				ans[s.top() % n] = nums[i%n];
				s.pop();
			}
			s.push(i);
		}
		return ans;
	}
};
// 3 2 1 4 2 3
class StockSpanner {
public:
	StockSpanner() {
		s = std::stack<int>();
		ptr = 0;
		v.clear();
	}
	stack<int> s;
	int ptr = 0;
	vector<int> v;
	int next(int price) {
		int ans = 0;
		v.push_back(price);
		while (!s.empty() && v[s.top()] <= price)
		{
			s.pop();
		}
		ans = ptr - (s.empty() ? -1 : s.top());
		s.push(ptr);
		ptr++;
		return ans;
	}
};


int main()
{
	//Solution s;
	//vector<int> v=s.findFluctuations({ 120, 150, 110, 180, 130, 160, 140, 170 }, 3);
	//vector<vector<char>> v = s.updateBoard({{'E', 'E', 'E', 'E', 'E'}, { 'E', 'E', 'M', 'E', 'E' }, { 'E', 'E', 'E', 'E', 'E' }, { 'E', 'E', 'E', 'E', 'E' }},{3,0});
	//cout << s.largestIsland({ { 1,1 }, { 1,0} });
	//cout << s.nearestExit({ {'+','+','.','+'},{'.','.','.','+'},{'+','+','+','.'}}, {1,2});
	//cout << s.nearestExit({ {'+','+','+'},{'.','.','.'},{'+','+','+'} }, { 1,0 });
	//cout << s.shortestBridge({{ 0, 1, 0},
	//						  { 0, 0, 0},
	//						  { 0, 0, 1} });
	//cout << s.hasValidPath({ {'(', '(', '('}, {')', '(', ')'}, {'(', '(', '('}, {'(', '(', ')'} });
	//cout << s.validPartition({ 5,6,7,8,9,10,11 });
	//cout << s.wordBreak("leetcode", { "leet", "code" });
	StockSpanner* x = new StockSpanner();
	cout<<x->next(1)<<' ';
	cout<<x->next(4)<<' ';
	cout<<x->next(3)<<' ';
	cout<<x->next(5)<<' ';
	cout<<x->next(5)<<' ';
	cout<<x->next(2)<<' ';
	cout<<x->next(3)<<' ';
	cout<<x->next(6)<<' ';


	return 0;
}