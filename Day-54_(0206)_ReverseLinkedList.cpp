#include<bits/stdc++.h>
using namespace std;
   //day-54
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
  Node* reverseOperation(Node*curr,Node*prev){
        if(curr==nullptr)return nullptr;
        if(curr->next==nullptr){
            Node* head =curr;
            curr->next=prev;
            return head;
        }
        Node* head =reverseOperation(curr->next,curr);
        curr->next=prev;
        return head;
    }
  Node* reverseList(Node* head) {
    Node* newHead=reverseOperation(head,nullptr);
      return newHead;
  }

int main(){

int n;

vector<int>Nodes= {2,13,5,67,54,-12,33,15,68,12,24,-14,-15,-61,99,88,64};

Node* head =makeList(Nodes);
Node* delNode = head->next->next->next;
printList(head);
Node* ans =reverseList(head);
printList(ans);
return 0;
}
