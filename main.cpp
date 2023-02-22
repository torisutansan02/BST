#include "node.hpp"

using namespace std;

int main() 
{
    BST B, *root = nullptr;

    cout << "Input values for the BST algorithm" << endl;

    int value;
    string answer;
    cin >> value;

    root = B.Insert(root, value);

    cout << "Would you like to continue inputting values?" << endl;
    while (cin >> answer)
    {
        if (answer == "yes")
        {
            cout << "Enter a number" << endl;
            cin >> value;
            B.Insert(root, value);
            cout << "Would you like to continue inputting values?" << endl;
        }
        else { break; }
    }

    B.InOrder(root);

    cout << "Input a number from the list" << endl;
    cin >> value;

    B.Search(root, value);

    cout << "Would you like to keep searching?" << endl;
    while (cin >> answer)
    {
        if (answer == "yes")
        {
            cout << "Enter a number" << endl;
            cin >> value;
            B.Search(root, value);
            cout << "Would you like to keep searching?" << endl;
        }
        else { break; }
    }

    cout << "Input a number from the list" << endl;
    cin >> value;

    B.Delete(root, value);

    cout << "Would you like to keep deleting?" << endl;
    while (cin >> answer)
    {
        if (answer == "yes")
        {
            cout << "Enter a number" << endl;
            cin >> value;
            B.Delete(root, value);
            cout << "Would you like to keep deleting??" << endl;
        }
        else { break; }
    }

    B.InOrder(root);

    return 0;
}