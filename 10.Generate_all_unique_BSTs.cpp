/* GENERATE ALL UNIQUE BST FOR A GIVEN VALUE OF N
 * Question Link:://leetcode.com/problems/unique-binary-search-trees-ii/
 * Let T(n) denote the number of BST with n nodes, then T(n) = summation (i=1 to n){T(i-1)*T(n - i)}
 * Means "i - 1" nodes go to left subtree, ith node is root, i+1 to n nodes go to right subtree.
 * This has exponential time complexity. There is DP approach also. Given solution is without DP.
*/

Class Solution{
public:
    vector<TreeNode* >generateTrees(int n)
    {
        if(n < 1)
            return ({nullptr});
        return generate(1, n); // root node's initial start value and end value
    }

    vector<TreeNode* >generate(int start, int end)
    {
        vector<TreeNode* >list;
        if(start > end)
            return({nullptr});
        for(int i = start; i <= end; ++i)
        {
            vector<TreeNode* >left = generate(start, i - 1);
            vector<TreeNode* >right = generate(i + 1, end);

            int l = left.size();
            int r = right.size();
            for(int j = 0; j < l; ++j)
            {
                for(int k = 0; k < r; ++k)
                {
                    TreeNode* node = new TreeNode(i);
                    node->left = left[j];
                    node->right = right[k];
                    list.push_back(node);
                }
            }
        }

        return list;
    }
};
