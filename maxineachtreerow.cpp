/*

Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).

Input: root = [1,3,2,5,3,null,9]
Output: [1,3,9]
Example 2:

Input: root = [1,2,3]
Output: [1,3]
 

Constraints:

The number of nodes in the tree will be in the range [0, 104].
-231 <= Node.val <= 231 - 1

*/

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {

         //this will be the final result that we will be returning, max values at each level of the tree
        vector<int> maxLevelVal;
        
        if(root == NULL)return maxLevelVal;
        
        // it will be used to do Level Order traversal of the tree
        queue<TreeNode*> levelQueue;
        levelQueue.push(root);
        
        while(!levelQueue.empty()){
            int size = levelQueue.size();
            //here you are exploring current level nodes and equeueing their neighbors in the queue
            //to store max value node at current level
            int maxValNode = INT_MIN;
            while(size>0){
                TreeNode * currNode = levelQueue.front();
                maxValNode = max(currNode->val, maxValNode);
                levelQueue.pop();
                //enqueue it's neighbors or say children
                if(currNode->left != NULL){
                    levelQueue.push(currNode->left);
                }
                if(currNode->right != NULL){
                    levelQueue.push(currNode->right);
                }
                size--;
            }
            maxLevelVal.push_back(maxValNode);
        }
        return maxLevelVal;
    }
};
