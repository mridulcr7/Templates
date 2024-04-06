#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
} *root = NULL;

void bfs(node *temp)
{
    queue<node *> a;
    if(temp!=NULL)
        a.push(temp);
    while(!a.empty())
    {
        node *curr = a.front();
        a.pop();
        cout << curr->data<<" ";
        if(curr->left!=NULL)
        {
            a.push(curr->left);
        }
        if(curr->right!=NULL)
        {
            a.push(curr->right);
        }
    }
}


void create_bt()
{
    int t;
    queue<node *> a;
   // cout << "Enter data\n";
    cin >> t;
    if (t == -1)
        return;
    node *temp = new node;
    temp->data = t;
    temp->left = NULL;
    temp->right = NULL;
    root = temp;
    a.push(root);
    while (!a.empty())
    {
        cin >> t;
        if (t != -1)
        {
            node *temp = new node;
            temp->data = t;
            temp->left = NULL;
            temp->right = NULL;
            a.front()->left = temp;
            a.push(temp);
        }
        cin >> t;
        if (t != -1)
        {
            node *temp = new node;
            temp->data = t;
            temp->left = NULL;
            temp->right = NULL;
            a.front()->right = temp;
            a.push(temp);
        }
        a.pop();
    }
}

int main()
{
    create_bt();
    bfs(root);
}