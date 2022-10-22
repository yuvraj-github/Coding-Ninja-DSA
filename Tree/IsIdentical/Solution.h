bool areIdentical(TreeNode<int> *root1, TreeNode<int> *root2)
{
    // Write your code here
    if (root1 == NULL)
    {
        if (root2 == NULL)
            return true;
        else
            return false;
    }
    /* Both root1 and root2 are non null */
    if (root1->data != root2->data)
        return false;
    int childCount1 = root1->children.size();
    int childCount2 = root2->children.size();
    if (childCount1 != childCount2)
        return false;
    for (int i = 0; i < childCount1; i++)
        if (!areIdentical(root1->children[i], root2->children[i]))
            return false;
    return true;
}