#include<bits/stdc++.h>
using namespace std;
   //day-72
   //MS001;


 class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x){
        val=x;
    }
    void addLeft(int x){
        TreeNode* leftP = new TreeNode(x);
        this ->left =leftP;
    }
     void addRight(int x){
        TreeNode* rightP = new TreeNode(x);
        this->right =rightP;
    }

 };  
 
TreeNode* makeTree(vector<int>nodeV,int ind,int n){
 if (ind >=n || nodeV[ind]==-1) return nullptr;
 TreeNode * root =new TreeNode(nodeV[ind]);
 root->left  =makeTree(nodeV,2*ind,n);
 root->right =makeTree(nodeV,(2*ind)+1,n);
 return root;
}
void LevelOrder(queue<TreeNode*>&q,int &lvl,int &cnt){
   if(!(q.empty())){
        if(q.front()==nullptr) {cout<<"-1" ;
            q.pop();
            cnt++;
            if(cnt==pow(2,lvl)){
                cout<<endl;
                lvl++;
            }
            LevelOrder(q,lvl,cnt);
            return ;
        }

    
        cout<<" "<<q.front()->val<<" ";
        if(q.front()->left!=nullptr || q.front()->right!=nullptr){
            q.push(q.front()->left);
            q.push(q.front()->right);    
        }
        
        q.pop();
        cnt++;
        if(cnt==pow(2,lvl)){
            cout<<endl;
            lvl++;
            cnt=0;
        }
        LevelOrder(q,lvl,cnt);
    }
   
    return;
}
 void getDistance(TreeNode*target,int k,vector<bool>&visited,unordered_map<TreeNode*,TreeNode*>&parent,int dist,vector<int>&ans){
        if(target==nullptr) return;
        if(dist==k){
         
            ans.push_back(target->val);
        }
        visited[target->val]=true;
        
        if(target->left!=nullptr && !visited[target->left->val]){
            getDistance(target->left,k,visited,parent,dist+1,ans);
        }
        if(target->right!=nullptr && !visited[target->right->val]){
            getDistance(target->right,k,visited,parent,dist+1,ans);
        }
        if(parent[target]!=nullptr && !visited[parent[target]->val]){
            getDistance(parent[target],k,visited,parent,dist+1,ans);
        }
        return;
        
    }
    void getParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent){
        if(root==nullptr) return;
        if(root->left==nullptr && root->right==nullptr){
            return;
        }
        parent[root->left]=root;
        parent[root->right]=root;
        getParents(root->left,parent);
        getParents(root->right,parent);
        return;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        unordered_map<TreeNode*,TreeNode*>parent;
        vector<bool>visited(500,false);
        parent[root]=nullptr;
        getParents(root,parent);
        
        getDistance(target,k,visited,parent,0,ans);
        return ans;
    }
int main(){

int n;

vector<int>LevelNodes= {0,2,13,5,67,54,-1,33,15,68,12,24,-1,-1,-1,99,88,64};
n=LevelNodes.size();
TreeNode* root =makeTree(LevelNodes,1,n);
queue<TreeNode*>q;
q.push(root);
int lvl=0,cnt=0;
LevelOrder(q,lvl,cnt);
cout<<endl;
TreeNode * target =root->left->left->right;
vector<int> ans = distanceK(root,target,3);

 for(auto&x:ans){
    cout<<x<<" ";
 }
 cout<<endl;
return 0;
}
