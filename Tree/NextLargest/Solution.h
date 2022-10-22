TreeNode<int> *getNextLargerElement(TreeNode<int> *root, int x)
{
    // Write your code here
    if (root == NULL)
        return NULL;
    int childCount = root->children.size();
    if (childCount == 0) // Base Case
    {
        if (root->data > x)
            return root; // Found node with value greater than n
        return NULL;
    }
    TreeNode<int> *result = NULL;
    if (root->data > x)
        result = root; // Found node with value greater than n
    for (int i = 0; i < childCount; i++)
    {
        TreeNode<int> *temp = getNextLargerElement(root->children[i], x);
        if (temp == NULL)
            continue;
        if (result == NULL || result->data > temp->data)
            result = temp;
    }
    return result;
}