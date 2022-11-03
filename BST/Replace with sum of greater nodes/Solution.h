int replace(BinaryTreeNode<int> *root,int sum)
{
    if(root==NULL)
        return sum;
    
     sum=replace(root->right,sum);
      sum=sum +root->data;
      root->data=sum;
      sum =replace(root->left,sum);
    
   return  sum;
    
}
void replaceWithLargerNodesSum(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root==NULL)return; 
    int ans =replace(root,0);
    
    return ;
}