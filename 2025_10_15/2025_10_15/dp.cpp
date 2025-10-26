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
#include <unordered_set>
#include <random>
using namespace std;


 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution0 {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty())return NULL;
        int x = 0;
        for (int i = 0; i < inorder.size(); i++)
        {
            if (preorder[0] == inorder[i])
            {
                x = i;
                break;
            }
        }
        TreeNode* head = new TreeNode(preorder[0]);
        vector<int> preorder_left(preorder.begin() + 1, preorder.begin() + x + 1);
        vector<int> preorder_right(preorder.begin() + x + 1, preorder.end());

        vector<int> inorder_left(inorder.begin(), inorder.begin() + x);
        vector<int> inorder_right(inorder.begin() + x + 1, inorder.end());
        head->left = buildTree(preorder_left, inorder_left);
        head->right = buildTree(preorder_right, inorder_right);
        return head;
    }
};
class Solution1 {
public:
    vector<long long>memo;
    int size;
    long long mostPoints(vector<vector<int>>& questions) {
        size = questions.size();
        memo.assign(size, -1);
        return dfs(0, questions);
    }
    long long dfs(int i, vector<vector<int>>& questions)
    {
        if (i >= size)return 0;
        if (memo[i] != -1)return memo[i];
        long long x1 = dfs(i + 1, questions);
        long long x2 = dfs(i + questions[i][1] + 1, questions) + questions[i][0];
        x1 > x2 ? memo[i] = x1 : memo[i] = x2;
        return memo[i];
    }
};
class Solution2 {
public:

    int coinChange(vector<int>& coins, int amount) {
        if (!amount)return 0;
        int size = coins.size();
        vector<int> memo(amount + 1, -1);
        sort(coins.begin(), coins.end());
        for (int i = 1; i <= amount; i++)
        {
            int temp = -1;
            for (auto it : coins)
            {
                if (i - it < 0)break;
                else if (i - it == 0)
                {
                    temp = 1;
                    break;
                }
                else if (memo[i - it] != -1 && temp == -1)temp = memo[i - it]+1;
                else if (memo[i - it] != -1 && temp != -1)temp = min(temp, memo[i - it]+1);
            }
            memo[i] = temp;
        }
        return memo[amount];
    }
};
class Solution3 {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<long long> memo(high + 1, 0);
        for (int i = 1; i <= high; i++)
        {
            long long temp = 0;
            if (i == zero)temp += 1;
            if (i == one)temp += 1;
            if (i - zero > 0)temp += memo[i - zero];
            if (i - one > 0)temp += memo[i - one];
            memo[i] = temp % (1000000000 + 7);
        }
        long long ans = 0;
        for (int i = low; i <= high; i++)
        {
            ans += memo[i];
            ans %= 1000000000 + 7;
        }
        return ans;
    }
};
class Solution4 {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        flatten(root->left);
        flatten(root->right);
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        root->right = left;
        root->left = nullptr;

        TreeNode* p = root;
        while (p->right) p = p->right;

        p->right = right;
    }
};
class Solution5 {
public:
    vector<int>v;
    vector<int> rightSideView(TreeNode* root) {
        int n = 1;
        finding(root, n);
        return v;
    }
    void finding(TreeNode* root, int n)
    {
        if (root == nullptr)return;
        if (v.size() < n)v.push_back(root->val);
        finding(root->right, n + 1);
        finding(root->left, n + 1);
    }
};
class Solution6 {
public:
    vector<int> v;
    int n = 0;
    int kthSmallest(TreeNode* root, int k) {
        finding(root, k);
        return v[k - 1];
    }
    void finding(TreeNode* root, int& k)
    {
        if (root == nullptr)return;
        if (n != k)finding(root->left, k);
        v.push_back(root->val);
        n++;
        if (n != k)finding(root->right, k);
    }
};
class Solution7 {
public:
    bool isValidBST(TreeNode* root, long long left = LLONG_MIN, long long right = LLONG_MAX) {
        if (root == nullptr)return true;
        long long x = root->val;
        return x > left && x < right && isValidBST(root->left, left, x) && isValidBST(root->right, x, right);
    }
};
class Solution8 {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>> m;
        vector<int> v(numCourses, 0);
        vector<int> ans;

        //构建课程
        for (int i = 0; i < numCourses; i++)
        {
            m[i] = {};
        }
        for (int i = 0; i < prerequisites.size(); i++)
        {
            m[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        //构建入度
        for (int i = 0; i < numCourses; i++)
        {
            v[i] = m[i].size();
        }

        int flag = 0;//是否更改了元素
        while (ans.size() != numCourses)
        {
            if (flag)return{};
            flag = 1;
            for (int i = 0; i < numCourses; i++)
            {
                if (v[i] == 0)
                {
                    ans.push_back(i);
                    flag = 0;
                    v[i] = -1;
                    for (auto it : m)
                    {
                        if (find(it.second.begin(), it.second.end(), i) != it.second.end())v[it.first]--;
                    }
                }
            }
        }
        return ans;
    }
};


int main()
{
    Solution8 s;
    vector<vector<int>> v = { {1,0},{2,0} , {3,1}, {3,2} };
    s.findOrder(4, v);
    return 0;
}
#endif