#include<bits/stdc++.h>
using namespace std;
   //day-85
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
    int carry=0;
    int sum =l1->val+l2->val;
    if(sum>9){
        carry=1;
        sum=sum%10;
    }
    Node *head3 = new Node(sum);
    Node *il1 =l1->next, *il2=l2->next,*il3=head3;
    
    while(il1!=nullptr && il2!=nullptr){
       int sumi = il1->val + il2->val + carry;
       carry=0;
       if(sumi>9){
            carry=1;
            sumi=sumi%10;
        }  
        head3->next =new Node(sumi);
        il1=il1->next;
        il2=il2->next;
        head3 =head3->next;
    }

      while(il1!=nullptr){
          head3->next = new Node(il1->val);
          head3=head3->next;
          if(carry){
            (head3->val)++;
            if((head3->val)<=9){
            carry=0;
            }
            else{
           
                 head3->val =((head3->val)%10);
            }
          }
         
          il1=il1->next;
          
      }
       while(il2!=nullptr){
          head3->next = new Node(il2->val);
          head3=head3->next;
          if(carry){
            (head3->val)++;
            if((head3->val)<=9){
              carry=0;
            }
            else{
              head3->val =((head3->val)%10);
            }
          }
          il2=il2->next; 
      }
      if(carry){
          
          head3->next =new Node(1);
          head3=head3->next;
      }
      head3->next=nullptr;
      return il3;
  }

int main(){

int n;

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
