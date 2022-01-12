vector<int> reverseLevelOrder(Node *root)
{
    vector<vector<int>>vec;
    queue<Node*>q;
    q.push(root);
    vector<int>v;
    while(!q.empty()){
        int n=q.size();
        for(int i=1;i<=n;i++){
            Node*ptr=q.front();
            q.pop();
            if(ptr->left)
            q.push(ptr->left);
            if(ptr->right)
            q.push(ptr->right);
            v.push_back(ptr->data);
        }
        vec.push_back(v);
        v.clear();
    }
    vector<int>p;
    for(int i=vec.size()-1;i>=0;i--){
        
        for(auto x:vec[i]){
            p.push_back(x);
            
        }
    }
return p;
    
}
//Time Complexity:O(n) where n is the number of nodes in the binary tree
//Auxilary Space :O(n) //n is the number of elements 

//method 2 :using a stack 
vector<int> reverseLevelOrder(Node *root)
{ queue<Node*>q;
  stack<int>s;
  vector<int>ans;
  q.push(root);
  while(!q.empty()){
      Node*temp=q.front();
      s.push(temp->data);
      q.pop();
      if(temp->right)
      q.push(temp->right);
      if(temp->left)
      q.push(temp->left);
  }
  while(!s.empty())
 { ans.push_back(s.top());
  s.pop();
}
return ans;
    // ce here
}

