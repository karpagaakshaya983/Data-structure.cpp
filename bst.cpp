#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node* insert(Node* root, int x)
{
    if (root == NULL)
    {
        Node* temp = new Node;
        temp->data = x;
        temp->left = temp->right = NULL;
        return temp;
    }

    if (x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);

    return root;
}

void inorder(Node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main()
{
    Node* root = NULL;
    int a[] = {50, 30, 70, 20, 40, 60, 80};

    for (int i = 0; i < 7; i++)
        root = insert(root, a[i]);

    cout << "Employee IDs in ascending order: ";
    inorder(root);

    return 0;
}
