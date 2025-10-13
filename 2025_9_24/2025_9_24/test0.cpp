#if 1

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class StackOfPlates {
public:
    vector<stack<int>> v;
    int num = 0;
    int size;

    StackOfPlates(int cap)
    {
        size = cap;
        if (cap > 0) v.push_back(stack<int>());
    }

    void push(int val) {
        if (v.empty()) {
            v.push_back(stack<int>());
            num = 0;
        }

        if (v[num].size() == size) {
            num++;
            v.push_back(stack<int>());
        }
        v[num].push(val);
    }

    int pop() {
        if (v.empty()) return -1;
        while (!v.empty() && v[num].empty()) {
            v.pop_back();
            num--;
        }

        if (v.empty()) return -1;

        int temp = v[num].top();
        v[num].pop();

        if (v[num].empty()) {
            v.pop_back();
            num--;
        }

        return temp;
    }

    int popAt(int index) {
        if (index < 0 || index >= (int)v.size()) return -1;
        if (v[index].empty()) return -1;

        int temp = v[index].top();
        v[index].pop();

        if (v[index].empty()) {
            v.erase(v.begin() + index);
            num = (int)v.size() - 1;
        }

        return temp;
    }
};
class SortedStack {
    vector<int> v;
public:
    SortedStack() {
        v.clear();
    }

    void push(int val) {
        v.push_back(val);
        sort(v.begin(), v.end());
        return;
    }

    void pop() {
        if (!v.empty())v.erase(v.begin());
    }

    int peek() {
        if (v.empty())return -1;
        return v[0];
    }

    bool isEmpty() {
        return v.empty();
    }
};
class AnimalShelf {
public:
    vector<vector<int>> v;
    AnimalShelf() {

    }

    void enqueue(vector<int> animal) {
        v.push_back(animal);
    }

    vector<int> dequeueAny() {
        vector<int> temp = { -1,-1 };
        if (v.empty())return temp;
        temp = v[0];
        v.erase(v.begin());
        return temp;
    }

    vector<int> dequeueDog() {
        int size = v.size();
        vector<int> temp = { -1,-1 };
        for (int i = 0; i < size; i++)
        {
            if (v[i][1] == 1)
            {
                temp = v[i];
                v.erase(v.begin() + i);
                break;
            }
        }
        return temp;
    }

    vector<int> dequeueCat() {
        int size = v.size();
        vector<int> temp = { -1,-1 };
        for (int i = 0; i < size; i++)
        {
            if (v[i][1] == 0)
            {
                temp = v[i];
                v.erase(v.begin() + i);
                break;
            }
        }
        return temp;
    }
};
class Solution0 {
public:
    int m;
    int n;
    int num;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        m = image.size();
        n = image[0].size();
        num = image[sr][sc];
        finding(image, sr, sc, newColor);
        return image;
    }

    void finding(vector<vector<int>>& image, int sr, int sc, int newColor)
    {
        if (image[sr][sc] == newColor)return;
        if (image[sr][sc] == num)image[sr][sc] = newColor;
        else return;
        if (sr + 1 < m)finding(image, sr + 1, sc, newColor);
        if (sr - 1 >= 0)finding(image, sr - 1, sc, newColor);
        if (sc + 1 < n)finding(image, sr, sc + 1, newColor);
        if (sc - 1 >= 0)finding(image, sr, sc - 1, newColor);
        return;
    }
};
class Solution1 {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        finding("", n, n);//n « £”‡ ˝¡ø
        return ans;
    }
    void finding(string S, int front, int back)
    {
        if (front < 0 || back < 0)return;
        if (front == 0 && back == 0)
        {
            ans.push_back(S);
            return;
        }
        if (front > back)return;
        finding(S + '(', front - 1, back);
        finding(S + ')', front, back - 1);
        return;
    }
};
class Solution2 {
public:
    vector<string> permutation(string S) {
        int size = S.size();//a b c d
        vector<string> ans;
        ans.push_back(S);
        for (int i = 0; i < size - 1; i++)
        {
            int temp = ans.size();
            for (int j = i + 1; j < size; j++)
            {
                for (int k = 0; k < temp; k++)
                {
                    string x = ans[k];
                    swap(x[i], x[j]);
                    ans.push_back(x);
                }
            }
        }
        set<string>temp(ans.begin(), ans.end());
        vector<string> a(temp.begin(), temp.end());
        return a;
    }
};
class Solution3 {
public:
    vector<string> permutation(string S) {
        int size = S.size();//a b c d
        vector<string> ans;
        ans.push_back(S);
        for (int i = 0; i < size - 1; i++)
        {
            int temp = ans.size();
            for (int j = i + 1; j < size; j++)
            {
                for (int k = 0; k < temp; k++)
                {
                    string x = ans[k];
                    swap(x[i], x[j]);
                    ans.push_back(x);
                }
            }
        }
        return ans;
    }
};
class Solution4 {
public:
    int waysToChange(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            if (i > 24)
            {
                dp[i] = dp[i - 25] + dp[i - 10] + dp[i - 5] + dp[i - 1];
            }
            else if (i > 9)
            {
                dp[i] = dp[i - 10] + dp[i - 5] + dp[i - 1];
            }
            else if (i > 4)
            {
                dp[i] = dp[i - 5] + dp[i - 1];
            }
            else
            {
                dp[i] = dp[i - 1];
            }
        }
        return dp[n];
    }
};
class Solution5 {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int ptr = m + n - 1;
        m = m - 1;
        n = n - 1;
        while (n >= 0)
        {
            if (m == -1 || A[m] < B[n])
            {
                A[ptr] = B[n];
                ptr--;
                n--;
            }
            else
            {
                A[ptr] = A[m];
                ptr--;
                m--;
            }
        }
        return;
    }
};
class Solution6 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string, vector<int>> m;
        for (int i = 0; i < strs.size(); i++)
        {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            m[temp].push_back(i);
        }
        for (auto it : m)
        {
            vector<string> temp;
            for (int i = 0; i < it.second.size(); i++)
            {
                temp.push_back(strs[it.second[i]]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
class Solution7 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty())return false;
        if (matrix[0].empty())return false;

        int m = matrix.size();
        int n = matrix[0].size();
        int len_min = 0;
        int roll_min = 0;
        int len_max = 0;
        int roll_max = 0;


        int flag = 1;
        int total = 0;
        for (int i = 0; i < m; i++)
        {
            if (flag)
            {
                if (matrix[i][0] <= target && matrix[i][n - 1] >= target)
                {
                    flag = 0;
                    roll_min = i;
                }
            }
            else total += 1;
        }
        roll_max = roll_min + total;

        flag = 1;
        total = 0;
        for (int i = 0; i < n; i++)
        {
            if (flag)
            {
                if (matrix[0][i] <= target && matrix[m - 1][i] >= target)
                {
                    flag = 0;
                    len_min = i;
                }
            }
            else total += 1;
        }
        len_max = len_min + total;

        for (int i = roll_min; i <= roll_max; i++)
        {
            for (int j = len_min; j <= len_max; j++)
            {
                if (matrix[i][j] == target)return true;
            }
        }
        return false;
    }
};
class Solution8 {
public:
    int findString(vector<string>& words, string s) {
        int lptr = 0;
        int rptr = words.size() - 1;
        while (lptr <= rptr)
        {
            while (words[lptr] == "")lptr++;
            while (words[rptr] == "")rptr--;
            int temp = (rptr + lptr) / 2;
            while (words[temp] == "")temp--;
            if (words[temp] > s)rptr = temp - 1;
            else if (words[temp] < s)lptr = temp + 1;
            else return temp;
        }
        return -1;
    }
};
class Solution9 {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int>temp = nums;
        sort(temp.begin(), temp.end());
        int size = temp.size();
        int state = 0;
        for (int i = 0; i < size; i++)
        {
            if (state == 0)
            {
                nums[i] = temp[i / 2 + size / 2];
                state = 1;
            }
            else
            {
                nums[i] = temp[i / 2];
                state = 0;
            }
        }
        return;
    }
};
class Solution10 {
public:
    int flag = 1;
    bool isValidBST(TreeNode* root, long left = LONG_MIN, long right = LONG_MAX) {
        if (root == nullptr)return true;
        long x = root->val;
        return left < x && x < right && isValidBST(root->left, left, x) && isValidBST(root->right, x, right);
    }
};

int main()
{
    vector<int> v = { 1,3,2 };
    Solution9 s;
    s.wiggleSort(v);
    return 0;
}
#endif