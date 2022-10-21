#include <math.h>
int getHeight(TreeNode<int>* root) {
    // Write your code here
    if(root == NULL) {
        return 0;
    }
    int ans=0;
    for (int i = 0; i < root->children.size(); i++) {
      int ch = getHeight(root->children[i]);
      ans = max(ans, ch);
    }     
    return ans+1;
}