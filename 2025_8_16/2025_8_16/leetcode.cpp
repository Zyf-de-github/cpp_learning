#if 1
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>
using namespace std;

class Solution {
private:
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    };


public:
    TreeNode* invertTree(TreeNode* root) {
        finding(root);
        return root;
    }
    void finding(TreeNode* root)
    {
        if (root == nullptr)return;
        TreeNode* temp = new TreeNode();
        temp = root->left;
        root->left = root->right;
        root->right = temp;
        finding(root->right);
        finding(root->left);
        return;
    }
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (i != nums[i])return i;
        }
        return n;
    }
    int firstBadVersion(int n) {
        int l = 1, r = n;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (isBadVersion(mid))
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
    int guessNumber(int n) {
        int l = 1, r = n;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (guess(mid) == 1)
            {
                l = mid + 1;
            }
            else if (guess(mid) == -1)
            {
                r = mid;
            }
            else
            {
                return mid;
            }
        }
        return l;
    }
    bool isPerfectSquare(int num) {
        long x = num;
        while (x * x > num)
        {
            x = (x + num / x) / 2;
        }
        return x * x == num;
    }
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> r;
        map<char, int> m;
        for (char c = 'a'; c <= 'z'; c++)
        {
            r[c] = 0;
            m[c] = 0;
        }
        for (auto it : ransomNote)
        {
            r[it]++;
        }
        for (auto it : magazine)
        {
            m[it]++;
        }
        for (char c = 'a'; c <= 'z'; c++)
        {
            if (r[c] > m[c])return false;
        }
        return true;
    }
};


#endif