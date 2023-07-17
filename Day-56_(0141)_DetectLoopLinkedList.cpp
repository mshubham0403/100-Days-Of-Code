#include<bits/stdc++.h>
using namespace std;
   //day-56
   //MS001;


 class Node{
    public:
    int val;
    Node* next;


    Node(int x){
        val=x;
    }
    void addNext(int x){
        Node* nextP = new Node(x);
        this ->next =nextP;
    }
 
     

 };
    void printList(Node* head){
        Node* itr =head;
        while(itr!=nullptr){
            cout<<itr->val<<"->";
        }
        cout<<"N0\n";
    }
 Node* makeList(vector<int>nums){
    Node* head =new Node(nums[0]);
    Node*itr =head;
    for(int i=1;i<nums.size();i++){
    itr->addNext(nums[i]);
    itr=itr->next;
    }
    itr->next=nullptr;
    return head;

 }  
 bool hasCycle(Node* head) {
      if(head==nullptr ||head->next==nullptr){
          return false;
      }
  Node *fast=head->next,*slow=head;
   while(fast!=slow){   
      if(fast->next==nullptr) return false;
      if(fast->next->next==nullptr) return false;
      fast=fast->next->next;
      slow=slow->next;
   }
      return true;
  }

int main(){



vector<int>Nodes= {2,13,5,67,54,-12,33,15,68,12,24,-14,-15,-61,99,88,64};

Node* head =makeList(Nodes);
Node* loopNode = head->next->next->next;
Node *itr =head;
while(itr->next!=nullptr){
    itr=itr->next;
}
itr->next=loopNode;
bool ans =hasCycle(head);
cout<<ans<<"\n";
return 0;
}
