/* Recover Binary Search Tree
 * Question Link://leetcode.com/problems/recover-binary-search-tree/submissions/ 
 * The question seems hard, but the idea is pretty straight. It just uses Inorder Traversal.
 * IDEA:
 * In the inorder sequence of a tree, say "a1a2a3a4a5", a2 will be to the right of a1 in tree representation also. So a2 cant be
 * smaller than a1. We can use this fact to modify the inorder traversal and just keep checking adjacent nodes for this
 * property. The question asks us not to modify the tree structure, so we will just swap the two swapped nodes values.
*/

Class Solution{
public:
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = new TreeNode(INT_MIN);

    void inorder(TreeNode* root)
    {
        if(!root)
            return;
        inorder(root->left); // normal left subtree traversal

        /* Here is the modification to inorder traversal */

        if(first == nullptr && prev->val >= root->val) // if the first node is not found, then simply assign it to prev.
            first = prev;
        if(first != nullptr && prev->val >= root->val) // if first has been found, then assign second = root.
            second = root;
        prev = root; // update prev as recursion will go to some other node and we need to maintain from where we came.
        
        inorder(root->right); // normal right subtree traversal
    }

    void recoverTree(TreeNode* root)
    {
        inorder(root);

        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
};
