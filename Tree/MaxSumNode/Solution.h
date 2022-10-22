int sumNode(TreeNode<int> *root)
{
    /* Called by maxSumNode */
    if (root == NULL)
        return 0;
    int sum = root->data; // Calculate sumNode for root Node
    int childCount = root->children.size();
    for (int i = 0; i < childCount; i++)
        sum += root->children[i]->data;
    return sum;
}
TreeNode<int> *maxSumNode(TreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
        return NULL;
    TreeNode<int> *result = root; // root node
    int maxSum = sumNode(root);   // Calculate sumNode for root Node
    int childCount = root->children.size();
    for (int i = 0; i < childCount; i++)
    {
        TreeNode<int> *temp = maxSumNode(root->children[i]);
        int sum = sumNode(temp);
        if (sum > maxSum)
        {
            maxSum = sum;
            result = temp;
        }
    }
    return result;
}