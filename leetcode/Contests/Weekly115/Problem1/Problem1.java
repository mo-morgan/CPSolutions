/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    
    
    public boolean isCompleteTree(TreeNode root) {
        int nodes = countNodes(root);
        int index = 0;
        
        if (isComplete(root, index, nodes)) {
            return true;
        } else {
            return false;
        }
    }
    
    public int countNodes(TreeNode root)  { 
        if (root == null) 
            return (0); 
        
        return (1 + countNodes(root.left) + countNodes(root.right)); 
    } 
    
    public boolean isComplete(TreeNode root, int index, int nodes) {
        if (root == null) {
            return true;
        }
        
        if (index > nodes - 1) {
            return false;
        }
        
        return (isComplete(root.left, 2 * index + 1, nodes)
               && isComplete(root.right, 2 * index + 2, nodes));
    }
}