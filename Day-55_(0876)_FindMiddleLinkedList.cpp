#include<bits/stdc++.h>
using namespace std;
   //day-55
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
 Node* middleNode(Node* head) {
    Node* slow=head;Node* fast=head;
      while(fast->next!=nullptr){
          if(fast->next->next!=nullptr){
          slow=slow->next;
          fast=fast->next->next;
          }
          else{
              slow=slow->next;
              break;
          }
      }

      return slow;
  }

int main(){



vector<int>Nodes= {2,13,5,67,54,-12,33,15,68,12,24,-14,-15,-61,99,88,64};

Node* head =makeList(Nodes);
Node* delNode = head->next->next->next;
printList(head);
Node* ans =middleNode(head);
printList(ans);
return 0;
}
