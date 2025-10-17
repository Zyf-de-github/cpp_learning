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


struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};


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
class Solution5 {
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
class Solution6 {
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
class Solution7 {
public:
    int countOdds(int low, int high) {
        return (high + 1) / 2 - low / 2;
    }
};
class Solution8 {
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
class Solution9 {
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
class Solution10 {
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
class Solution11 {
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
class Solution12 {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")return "0";
        int size1 = num1.size();
        int size2 = num2.size();
        vector<int> ans(size1 + size2, 0);
        for (int i = size1 - 1; i >= 0; i--)
        {
            for (int j = size2 - 1; j >= 0; j--)
            {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + ans[i + j + 1];
                ans[i + j + 1] = sum % 10;
                ans[i + j] += sum / 10;
            }
        }
        string x;
        int flag = 1;
        for (auto it : ans)
        {
            if (it == 0 && flag) continue;
            flag = 0;
            x = x + to_string(it);
        }
        return x;
    }
};
class Solution13 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        int temp = 0;
        ListNode* l3 = new ListNode(0);
        ListNode* ptr = l3;
        while (l1 != nullptr || l2 != nullptr)
        {
            if (l1 == nullptr)
            {
                int num = l2->val + temp;
                temp = num / 10;
                ptr->val = num % 10;
                ListNode* x = new ListNode(0);
                ptr->next = x;
                ptr = x;
            }
            else if (l2 == nullptr)
            {
                int num = l1->val + temp;
                temp = num / 10;
                ptr->val = num % 10;
                ListNode* x = new ListNode(0);
                ptr->next = x;
                ptr = x;
            }
            else
            {
                int num = l1->val + l2->val + temp;
                temp = num / 10;
                ptr->val = num % 10;
                ListNode* x = new ListNode(0);
                ptr->next = x;
                ptr = x;
            }
            if (l1)l1 = l1->next;
            if (l2)l2 = l2->next;
        }
        if (temp != 0)
        {
            ptr->val = temp;
            ListNode* x = new ListNode(0);
            ptr->next = x;
            ptr = x;
        }
        l3 = reverseList(l3);
        return l3->next;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* list = new ListNode();
        while (head)
        {
            list->val = head->val;
            ListNode* temp = new ListNode();
            temp->next = list;
            list = temp;
            head = head->next;
        }
        return list->next;
    }
};
class Solution14 {
public:
    string tictactoe(vector<string>& board) {
        int n = board.size();
        char winner = findWinner(board, n);

        bool hasEmpty = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == ' ') {
                    hasEmpty = true;
                    break;
                }
            }
            if (hasEmpty) break;
        }

        if (winner != ' ') return string(1, winner);
        return hasEmpty ? "Pending" : "Draw";
    }

private:
    char findWinner(const vector<string>& board, int n) {
        // 检查每一行
        for (int i = 0; i < n; i++) {
            char first = board[i][0];
            if (first == ' ') continue;
            bool same = true;
            for (int j = 1; j < n; j++) {
                if (board[i][j] != first) {
                    same = false;
                    break;
                }
            }
            if (same) return first;
        }

        // 检查每一列
        for (int j = 0; j < n; j++) {
            char first = board[0][j];
            if (first == ' ') continue;
            bool same = true;
            for (int i = 1; i < n; i++) {
                if (board[i][j] != first) {
                    same = false;
                    break;
                }
            }
            if (same) return first;
        }

        // 检查主对角线
        {
            char first = board[0][0];
            if (first != ' ') {
                bool same = true;
                for (int i = 1; i < n; i++) {
                    if (board[i][i] != first) {
                        same = false;
                        break;
                    }
                }
                if (same) return first;
            }
        }

        // 检查副对角线
        {
            char first = board[0][n - 1];
            if (first != ' ') {
                bool same = true;
                for (int i = 1; i < n; i++) {
                    if (board[i][n - 1 - i] != first) {
                        same = false;
                        break;
                    }
                }
                if (same) return first;
            }
        }

        return ' ';
    }
};

int main()
{

    return 0;
}


#endif