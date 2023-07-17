#include<bits/stdc++.h>
using namespace std;
   //day-87
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
            itr=itr->next;
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
   Node* addTwoNumbers(Node* l1, Node* l2) {
        stack<int>st1;
        stack<int>st2;
        Node *il1=l1,*il2=l2;
        while(il1!=nullptr){
            st1.push(il1->val);
            il1=il1->next;
        }
         while(il2!=nullptr){
            st2.push(il2->val);
            il2=il2->next;
        }
        Node *head = nullptr;
        int carry=0;
        int sumi=0;
        while(!st1.empty() && !st2.empty()){
            sumi =(st1.top()+st2.top()+carry);
            int dig =sumi%10;
            carry=sumi/10;
            st1.pop();st2.pop();
            Node *prev =new Node(dig);
            prev->next=head;
            head=prev;
        }
        while(!st1.empty()){
            sumi=st1.top()+carry;
            int dig =sumi%10;
            carry=sumi/10;
            st1.pop();
            Node *prev =new Node(dig);
            prev->next=head;
            head=prev;
        }
        while(!st2.empty()){
            sumi=st2.top()+carry;
            int dig =sumi%10;
            carry=sumi/10;
            st2.pop();
            Node *prev =new Node(dig);
            prev->next=head;
            head=prev;
        }
        if(carry){
            Node *prev =new Node(1);
            prev->next=head;
            head=prev;
        }
        return head;
    }

int main(){

vector<int>Nodes= {2,3,9,8,1,2};
vector<int>Nodes2 ={9,6,7,9,9,2,9};

Node* head =makeList(Nodes);
Node* head2 =makeList(Nodes2);
printList(head);
printList(head2);
Node* ans =addTwoNumbers(head,head2);
printList(ans);
return 0;
}
