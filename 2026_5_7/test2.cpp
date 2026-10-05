#include <bits/stdc++.h>
using namespace std;

class Solution0 {
public:
    vector<int> beautifulArray(int n) 
    {
        ans.assign(n,1);
        n=n-1;
        func_single(0,n/2);
        if(n>0)func_double(n/2+1,n);
        int as=1;
        return ans;
    }
private:
    vector<int> ans;
    void func_single(int begin,int end)
    {
        if(begin!=end)func_single(begin,(begin+end)/2);
        if(begin!=end)func_double((begin+end)/2+1,end);
        for(int i=begin;i<=end;i++)ans[i]=ans[i]*2-1;
    }
    void func_double(int begin,int end)
    {
        if(begin!=end)func_single(begin,(begin+end)/2);
        if(begin!=end)func_double((begin+end)/2+1,end);
        for(int i=begin;i<=end;i++)ans[i]=ans[i]*2;
    }
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution1 {
public:
    TreeNode* buildTree(vector<int> inorder, vector<int> postorder) {
        if(inorder.empty())return nullptr;
        TreeNode* head = new TreeNode(postorder.back());

        auto i = find(inorder.begin(), inorder.end(), head->val);
        int index = i - inorder.begin();

        vector<int> right_inorder(inorder.begin() + index + 1, inorder.end());
        vector<int> right_postorder(postorder.begin() + index, postorder.end() - 1);
        head->right = buildTree(right_inorder, right_postorder);

        vector<int> left_inorder(inorder.begin(), inorder.begin() + index);
        vector<int> left_postorder(postorder.begin(), postorder.begin() + index);
        head->left = buildTree(left_inorder, left_postorder);
        return head;
    }
};

class Solution {
public:
    int countRangeSum(vector<int> nums, int lower, int upper) {
            long s = 0;
            vector<long> sum{0};
            for(auto& v: nums) {
                s += v;
                sum.push_back(s);
            }
            return func(sum,lower,upper,0,sum.size()-1);
        }
private:
    int func(vector<long>& sum, int lower, int upper, int left, int right)
    {
        if(left==right)return 0;
        int mid=(left+right)/2;
        int ans=func(sum,lower,upper,left,mid)+func(sum,lower,upper,mid+1,right);
        
        int i=left,ptrl=mid+1,ptrr=mid+1;
        while(i<=mid)
        {
            while(ptrl<=right&&sum[ptrl]-sum[i]<lower)ptrl++;
            while(ptrr<=right&&sum[ptrr]-sum[i]<=upper)ptrr++;
            ans+=(ptrr-ptrl);
            i++;
        }

        int x1=left,x2=mid+1;
        vector<int> temp;
        while(x1<=mid||x2<=right)
        {
            if(x1>mid)temp.push_back(sum[x2++]);
            else if(x2>right)temp.push_back(sum[x1++]);
            else
            {
                if(sum[x1]>sum[x2])temp.push_back(sum[x2++]);
                else temp.push_back(sum[x1++]);
            }
        }
        for(int i=left;i<=right;i++)sum[i]=temp[i-left];
        return ans;
    }
};

int main()
{
    // Solution s;
    // // s.beautifulArray(1);
    // s.buildTree({9,3,15,20,7},{9,15,7,20,3});
    Solution s;
    s.countRangeSum({-2,5,-1},-2,2);
    return 0;
}
