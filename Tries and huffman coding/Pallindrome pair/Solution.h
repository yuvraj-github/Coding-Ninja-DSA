class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie
{
    TrieNode *root;

public:
    int count;

    Trie()
    {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool add(TrieNode *root, string word)
    {
        // Base case
        if (word.size() == 0)
        {
            if (!root->isTerminal)
            {
                root->isTerminal = true;
                return true;
            }
            else
            {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childCount++;
        }

        // Recursive call
        return add(child, word.substr(1));
    }

    void add(string word)
    {
        if (add(root, word))
        {
            this->count++;
        }
    }
    bool search(TrieNode *root, string word)
    {
        if (word.size() == 0)
            return true;
        TrieNode *child;
        int index = word[0] - 'a';
        if (root->children[index] == NULL)
            return false;
        else
            child = root->children[index];

        return search(child, word.substr(1));
    }

    bool search(string word)
    {
        return search(root, word);
    }

    bool isPalindromePair(vector<string> words)
    {
        // Write your code here
        for (int i = 0; i < words.size(); i++)
        {
            string str = words[i];
            reverse(str.begin(), str.end());
            for (int j = 0; j < str.size(); j++)
            {
                add(str.substr(j));
            }
            if (search(words[i]))
                return true;
            if (search(words[i].substr(1)))
                return true;
        }
        return false;
    }
};