bool isSibling(BinaryTreeNode<int> *root, int data_one,
               int data_two)
{
    if (!root)
        return false;
    if (root->left && root->right)
    {
        int left = root->left->data;
        int right = root->right->data;

        if (left == data_one && right == data_two)
            return true;
        else if (left == data_two && right == data_one)
            return true;
    }

    if (root->left)
        isSibling(root->left, data_one,
                  data_two);

    if (root->right)
        isSibling(root->right, data_one,
                  data_two);
}

int level(BinaryTreeNode<int> *root, int ptr, int lev)
{
    if (root == NULL)
        return 0;
    if (root->data == ptr)
        return lev;

    int l = level(root->left, ptr, lev + 1);
    if (l != 0)
        return l;

    return level(root->right, ptr, lev + 1);
}

bool isCousin(BinaryTreeNode<int> *root, int p, int q)
{
    // Write your code here
    if ((level(root, p, 1) == level(root, q, 1)) && !(isSibling(root, p, q)))
        return true;
    else
        return false;
}
