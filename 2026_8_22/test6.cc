#include "bits/stdc++.h"
using namespace std;

class node
{
public:
    int n;
    node* ptr;
    node(int n=0,node* ptr=nullptr)
    {
        this->n=n;
        this->ptr=ptr;
    }
};

int main() {
    int n,x;
    cin>>n>>x;
    vector<int>v(n,0);
    node* root=new node();
    node* root_temp=root;
    for(int i=0;i<n;i++)cin>>v[i];
    for(auto it:v)
    {
        node* temp=new node(it);
        root_temp->ptr=temp;
        root_temp=temp;
    }
    root_temp=root;
    while(root_temp&&root_temp->ptr)
    {
        if(root_temp->ptr->n==x)root_temp->ptr=root_temp->ptr->ptr;
        root_temp=root_temp->ptr;
    }
    root=root->ptr;
    while(root)
    {
        cout<<root->n<<' ';
        root=root->ptr;
    }
    return 0;
}
