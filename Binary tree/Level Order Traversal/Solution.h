void printLevelWise(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;

    queue<BinaryTreeNode<int> *> q;

    q.push(root);

    while (q.empty() == false)
    {
        int nodeCount = q.size();

        while (nodeCount > 0)
        {
            BinaryTreeNode<int> *node = q.front();
            cout << node->data << " ";
            q.pop();
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
            nodeCount--;
        }
        cout << endl;
    }
}