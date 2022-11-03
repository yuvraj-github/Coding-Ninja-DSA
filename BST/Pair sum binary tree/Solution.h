#include <bits/stdc++.h>
#include <vector>
vector<int> v;
void inorder(BinaryTreeNode<int> *root) {
  if (root == NULL) {
    return;
  }
  v.push_back(root->data);
  inorder(root->left);
  inorder(root->right);
}
void pairSum(BinaryTreeNode<int> *root, int sum) {
  // Write your code here
  inorder(root);
  sort(v.begin(), v.end());
  int i = 0;
  int j = v.size() - 1;
  while (i < j) {
    if (v[i] + v[j] == sum) {
      cout << v[i] << " " << v[j] << endl;
      i++;
      j--;
    } else if (v[i] + v[j] < sum) {
      i++;

    } else {
      j--;
    }
  }
}