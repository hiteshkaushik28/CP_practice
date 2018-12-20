/* Contruct Binary tree using its Inorder and Preorder traversal
 * Question Link:://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal
 * The first element in preorder traversal gives us the root of the tree, this root divides the inorder traversal in two parts
 * , one is the subtree of root and other is the right subtree. We use this idea recursively using DFS to construct the tree.
*/

Class Solution{
public:
    
    TreeNode* build_using_DFS(int l_pre, int r_pre, int l_in, int r_in, vector<int>& preorder, vector<int>& iborder)
    {
        if(l_pre > r_pre)
            return nullptr;

        for(int i = l_in; i < r_in && preorder[l_pre] != inorder[i]; ++i) // find the root's position in inorder list
        {}

        int left_size = i - l_in; // size of the left subtree 

        TreeNode* root = new TreeNode(preorder[l_pre]); // construct the root
        root->left = build_using_DFS(l_pre + 1, l_pre + left_size, l_in, i - 1, preorder, inorder); // recursively construct
                                                                                                    // root's left tree
        root->right = build_using_DFS(l_pre + left_size + 1, r_pre, i + 1, r_in, preorder, inorder);//recursively construct 
                                                                                                    // root's right tree

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        return build_using_DFS(int 0, int preorder.size() - 1, 0, inorder.size() - 1, preorder, inorder);
    }
};
