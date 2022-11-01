BinaryTreeNode<int>* binaryTree(int *input, int s, int e) {
    if(s>e) {
        return NULL;
    }
    int mid = (s+e)/2;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int> (input[mid]);
    root->left = binaryTree(input, s, mid-1);
    root->right = binaryTree(input, mid+1, e);
    return root;
}
BinaryTreeNode<int>* constructTree(int *input, int n) {
	// Write your code here
    return binaryTree(input,0,n-1);
}