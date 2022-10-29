int height(BinaryTreeNode<int>* node)
{
    if (node == NULL)
        return 0;
  
    return 1 + max(height(node->left), height(node->right));
}
bool isBalanced(BinaryTreeNode<int> *root)
{
    // Write your code here
    int lh, rh;

    if (root == NULL)
        return 1;

    lh = height(root->left);
    rh = height(root->right);

    if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;

    return 0;
}