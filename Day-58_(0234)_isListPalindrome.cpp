#include<bits/stdc++.h>
using namespace std;
   //day-58
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
Node* reveseList(Node* head){
       Node *prev =nullptr,*curr=head;
        while(curr!=nullptr){
           Node *temp=curr->next;
            curr->next =prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    Node* getMiddle(Node*head){
        Node *slow=head,*fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next->next;
            if(fast==nullptr){
                break;
            }
            slow=slow->next;
        }
        return slow;
    }
  bool isPalindrome(Node* head) {
        Node* midd =getMiddle(head);
        Node* newMidNext = reveseList(midd->next);
      Node *itr =head;
        while(newMidNext!=nullptr){
            if(itr->val!=newMidNext->val){
                return false;
            }
            newMidNext =newMidNext->next;
            itr=itr->next;
        }
      return true;
  }

int main(){



vector<int>Nodes= {1,2,3,0,3,2,1};

Node* head =makeList(Nodes);
bool ans =isPalindrome(head);
cout<<ans<<"\n";
return 0;
}
