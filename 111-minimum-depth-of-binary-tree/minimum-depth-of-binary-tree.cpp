#include <queue>
using namespace std;
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;  // If the tree is empty, return depth 0

        queue<pair<TreeNode*, int>> q;  // Queue to store nodes along with their depth
        q.push({root, 1});  // Start with the root node at depth 1
        
        while (!q.empty()) {
            auto [node, depth] = q.front();  // Get the front node and its depth
            q.pop();
            
            // If this is a leaf node, return its depth
            if (!node->left && !node->right) {
                return depth;
            }
            
            // If there is a left child, add it to the queue with depth + 1
            if (node->left) {
                q.push({node->left, depth + 1});
            }
            
            // If there is a right child, add it to the queue with depth + 1
            if (node->right) {
                q.push({node->right, depth + 1});
            }
        }
        
        return 0;  // This line will never be reached if the tree is valid
    }
};