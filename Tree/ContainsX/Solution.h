bool isPresent(TreeNode<int>* root, int x) {
    // Write your code here
    if(root==NULL) return false;
    if(root->data==x) return true;
    int childCount = root->children.size();
    for(int i=0; i<childCount; i++)
        if(isPresent(root->children[i], x)) return true;
    return false;
}