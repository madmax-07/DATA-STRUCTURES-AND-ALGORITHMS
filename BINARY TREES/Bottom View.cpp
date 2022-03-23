class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int>ans;
        if(root==NULL)
         return ans;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        map<int,vector<int>>mp;
        while(!q.empty()){
            pair<Node*,int>p=q.front();
            q.pop();
            Node*temp=p.first;
            int col=p.second;
            mp[col].push_back(temp->data);
            if(temp->left)
            q.push({temp->left,col-1});
            if(temp->right){
                q.push({temp->right,col+1});
            }
        }
        
        for(auto it:mp){
            vector<int>v=it.second;
            int n=v.size()-1;
            ans.push_back(v[n]);
        }
        return ans;
        // Your Code Here
    }
};
