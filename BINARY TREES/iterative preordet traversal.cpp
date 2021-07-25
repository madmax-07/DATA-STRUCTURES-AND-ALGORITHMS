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
vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> v;
    if (root == NULL)
        return v;
    stack<TreeNode *> s;
    s.push(root);
    while (!s.empty())
    {
        TreeNode *ptr = s.top();
        s.pop();
        v.push_back(ptr->val);
        if (ptr->right)
            s.push(ptr->right);
        if (ptr->left)
        {
            s.push(ptr->left);
        }
    }
    return v;
}
