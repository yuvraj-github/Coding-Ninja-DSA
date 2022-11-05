#include <cmath>
int height(BinaryTreeNode<int>* root)
{
    if(root==NULL)
        return 0;
    
    return 1+ max(height(root->left),height(root->right));
}
vector<int> *longestPath(BinaryTreeNode<int> *root)
{
    // Write your code here
    if (root->left == NULL && root->right == NULL)
    {
        vector<int> *ans = new vector<int>();
        ans->push_back(root->data);
        return ans;
    }
    int left = 0;
    int right = 0;
    if (root->left)
        left = height(root->left);
    if (root->right)
        right = height(root->right);

    if (left > right)
    {
        vector<int> *l = longestPath(root->left);
        l->push_back(root->data);
        return l;
    }
    else
    {
        vector<int> *r = longestPath(root->right);
        r->push_back(root->data);
        return r;
    }
}