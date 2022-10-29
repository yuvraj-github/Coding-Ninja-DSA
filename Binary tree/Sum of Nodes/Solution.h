int getSum(BinaryTreeNode<int>* root) {
    // Write your code here
    if(root == NULL) {
        return 0;
    }
    int leftSum = getSum(root->left);
    int rightSum = getSum(root->right);
    return root->data+leftSum+rightSum;
}