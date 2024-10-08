#include <iostream>
#include <algorithm>
#include <utility> // For std::pair

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    // Constructor
    TreeNode(int x) : val(x), left(NULL), right(NULL) {} // Use NULL instead of nullptr
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return checkBalanceAndHeight(root).first; // Check if the tree is balanced
    }

private:
    // Helper function that returns a pair: (isBalanced, height)
    std::pair<bool, int> checkBalanceAndHeight(TreeNode* node) {
        if (!node) {
            return std::make_pair(true, 0); // A null node is balanced and has height 0
        }

        std::pair<bool, int> left = checkBalanceAndHeight(node->left);   // Check left subtree
        std::pair<bool, int> right = checkBalanceAndHeight(node->right); // Check right subtree

        // Check if current node is balanced
        bool balanced = left.first && right.first && std::abs(left.second - right.second) <= 1;
        // Calculate height of current node
        int height = std::max(left.second, right.second) + 1;

        return std::make_pair(balanced, height); // Return the balance status and height
    }
};

// Example usage
int main() {
    // Create a sample balanced binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution solution;
    bool result = solution.isBalanced(root);
    
    std::cout << "The binary tree is " << (result ? "balanced" : "not balanced") << std::endl;

    // Clean up the allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
