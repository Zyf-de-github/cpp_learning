#if 1

#include <vector>
#include <algorithm>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
     };

class Solution1 {
private:
    vector<int> x;
public:
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        x = nums;
        return build(0, nums.size() - 1);
    }
    TreeNode* build(int begin, int end)
    {
        if (begin > end)return nullptr;
        TreeNode* root = new TreeNode(x[(begin + end) / 2]);
        root->left = build(begin, (begin + end) / 2 - 1);
        root->right = build((begin + end) / 2 + 1, end);
        return root;
    }
};

class Solution2 {
public:
    vector<int> findClosedNumbers(int num) {
        int small = num;
        if (num == 1) small = -1;
        int big = num;
        if (num == 2147483647) big = -1;

        if (big != -1) {
            for (int i = 1; i < 32; i++) {
                if ((!(num & (1 << i))) && (num & (1 << (i - 1)))) {
                    big |= 1 << i;
                    big &= ~(1 << (i - 1));

                    int ones = __builtin_popcount(num & ((1 << (i - 1)) - 1));
                    big &= ~((1 << (i - 1)) - 1);
                    big |= (1 << ones) - 1;
                    break;
                }
            }
        }

        if (small != -1) {
            for (int i = 30; i >= 0; i--) {
                if ((!(num & (1 << i))) && (num & (1 << (i + 1)))) {
                    small |= 1 << i;
                    small &= ~(1 << (i + 1));

                    int ones = __builtin_popcount(num & ((1 << i) - 1));
                    small &= ~((1 << i) - 1);
                    small |= ((1 << ones) - 1) << (i - ones);
                    break;
                }
            }
        }
        return { big, small };
    }
};



class Solution {
public:
    vector<int> findClosedNumbers(int num)
    {
        int larger = findLarger(num);
        int smaller = findSmaller(num);

        return { larger,smaller };
    }
    int exchangeBits(int num) {
        int c0 = 0;
        int c1 = 0;
        int c = 0;
        for (int i = 0; i < 32; i += 2)
        {
            c0 |= num & (1 << i);
            c1 |= num & (1 << (i + 1));
            int temp = 0;
            temp |= 1 << i;
            temp |= 1 << (i + 1);

            num &= (~temp);
            num |= c0 << 1;
            num |= c1 >> 1;
        }
        return num;
    }
private:
    int findLarger(int num) {
        int c = num;
        int c0 = 0;
        int c1 = 0;

        while (((c & 1) == 0) && (c != 0)) {
            c0++;
            c >>= 1;
        }
        while ((c & 1) == 1) {
            c1++;
            c >>= 1;
        }

        if (c0 + c1 == 31 || c0 + c1 == 0) {
            return -1;
        }

        int pos = c0 + c1;

        num |= (1 << pos);
        num &= ~((1 << pos) - 1);
        num |= ((1 << (c1 - 1)) - 1);

        return num;
    }
    int findSmaller(int num)
    {
        int c = num;
        int c1 = 0;
        int c0 = 0;

        while ((c & 1) == 1)
        {
            c1++;
            c >>= 1;
        }

        if (c == 0) return -1;

        while (((c & 1) == 0) && (c != 0))
        {
            c0++;
            c >>= 1;
        }

        int pos = c0 + c1;

        num &= ~((1 << (pos + 1)) - 1);
        int mask = (1 << (c1 + 1)) - 1;
        num |= mask << (c0 - 1);

        return num;
    }
};

#endif