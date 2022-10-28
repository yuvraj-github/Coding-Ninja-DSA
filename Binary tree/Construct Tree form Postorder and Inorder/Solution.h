BinaryTreeNode<int> *buildTreeHelper(int *postorder, int *inorder, int ps, int pe, int is, int ie)
{
    if (ps > pe)
        return NULL;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(postorder[pe]);
    int k = 0;
    for (int i = is; i <= ie; i++)
    {
        if (postorder[pe] == inorder[i])
        {
            k = i;
            break;
        }
    }
    int lps = ps;              // left prestart
    int lis = is;              // left instart
    int lie = k - 1;           // left inend
    int lpe = lie - lis + lps; // left  pre end
    int rps = lpe + 1;         // right prestart
    int rpe = pe - 1;          //  right preend
    int ris = k + 1;           // right instart
    int rie = ie;              // right inend
    root->left = buildTreeHelper(postorder, inorder, lps, lpe, lis, lie);
    root->right = buildTreeHelper(postorder, inorder, rps, rpe, ris, rie);
    return root;
}


BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    // Write your code here
    return buildTreeHelper(postorder, inorder, 0, postLength - 1, 0, inLength - 1);
}