#include <bits/stdc++.h>
using namespace std;
class tree
{
public:
    int data;
    tree *left;
    tree *right;
    tree(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
void print(tree *root)
{
    if (root == NULL)
        return;
    cout << root->data;
    print(root->left);
    print(root->right);
}
tree *build_tree()
{
    int d;
    cin >> d;
    if (d == -1)
        return NULL;
    tree *root = new tree(d);
    root->left = build_tree();
    root->right = build_tree();
    return root;
}
void preorder(tree *root)
{
    if (root == NULL)
        return;
    stack<tree *> s;
    s.push(root);
    while (!s.empty())
    {
        tree *ptr = s.top();
        cout << ptr->data << "->";

        s.pop();
        if (ptr->right)
        {
            s.push(ptr->right);
        }
        if (ptr->left)
        {
            s.push(ptr->left);
        }
    }
    cout << endl;
}
int height(tree *root)
{
    if (root == NULL)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh, rh) + 1;
}

int main()
{
    tree *root = NULL;
    root = build_tree();
    print(root);
    cout << "tree in preorder is";
    preorder(root); //this is iterative preorder traversal
    cout << "height of tree" << endl;
    cout << height(root) << endl;
    
}
