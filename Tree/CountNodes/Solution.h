int getLargeNodeCount(TreeNode<int> *root, int x)
{
    // Write your code here
    if (root == NULL)
        return 0;
    int result = 0;
    if (root->data > x)
        result++;
    int childCount = root->children.size();
    for (int i = 0; i < childCount; i++)
        result += getLargeNodeCount(root->children[i], x);
    return result;
}