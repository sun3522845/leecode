/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int GetPathToRoot(TreeNode* root, TreeNode *p, stack<TreeNode *> &path){
        path.push(root);
        
        while(!path.empty()){
            TreeNode* tmp = path.top();
            if(tmp==p){
                return 0;
            }
            if(tmp->left){
                path.push(tmp->left);
            }else if(tmp->right){
                path.push(tmp->right);
            }else{
                path.pop();
                while(!path.empty()){
                    if(path.top()->left==tmp && path.top()->right){
                        path.push(path.top()->right);
                        break;
                    }else{
                        tmp = path.top();
                        path.pop();
                    }
                }
                
            }
           
            
        }
        return 1;
        
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode *> path_p,path_q;
        if(GetPathToRoot(root,p,path_p)==0 && GetPathToRoot(root,q,path_q)==0){
            if(path_p.size()>path_q.size()){
                while(path_p.size()!=path_q.size()){
                    path_p.pop();
                }
            }else if(path_p.size()<path_q.size()){
                  while(path_p.size()!=path_q.size()){
                    path_q.pop();
                }
            }
            while(path_p.top()!=path_q.top()){
                path_p.pop();
                path_q.pop();
            }
            return path_p.top();
        }
        else{
            return NULL;
        }
    }
};