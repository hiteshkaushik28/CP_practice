/* Delete node in a BSt
 * Question Link: https://leetcode.com/problems/delete-node-in-a-bst/
 * The node to be deleted is replaced by its inorder successor.
 * Two Cases arise:
  i) The target node has both left and right subtrees.
  ii) The target node doesnt have a right subtree.
*/

Class Solution{
public:
    TreeNode* deleteNode(TreeNode* root, int key)
    {
        if(!root) return root;

        TreeNode* target = root, *parent = nullptr;

        while(target && target->val != key)
        {
            parent = target;
            if(target->val > key) target = target->left; // use BST property to locate the target node 
            else target = target->right;
        }

        if(!target) return root; // if target node is not present

        if(!target->right)  // target's right subtree is not present
        {
            if(!parent) return target->left; // if it is the root node itself
            if(target == parent->left) parent->left = target->left;
            else parent->right = target->left;
            return root;
        }

        TreeNode* prev = target, *p = target->right;  // target node's right subtree exists
        while(p->left) // find the smallest node in the right subtree
        {
            prev = p;
            p = p->left;
        }
        
        target->val = p->val;
        if(p == prev->right) prev->right = p->right;
        else prev->left = p->right;
        return root;
    }
};
