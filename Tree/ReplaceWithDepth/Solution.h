void replaceWithDepthValueHelper(TreeNode<int> *root, int value)
{
    if (root == NULL)
        return;
    root->data = value; // root node
    int childCount = root->children.size();
    for (int i = 0; i < childCount; i++)
        replaceWithDepthValueHelper(root->children[i], value + 1);
}
void replaceWithDepthValue(TreeNode<int> *root)
{
    // Write your code here
    replaceWithDepthValueHelper(root, 0);
}