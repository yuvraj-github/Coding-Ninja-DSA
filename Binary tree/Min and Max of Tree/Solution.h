#include <limits.h>
pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
	// Write your code here
    pair<int, int> answer;
    answer.first = INT_MAX;
    answer.second = INT_MIN;
    if(root==nullptr) return answer;
    pair<int, int> left = getMinAndMax(root->left);
    pair<int, int> right = getMinAndMax(root->right);
    answer.first = min(root->data, min(left.first, right.first));
    answer.second = max(root->data, max(left.second, right.second));
    return answer;
}