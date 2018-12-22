/* 117. Populating Next Right Pointers in Each Node II
 *      struct TreeLinkNode 
 *      {
 *          TreeLinkNode *left;
 *          TreeLinkNode *right;
 *          TreeLinkNode *next;
 *      }

 * Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set 
 * to NULL.
 * Initially, all next pointers are set to NULL.
 * NOTE
 * You may only use constant extra space.
 * Recursive approach is fine, implicit stack space does not count as extra space for this problem.
 * The solution is very ELEGANT.
 * The Idea is to use the LinkedList we are creating by connecting next pointers for traversing the tree. 
*/

Class Solution{
public:
    void connect(TreeLinkNode* root)
    {
        if(!root) return;

        for(TreeLinkNode* head = root; head != nullptr; )
        {
            TreeLinkNode* nextHead = new TreeLinkNode(0); // Dummy Node with dummy value. This will maintain the next level 
                                                          // order node to be visited. Pretty important.
            TreeLinkNode* nextTail = nextHead;            // this pointer will connect the next pointers.

            for(TreeLinkNode* node = head; node != nullptr; )
            {
                if(node->left)
                {
                    nextTail->next = node->left; // link the dummy node to left child of root
                    nextTail = node->left;       // move forward the nextTail pointer in the linked list.
                }

                if(node->right)
                {
                    nextTail->next = node->right; // link the left child of root to its left child
                    nextTail = node->right;       // move forward the nextTail pointer in the linked list.
                }
            }

            head = nextHead->next;               // nextHead points to dummy node, its next is the left child of root, so we
                                                 // get the next level order node using nextHead->next
        }
    }
};
