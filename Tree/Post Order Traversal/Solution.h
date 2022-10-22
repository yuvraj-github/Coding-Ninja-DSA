void printPostOrder(TreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
        return;    
    int childCount = root->children.size();
    for (int i = 0; i < childCount; i++)
        printPostOrder(root->children[i]);
    cout << root->data << ' ';
}