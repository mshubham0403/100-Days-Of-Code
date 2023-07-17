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
   Node* deleteMiddle(Node* head) {
        if(head==nullptr ) return head;
        if(head->next==nullptr){
            head=nullptr;
            return head;
        }
        int size=0;
        Node * ptr =head;
        while(ptr!=nullptr){
            size++;
            ptr=ptr->next;
        }
        int middle =size/2;
        int cnt=0;
        ptr=head;
        while(cnt<middle-1){
            cnt++;
            ptr=ptr->next;
        }
        Node* a=ptr->next;
        ptr->next =ptr->next->next;
        a->next=nullptr;
        return head;
        
        
    }

int main(){

int n;

vector<int>Nodes= {2,13,5,67,54,-12,33,15,68,12,24,-14,-15,-61,99,88,64};

Node* head =makeList(Nodes);
Node* delNode = head->next->next->next;
printList(head);
Node* ans =deleteMiddle(head);
printList(ans);
return 0;
}
