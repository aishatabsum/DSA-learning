#include <iostream>

using namespace std;

class Node{
 public: 
 int data;
 Node *next;
 Node* prev;
};

class Doubly_LLC{
 public:
    Node *head;

    public:
    Doubly_LLC(){
    head=NULL;
    }
    Doubly_LLC(int A[], int n);
    void DisplayCir();
    void Insert(int index, int x);
    int Delete(int index);
     int LengthLL();
     int Max();
     int Min();
     int LSearch(int key);
     bool isSorted();
     bool isLoop();
     int SumEle();
     ~Doubly_LLC();
};


Doubly_LLC::Doubly_LLC(int A[], int n){
int i=0;
 Node *t,*last;
 head=new Node;
 head->data=A[0];
 head->next=head->prev=head;
 last=head;

 for(i=1; i<n; i++){
 t=new Node;
 t->data=A[i];
 t->next=last->next;
 last->next=t;
 t->prev=last;
 head->prev=t;
 last=t;
}
 }
 


 int Doubly_LLC:: LengthLL(){
      Node*p=head;
    int count =0;
    do{
        count++;
        p=p->next;
    }while(p!=head);
    return count;
 }


int Doubly_LLC::SumEle(){
      Node*p=head;
    int sum=0;
   do{
        sum+=p->data;
        p=p->next;
    }while(p!=head);
    return sum;
}


int Doubly_LLC:: Max(){
    Node*p=head;
    int x=INT_MIN;
  do{
    if(p->data > x){
        x=p->data;
    }
    p=p->next;
   }while(p!=head);
   return x;
}


int Doubly_LLC:: Min(){
    Node *p=head;
    int x= INT_MAX;
    do{
    if(p->data < x){
        x=p->data;
    }
     p=p->next;
   }while(p!=head);
   return x;
}

// here index means at this index should be inserted
void Doubly_LLC::Insert(int index, int x){
    Node *t,*p=head;
    if(index<0 ||index>LengthLL()){
        return;
    }

    if(index==0){
    t=new Node;
    t->data=x;
    if(head==NULL){
        head =t;
        head->next=head;
        head->prev=head;
    }
    else{
       t->next=head;
       t->prev=head->prev;
        head->prev->next=t;
       head->prev=t;
     head=t;
    }
}
    else{
       for(int i = 0; i < index - 1; i++){
            p = p->next;      
        }
        t=new Node;
        t->data=x;
      t->next=p->next;
      t->prev=p;
      if(p->next)
      p->next->prev=t;
       p->next=t;
    }
    
}// constant time

bool Doubly_LLC::isLoop(){
    if(head==NULL) return false;
    if(head->next==head) return true;
    Node *slow,*fast;
    slow=fast=head;
    do{
        slow=slow->next;
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
    }while(slow!=NULL && fast!=NULL &&slow!=fast);
    if(slow==fast){return true;}
    else return false;
}


void Doubly_LLC::DisplayCir(){
 if(head == NULL){
        cout << "Empty list" << endl;
        return;
    }
    
    if(!isLoop()){
        cout << "Error: Not a circular list" << endl;
        return;
    }
    Node *p=head;
do{
    cout<<(p->data)<<" ";
    p=p->next;

}while(p!=head);
cout<<"\n";
}


int Doubly_LLC:: Delete(int index){
Node*q,*p=head;
int x;
if(index<1||index>LengthLL()){
    return -1;
}
if(index==1){ 
    x=head->data;
    if(head->next==head){
        delete head;
        head=NULL;
    }
    else{
        Node*temp=head;
head->prev->next=head->next;
   head->next->prev=head->prev;
    head=head->next;
    delete temp;
    }
}
else 
{
    for(int i=0; i<index-2; i++){
        p=p->next;
    }
    q=p->next;
    p->next=q->next;
    q->next->prev=p;
    x=q->data;
    delete q;
}
return x;
}

bool Doubly_LLC::isSorted(){
    int x=INT_MIN;
    Node*p=head;
    do{
        if(p->data<x){
            return false;
        }
        x=p->data;
        p=p->next;

    }while(p!=head);
    return true;
}

int Doubly_LLC::LSearch(int key){
Node*p=head;
int index=0;
    do{
        if(key==p->data){
            return index;
        }
        p=p->next;
        index++;
    }while(p!=head);
    return -1;
}


Doubly_LLC::~Doubly_LLC(){
    Node *p=head;
    while(p->next!=head){
        p=p->next;
    }
    while(p!=head){
        p->next=head->next;
        delete head;
        head=p->next;
    }

    if(p==head){
        delete head;
        head=NULL;
    }
    }
 

int main(){
  int Arr[]={2,4,7,9,1};
Doubly_LLC l(Arr, 5);
cout<<"length of Circular linked list: "<<l.LengthLL()<<endl;
cout<<"Display the elements of circular ll: "<<endl;
l.DisplayCir();
cout<<"Maximum number: "<<l.Max()<<endl;
cout<<"Minimum number: "<<l.Min()<<endl;
int i=l.LSearch(9);
if(i==-1)cout<< "Key not found"<<endl; else cout<<"Key found at index "<<i+1<<endl; 
cout<<"LinkedList is Sorted: "<<boolalpha<<l.isSorted()<<endl;
l.Insert(4,19);
cout<<"element: "<<l.Delete(3)<<" at index 3 is deleted "<<endl;
cout<<"LinkedlistC is loop: "<<boolalpha<<l.isLoop()<<endl;
cout<<"displaying after insertion and deletion: "<<endl;
l.DisplayCir();
l.Insert(5,10);
cout<<"after inserting again: "<<endl;
l.DisplayCir();
cout<<"length after insertion of other element: "<<l.LengthLL()<<endl;

}
