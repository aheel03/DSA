#include<bits/stdc++.h>
using namespace std;

struct BinaryTree{
    struct node{
        int val;
        node* left;
        node* right;
    };
    node* root=NULL;

    void rootdeclare(int x) {
        root=CreateNode(x);
    }

    node* CreateNode(int x){
        node* newnode=(node*)malloc(sizeof(node));
        newnode->val=x;
        newnode->left=NULL;
        newnode->right=NULL;
        return newnode;
    }

    node* FindNode(node* parent, int x) {
        if (parent==NULL) return NULL; 
        if (parent->val==x) return parent;
        node* f=FindNode(parent->left,x);
        if (f!=NULL) return f;
        return FindNode(parent->right,x);
    }

    void InsertValue(int type, int par, int x){
        node* rt=FindNode(root,par);
        if(type==0){
            if(rt->left==NULL){
                rt->left=CreateNode(x);
                return;
            }
        }else{
            if(rt->right==NULL){
                rt->right=CreateNode(x);
                return;
            }
        }
    }

    void BFS() {
        if (root==NULL) return;
        queue<node*> q;
        q.push(root);
        while (!q.empty()) {
            node* node=q.front();
            q.pop(); 
            cout <<node->val<< " ";
            if(node->left!=NULL) q.push(node->left);
            if(node->right!=NULL) q.push(node->right);
        }
        cout<<endl;
    }

    void inOrderDFS(node* node) {
        if(node==NULL) return;
        inOrderDFS(node->left);
        cout<<node->val<<" ";
        inOrderDFS(node->right);
    }

    void preOrderDFS(node* node) {
        if(node==NULL) return;
        cout<<node->val<<" ";
        preOrderDFS(node->left);
        preOrderDFS(node->right);
    }

    void postOrderDFS(node* node) {
        if(node==NULL) return;
        postOrderDFS(node->left);
        postOrderDFS(node->right);
        cout<<node->val<<" ";
    }

    void post_order_traversal(){
        postOrderDFS(root);
        cout<<endl;
    }
    void in_order_traversal(){
        inOrderDFS(root);
        cout<<endl;
    }
    void pre_order_traversal(){
        preOrderDFS(root);
        cout<<endl;
    }
};

bool AreTreesEqual(BinaryTree::node* root1, BinaryTree::node* root2) {
    if (root1 == NULL && root2 == NULL) return true;
    if (root1 == NULL || root2 == NULL) return false;
    return (root1->val == root2->val) &&
           AreTreesEqual(root1->left, root2->left) &&
           AreTreesEqual(root1->right, root2->right);
}



int main(){
    int rr;
    cin>>rr;
    BinaryTree bt;
    bt.rootdeclare(rr);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int type,par,x;
        cin>>type>>par>>x;
        bt.InsertValue(type,par,x);
    }
    cin>>rr;
    BinaryTree bt2;
    bt2.rootdeclare(rr);
    cin>>n;
    for(int i=0;i<n;i++){
        int type,par,x;
        cin>>type>>par>>x;
        bt2.InsertValue(type,par,x);
    }
    cout<<AreTreesEqual(bt.root,bt2.root);
}
