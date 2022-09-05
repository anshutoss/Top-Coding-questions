class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(root==NULL) return res;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int> cur;
            for(int i=0;i<size;i++){
                Node* tmp=q.front();q.pop();
                cur.push_back(tmp->val);
                for(Node* child:tmp->children)
                    if(child) q.push(child);
            }
            res.push_back(cur);
        }
        return res;
    }
};