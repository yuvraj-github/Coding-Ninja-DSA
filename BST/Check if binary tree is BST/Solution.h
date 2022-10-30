#include <climits>
bool isBSThelper(BinaryTreeNode<int> *root, int min, int max)
{
	if (root == NULL)
	{
		return true;
	}
	if (root->data < min || root->data > max)
	{
		return false;
	}
	bool isleftok = isBSThelper(root->left, min, root->data-1);
	bool isrightok = isBSThelper(root->right, root->data, max);
	return isleftok && isrightok;
}

bool isBST(BinaryTreeNode<int> *root)
{
	return isBSThelper(root, INT_MIN, INT_MAX);
}