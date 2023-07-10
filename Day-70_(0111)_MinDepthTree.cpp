#include<bits/stdc++.h>
using namespace std;
   //day-70
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
 int getNodesTillLeaf(TreeNode * root){
      
        if(root == nullptr) return 0;
      
        if(root->left ==nullptr && root->right==nullptr){
            return 1;
        }
       if(root->left==nullptr){
           return 1+getNodesTillLeaf(root->right);
       }
          if(root->right==nullptr){
           return 1+getNodesTillLeaf(root->left);
       }
        int cnt  =min(1+getNodesTillLeaf(root->left),1+getNodesTillLeaf(root->right));
        return cnt;
    }
    int minDepth(TreeNode* root) {
        int ans =getNodesTillLeaf(root);
        return ans;
    }

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
int ans = minDepth(root);

 cout<<ans;
 //ans
 cout<<endl;
return 0;
}
