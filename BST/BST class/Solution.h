class BST
{
    // Define the data members
    BinaryTreeNode<int>* root;
public:
    BST()
    {
        // Implement the Constructor
        root = NULL;
    }
    ~BST() {
		delete root;
	}
    /*----------------- Public Functions of BST -----------------*/
    private:
    void printTree(BinaryTreeNode<int>* root) {
        if(root == NULL) {
            return;
        }
        cout << root->data <<":";
        if(root->left != NULL) {
            cout << "L:" << root->left->data<<",";
        }
        if (root->right != NULL) {
			cout << "R:" << root->right->data;
		}
		cout << endl;
		printTree(root->left);
		printTree(root->right);
    }

    public:
    void remove(int data)
    {
        // Implement the remove() function
    }

    void print()
    {
        // Implement the print() function
        printTree(root);
    }

    void insert(int data)
    {
        // Implement the insert() function
    }

    bool search(int data)
    {
        // Implement the search() function
    }
};