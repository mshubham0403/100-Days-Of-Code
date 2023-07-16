#include<bits/stdc++.h>
using namespace std;
   //day-84
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
  Node* oddEvenList(Node* head) {
       if(head == nullptr)return head;
       if(head->next ==nullptr)return head;
       if(head->next->next==nullptr) return head;
        
        Node* oddpnt =head;
        Node* evnpnt =head->next;
        Node* evnBgn =head->next;
        Node* oddBgn =head;

        while(oddpnt->next->next!=nullptr && evnpnt->next->next!=nullptr){
            oddpnt->next = oddpnt->next->next;
            evnpnt->next = evnpnt->next->next;
            oddpnt = oddpnt->next;
            evnpnt =evnpnt->next;
            
        }
        while(oddpnt->next!=nullptr){
            if(oddpnt->next->next!=nullptr){
            oddpnt->next = oddpnt->next->next;
             oddpnt = oddpnt->next;
            }
            else{
                 oddpnt->next=nullptr;
                break;
            }
        }
          while(evnpnt->next!=nullptr){
              if(evnpnt->next->next!=nullptr){
            evnpnt->next = evnpnt->next->next;
             evnpnt = evnpnt->next;
              }
              else{
                  evnpnt->next=nullptr;
                  break;
              }
        }
        oddpnt->next = evnBgn;
        return oddBgn;

        
    }

int main(){

int n;

vector<int>Nodes= {2,13,5,67,54,-12,33,15,68,12,24,-14,-15,-61,99,88,64};

Node* head =makeList(Nodes);
Node* delNode = head->next->next->next;
printList(head);
Node* ans =oddEvenList(head);
printList(ans);
return 0;
}
