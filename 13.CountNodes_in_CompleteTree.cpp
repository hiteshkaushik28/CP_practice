/* Count number of nodes in a complete binary tree
 * In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are
 * as far left as possible. It can have between 1 and 2^h nodes inclusive at the last level h.

 * Question Link: https://leetcode.com/problems/count-complete-tree-nodes/
 * We can simply count the nodes using DFS traversal, however it may give TLE because of the runtime of DFS. Also since we are
 * given a Complete Tree, we can use the property of CT to reduce our computations.

 * The Idea is to find the point till where both left and right subtrees exist. Till this point we do not require any DFS calls.*/

 Class Solution{
 public:
    int countNodes(TreeNode* root)
    {
        if(!root)
            return 0;

        int height = 0;

        TreeNode* left = root->left;
        TreeNode* right = root->right;

        while(left && right) // find the height till where tree is completely filled
        {
            ++height;
            left = left->left;
            right = right->right;
        }

        if(!left && !right) return (1 << (height + 1)) - 1; // if the tree is completely filled till last level, then simply 
                                                            // return the answer using formula
        else return 1 + countNodes(root->left) + countNodes(root->right); // if not, then normally count thereafter
    }
 };
