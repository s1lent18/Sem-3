#include "AVL-Insertion.cpp"

// Finding the smallest value in the BST
Node * minValue(Node * n)
{
    Node * curr = n;

    while(curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}

// Function to delete the node with the given data
Node * deletenode(Node * root, int data)
{
    if(root == NULL)
    {
        return root;
    }

    if(data < root->data)
    {
        root->left = deletenode(root->left, data);
    }

    else if(data > root->data)
    {
        root->right = deletenode(root->right, data);
    }

    else if(data == root->data)
    {
        // Node with 0 or 1 child
        if(root->left == NULL || root->right == NULL)
        {
            Node * temp = root->left ? root->left : root->right;

            // Case for 0 child:
            if(temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            // Case for only 1 Child:
            else
            {
                *root = *temp;
                free(temp);
            }
        }
        // Node with 2 Children
        else
        {
            // getting the smallest value in the right subtree
            Node * temp = minValue(root->right);

            root->data = temp->data;

            root->right = deletenode(root->right, temp->data);
        }
    }

    // If the tree has only 1 Node
    if(root == NULL)
    {
        return root;
    }

    // Updating the height of the current node
    root->height = max(getheight(root->left), getheight(root->right)) + 1;

    // Checking if the tree has became unbalanced or not
    int balance = getbalancingfactor(root);

    // Case-1 -> Left-Left Case
    if(balance > 1 && data < root->left->data)
    {
        return rotateright(root);
    }

    // Case-2 -> Right-Right Case:
    if(balance > -1 && data > root->right->data)
    {
        return rotateleft(root);
    }

    // Case-3 -> Left-Right Case:
    if(balance > 1 && data > root->left->data)
    {
        root->left = rotateleft(root->left);
        return rotateright(root);
    }

    // Case-4 -> Right-Left Case:
    if(balance < -1 && data < root->right->data)
    {
        root->right = rotateright(root->right);
        return rotateleft(root);
    }

    return root;
}