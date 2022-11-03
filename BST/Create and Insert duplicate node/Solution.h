void insertDuplicateNode(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root==NULL)
        return;
    
    BinaryTreeNode<int> *duplicate = new BinaryTreeNode<int> (root->data);
    duplicate->left=root->left;
    root->left=duplicate;
    
    insertDuplicateNode(duplicate->left);
    insertDuplicateNode(root->right);
}