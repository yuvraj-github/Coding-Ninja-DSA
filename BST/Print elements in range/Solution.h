void elementsInRangeK1K2(BinaryTreeNode<int> *root, int k1, int k2)
{
    // Write your code here
    if (NULL == root)
        return;

    if (root->data >= k1 && root->data <= k2)
    {
        elementsInRangeK1K2(root->left, k1, k2);
        cout << root->data << " ";
        elementsInRangeK1K2(root->right, k1, k2);
    } else if (root->data < k1) {
        elementsInRangeK1K2(root->right, k1, k2);
    } else if(root->data > k2) {
        elementsInRangeK1K2(root->left, k1, k2); 
    }
}