int getLeafNodeCount(TreeNode<int>* root) {
    // Write your code here
    if(root == NULL) {
        return 0;
    }
    int childCount = root->children.size();
    if(childCount==0) return 1; 
    int count = 0;
    for(int i=0; i<childCount; i++) {
        count += getLeafNodeCount(root->children[i]);
    }
    return count;
}