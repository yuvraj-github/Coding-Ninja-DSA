void printLevelWise(BinaryTreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
    {
        return;
    }
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *currentNode = pendingNodes.front();
        pendingNodes.pop();
        cout << currentNode->data << ":";
        if (currentNode->left != NULL)
        {
            pendingNodes.push(currentNode->left);
            cout << "L:" << currentNode->left->data;
        } else {
            cout << "L:-1";
        }
        if (currentNode->right != NULL)
        {
            pendingNodes.push(currentNode->right);
            cout << ",R:" << currentNode->right->data;
        } else {
            cout << ",R:-1";
        }
        cout << endl;
    }
}