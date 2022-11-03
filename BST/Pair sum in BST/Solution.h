#include <stack>
int countnodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;

    return 1 + countnodes(root->left) + countnodes(root->right);
}
void printNodesSumToS(BinaryTreeNode<int> *root, int s)
{
    // Write your code here
    int totalnodes = countnodes(root);
    int count = 0;

    stack<BinaryTreeNode<int> *> inorder;
    stack<BinaryTreeNode<int> *> revinorder;

    BinaryTreeNode<int> *temp = root;

    while (temp)
    {
        inorder.push(temp);

        temp = temp->left;
    }
    temp = root;
    while (temp)
    {
        revinorder.push(temp);

        temp = temp->right;
    }

    while (count < totalnodes - 1)
    {
        BinaryTreeNode<int> *top1 = inorder.top();
        BinaryTreeNode<int> *top2 = revinorder.top();
        if (top1->data + top2->data == s)
        {
            cout << top1->data << " " << top2->data << endl;

            BinaryTreeNode<int> *top = top1;
            inorder.pop();
            count++;
            if (top->right)
            {
                top = top->right;
                while (top)
                {
                    inorder.push(top);
                    top = top->left;
                }
            }
            top = top2;
            revinorder.pop();
            count++;
            if (top->left)
            {
                top = top->left;
                while (top)
                {
                    revinorder.push(top);
                    top = top->right;
                }
            }
        }
        else if (top1->data + top2->data > s)
        {
            BinaryTreeNode<int> *top = top2;
            revinorder.pop();
            count++;
            if (top->left)
            {
                top = top->left;
                while (top)
                {
                    revinorder.push(top);
                    top = top->right;
                }
            }
        }
        else
        {
            BinaryTreeNode<int> *top = top1;
            inorder.pop();
            count++;
            if (top->right)
            {
                top = top->right;
                while (top)
                {
                    inorder.push(top);
                    top = top->left;
                }
            }
        }
    }
}