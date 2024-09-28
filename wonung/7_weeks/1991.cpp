#include <iostream>
#include <set>
using namespace std;

struct node
{
    node *left;
    node *right;
    char c;
};

node *createNode(char key)
{
    node *n = new node;
    n->c = key;
    n->left = NULL;
    n->right = NULL;
    return n;
}

node *nFind(node *n, char key)
{
    if (n == NULL)
        return NULL;
    if (n->c != key)
    {
        node *left = nFind(n->left, key);
        if (left == NULL)
            return nFind(n->right, key);
        return left;
    }
    else
        return n;
}
void preorder(node *n)
{
    if (n == NULL)
        return;
    cout << n->c;
    preorder(n->left);
    preorder(n->right);
}
void inorder(node *n)
{
    if (n == NULL)
        return;
    inorder(n->left);
    cout << n->c;
    inorder(n->right);
}
void postorder(node *n)
{
    if (n == NULL)
        return;
    postorder(n->left);
    postorder(n->right);
    cout << n->c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    char a, b, c;

    cin >> n;
    node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        node *n;
        cin >> a >> b >> c;
        if (root == NULL)
        {
            root = createNode(a);
            n = root;
        }
        else
        {
            n = nFind(root, a);
        }
        if (b != '.')
        {
            node *lnode = createNode(b);
            n->left = lnode;
        }

        if (c != '.')
        {
            node *rnode = createNode(c);
            n->right = rnode;
        }
    }
    preorder(root);
    cout << '\n';
    inorder(root);
    cout << '\n';
    postorder(root);
}