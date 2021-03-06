#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode *successor(TreeNode *root) {
        TreeNode *current = root;
        while (current->left != NULL) {
            current = current->left;
        }
        return current;
    }

    TreeNode *deleteNode(TreeNode *root, int key) {
        if (root == NULL)
            return root;

        if (key < root->val)
            root->left = deleteNode(root->left, key);
        else if (key > root->val)
            root->right = deleteNode(root->right, key);
        else {
            if (root->left == NULL) {
                return root->right;
            } else if (root->right == NULL) {
                return root->left;
            }
            // node with two chile
            TreeNode *temp = successor(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
        return root;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    /**
     * findSuccesor - Helper function for finding successor
     * In BST, succesor of root is the leftmost child in root's right subtree
     */
    TreeNode *findSuccessor(TreeNode *root) {
        TreeNode *cur = root->right;
        while (cur && cur->left) {
            cur = cur->left;
        }
        return cur;
    }

public:
    TreeNode *deleteNode(TreeNode *root, int key) {
        // return null if root is null
        if (!root) {
            return root;
        }

        // delete current node if root is the target node
        if (root->val == key) {
            // replace root with root->right if root->left is null
            if (!root->left) {
                return root->right;
            }

            // replace root with root->left if root->right is null
            if (!root->right) {
                return root->left;
            }

            // replace root with its successor if root has two children
            TreeNode *p = findSuccessor(root);
            root->val = p->val;
            root->right = deleteNode(root->right, p->val);
            return root;
        }

        if (root->val < key) {
            // find target in right subtree if root->val < key
            root->right = deleteNode(root->right, key);
        } else {
            // find target in left subtree if root->val > key
            root->left = deleteNode(root->left, key);
        }
        return root;
    }
};