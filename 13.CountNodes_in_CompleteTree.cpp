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

 // ANOTHER GOOD SOLUTION , TIME COMPLEXITY = O(log(n)^2)

/* Explanation
 * The height of a tree can be found by just going left. Let a single node tree have height 0. Find the height h of the whole 
 * tree. If the whole tree is empty, i.e., has height -1, there are 0 nodes.

 * Otherwise check whether the height of the right subtree is just one less than that of the whole tree, meaning left and 
 * right subtree have the same height.
 * If yes, then the last node on the last tree row is in the right subtree and the left subtree is a full tree of height h-1. 
 * So we take the 2^h-1 nodes of the left subtree plus  1 root node plus recursively the number of nodes in the right subtree.i
 * If no, then the last node on the last tree row is in the left subtree and the right subtree is a full tree of height h-2. 
 * So we take the 2^(h-1)-1 nodes of the right subtree plus the 1 root node plus recursively the number of nodes in the left 
 * subtree.
 * Since I halve the tree in every recursive step, I have O(log(n)) steps. Finding a height costs O(log(n)). 
 * So overall O(log(n)^2).
*/

 Class Solution{
 public:
    int height(TreeNode* root)
    {
        return (root == null ? -1 : 1 + height(root->left));
    }

    int countNodes(TreeNode* root)
    {
       int h = height(root);      

       return h < 0 ? 0 
                    : (height(root->right) == h - 1 
                    ? (1 << h) + countNodes(root->right) 
                    : (1 << h - 1) + countNodes(root->left));
    }
 };
