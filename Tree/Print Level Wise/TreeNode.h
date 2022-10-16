void printLevelWise(TreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
    {
        return;
    }
    queue<TreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode<int> *curr = q.front();
        q.pop();
        cout << curr->data << ':';
        int childCount = curr->children.size();
        if (childCount)
        {
            cout << curr->children[0]->data;
            q.push(curr->children[0]);
        }
        for (int i = 1; i < childCount; i++)
        {
            cout << ',' << curr->children[i]->data;
            q.push(curr->children[i]);
        }
        cout << endl;
    }
}