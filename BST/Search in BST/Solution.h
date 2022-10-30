
bool searchInBST(BinaryTreeNode<int> *root , int k) {
	// Write your code here
    if(root == NULL) {
        return 0;
    }
    if(root->data == k) {
        return 1;
    } else if(root->data>k) {
        return searchInBST(root->left, k);
    } else {
        return searchInBST(root->right, k);
    }
    return 0;
}