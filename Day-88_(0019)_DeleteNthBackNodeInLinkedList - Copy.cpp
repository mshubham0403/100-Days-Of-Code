#include<bits/stdc++.h>
using namespace std;
   //day-86
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
    pair<int,bool> removeNth(Node *head,int n){
        if(head==nullptr){
            return {1,false};
        }
        pair<int,bool> backInd =removeNth(head->next,n);
        if(backInd.first==n+1){
                backInd.second=true;
                head->next=head->next->next;
        }
        return {backInd.first+1,backInd.second};
    }
  Node* removeNthFromEnd(Node* head, int n) {
     pair<int,bool> dummy =removeNth(head,n);
      if(!dummy.second){
          return head->next;
      }
     return head;
  }

int main(){

int n;

vector<int>Nodes= {2,13,5,67,54,-12,33,15,68,12,24,-14,15,61,99,88,64};

Node* head =makeList(Nodes);
Node* delNode = head->next->next->next;
printList(head);
Node* ans =removeNthFromEnd(head,4);
printList(ans);
return 0;
}
