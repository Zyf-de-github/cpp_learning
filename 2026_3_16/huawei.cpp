// #include <bits/stdc++.h>
// using namespace  std;
//
// typedef struct treenode
// {
//     int val;
//     treenode *left, *right;
//     treenode(int val=0,treenode* left=nullptr,treenode* right=nullptr):val(val),left(left),right(right){};
// }treenode;
//
// treenode* buildtree(treenode* node,int& times)
// {
//     if (node!=nullptr&&node->val==-1)return nullptr;
//     if (times-->0)
//     {
//         int val,left,right;
//         cin>>val>>left>>right;
//         treenode* tree_left=new treenode(left);
//         treenode* tree_right=new treenode(right);
//         if (node==nullptr)
//         {
//             treenode* root=new treenode(val,tree_left,tree_right);
//             node=root;
//         }
//         else
//         {
//             node->left=tree_left;
//             node->right=tree_right;
//         }
//     }
//     if (node->left)buildtree(node->left,times);
//     if (node->right)buildtree(node->right,times);
//     return node;
// }
// int finding(int ans_temp,treenode* root,int flag,int K)
// {
//     if (root==nullptr||root->val==-1)return ans_temp-1;
//     int a=ans_temp,b=ans_temp,c=ans_temp,d=ans_temp;
//     if (flag!=-1&&root->val-root->left->val>=K)a=finding(ans_temp+1,root->left,-1,K);
//     if (flag!=1&&root->val-root->left->val<=-K)b=finding(ans_temp+1,root->left,1,K);
//     if (flag!=-1&&root->val-root->right->val>=K)c=finding(ans_temp+1,root->right,-1,K);
//     if (flag!=1&&root->val-root->right->val<=-K)d=finding(ans_temp+1,root->right,1,K);
//     return max(max(a,b),max(c,d));
// }
// int main()
// {
//     int N,K;
//     cin>>N>>K;
//     treenode* root=nullptr;
//     root=buildtree(root,N);
//     int ans=finding(1,root,0,K);
//     cout<<ans<<endl;
//     return 0;
// }
//

#include <bits/stdc++.h>
using namespace  std;
int main()
{
    return 0;
}