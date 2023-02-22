#include <iostream>
using namespace std;

class BST
{
    private:
        int data;
        BST* left;
        BST* right;
        BST* next;

    public:
        BST(); 
        BST(int);
        BST* Insert(BST*, int);
        void Search(BST*, int);
        void InOrder(BST*);
        BST* Delete(BST*, int);
};

BST::BST() : data(0), left(nullptr), right(nullptr) { }

BST::BST(int value)
{
    data = value;
    left = nullptr;
    right = nullptr;
}

BST* BST::Insert(BST* root, int value)
{
    if (root == nullptr)
    {
        return new BST(value);
    }
    if (value > root->data)
    {
        root->right = Insert(root->right, value);
    }
    else
    {
        root->left = Insert(root->left, value);
    }
    return root;
}

void BST::Search(BST* root, int value)
{
    if (root->data < value && root->right != nullptr)
    {
        return Search(root->right, value);
    }
    if (root->data > value && root->left != nullptr)
    {
        return Search(root->left, value);
    }
    if (root->data == value || root == nullptr)
    {
        cout << "It does have a value" << endl;
    }
    else
    {
        cout << "It does not have a value" << endl;
    }
}

void BST::InOrder(BST* root)
{
    if (root == nullptr)
    {
        return;
    }
    InOrder(root->left);
    cout << root->data << endl;
    InOrder(root->right);
}

BST* BST::Delete(BST* root, int value)
{
    if (root == nullptr) { return root; }

    if (value < root->data)
    {
        root->left = Delete(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = Delete(root->right, value);
    }
    else
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            return nullptr;
        }
        else if (root->left == nullptr)
        {
            BST* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == nullptr)
        {
            BST* temp = root->left;
            free(root);
            return temp;
        }

        BST* temp = root->right;

        while (temp && temp->left != nullptr)
        {
            temp = temp->left;
        }

        root->data = temp->data;
        root->right = Delete(root->right, temp->data);
    }
    return root;
}