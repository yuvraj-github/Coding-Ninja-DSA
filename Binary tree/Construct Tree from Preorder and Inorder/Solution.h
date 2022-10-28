BinaryTreeNode<int> *buildTree(int *preorder, int preLength, int *inorder, int inLength)
{
    // Write your code here
    if (preLength != inLength || preorder == nullptr || inorder == nullptr || preLength == 0)
        return NULL;
    int rootVal = preorder[0], leftCount, rightCount;   
    for (leftCount = 0; leftCount < inLength && inorder[leftCount] != rootVal; leftCount++);
    rightCount = preLength - leftCount - 1;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootVal);
    root->left = buildTree(preorder + 1, leftCount, inorder, leftCount);
    root->right = buildTree(preorder + leftCount + 1, rightCount,inorder + leftCount + 1, rightCount);
    return root;
}