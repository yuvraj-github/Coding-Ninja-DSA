int getLCA(BinaryTreeNode<int> *root, int a, int b)
{
    // Write your code here
    if (root == NULL)
        return -1;
    if (root->data == a || root->data == b)
        return root->data;

    int left = getLCA(root->left, a, b);
    int right = getLCA(root->right, a, b);

    if (left == -1 && right == -1)
        return -1;
    else if (left != -1 && right == -1)
        return left;
    else if (left == -1 && right != -1)
        return right;
    else
        return root->data;
}