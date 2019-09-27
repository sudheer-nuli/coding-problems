#include<bits/stdc++.h>
using namespace std;
#define ALPHABET_SIZE (26)
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    bool isWordEnd;
};
struct TrieNode *getNode(void)
{
    struct TrieNode *newnode = new TrieNode;
    newnode->isWordEnd = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        newnode->children[i] = NULL;

    return newnode;
}
void insert(struct TrieNode *root,  const string key)
{
    struct TrieNode *ptr = root;

    for (int level = 0; level < key.length(); level++)
    {
        int index = CHAR_TO_INDEX(key[level]);
        if (!ptr->children[index])
            ptr->children[index] = getNode();

        ptr = ptr->children[index];
    }
    ptr->isWordEnd = true;
}
bool search(struct TrieNode *root, const string key)
{
    int length = key.length();
    struct TrieNode *ptr = root;
    for (int level = 0; level < length; level++)
    {
        int index = CHAR_TO_INDEX(key[level]);

        if (!ptr->children[index])
            return false;

        ptr = ptr->children[index];
    }

    return (ptr != NULL && ptr->isWordEnd);
}
bool isLastNode(struct TrieNode* root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return 0;
    return 1;
}
void suggestionsRec(struct TrieNode* root, string current)
{
    if (root->isWordEnd)
    {
        cout << current;
        cout << endl;
    }
    if (isLastNode(root))
        return;

    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (root->children[i])
        {
            current.push_back(97 + i);
            suggestionsRec(root->children[i], current);
        }
    }
}
int printAutoSuggestions(TrieNode* root, const string findwords)
{
    struct TrieNode* ptr = root;
    int level;
    int n = findwords.length();
    for (level = 0; level < n; level++)
    {
        int index = CHAR_TO_INDEX(findwords[level]);
        if (!ptr->children[index])
            return 0;

        ptr = ptr->children[index];
    }
    bool isWord = (ptr->isWordEnd == true);
    bool isLast = isLastNode(ptr);
    if (isWord && isLast)
    {
        cout << findwords << endl;
        return -1;
    }
    if (!isLast)
    {
        string prefix = findwords;
        suggestionsRec(ptr, prefix);
        return 1;
    }
}
int main()
{
    struct TrieNode* root = getNode();
    insert(root, "ant");
    insert(root, "anthropology");
    insert(root, "anti");
    insert(root, "anticipatory");
    insert(root, "anvil");
    int check = printAutoSuggestions(root, "anth");
    if (check == -1)
        cout << "No other strings found with this prefix\n";
    else if (check == 0)
        cout << "No string found with this prefix\n";
    return 0;
}
