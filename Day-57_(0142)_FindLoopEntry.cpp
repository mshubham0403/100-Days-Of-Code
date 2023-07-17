#include<bits/stdc++.h>
using namespace std;
   //day-57
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
Node* detectCycle(Node* head) {
   if(head==nullptr) return nullptr;
   if(head->next==nullptr)return nullptr;
   Node *slow=head,*fast=head->next;
   while(slow!=fast){
       if(fast->next==nullptr) return nullptr;
       if(fast->next->next==nullptr) return nullptr;
       fast=fast->next->next;
       slow=slow->next;
   }
   Node *entry =head;
      slow=slow->next;
      while(slow!=entry){
          slow=slow->next;
          entry=entry->next;
      }
      return entry;
      

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
Node *ans =detectCycle(head);
cout<<ans->val<<"\n";
return 0;
}
