#include <iostream>
using namespace std;

class Node{
 public: 
 Node * prev;
 int data;
 Node *next;
};

class DoublyLL{
 private:
Node* first;

public:
DoublyLL(int A[], int n);
void DisplayDLL();
void Insert(int index, int x);
int Delete(int index);
int LengthDLL();
int Max();
int Min();
int LSearch(int key);
bool isSorted();
void ReverseDLL();
~DoublyLL();

};


DoublyLL::DoublyLL(int A[], int n){
int i=0;
 Node *t,*last;
 first=new Node;
 first->data=A[0];
 first->next=first->prev=NULL;
 last=first;

 for(i=1; i<n; i++){
 t=new Node;
 t->data=A[i];
 t->next=last->next;
 t->prev=last;
 last->next=t;
 last=t;
}
}

DoublyLL::~DoublyLL(){
   Node*p=first;
    while(first){
        first=first->next;
        delete p;
        p=first;
    }
}



void DoublyLL::DisplayDLL(){
       Node*p=first;
    while(p!=NULL){
        cout<<p->data<<"  ";
        p=p->next;
    }

}//O(n)



void DoublyLL::Insert(int index, int x){
Node *t,*p=first;
    if(index<0||index>LengthDLL()){
    return;
}
t= new Node;
 t->data=x;
 t->next =t->prev= NULL;
if(index==0){
t->next=first;
first->prev=t;
first=t;
}else{
    for(int i=0; i<index-1;i++){
        p=p->next;
    }
      t->next=p->next;
      t->prev=p;
      if(p->next)
      p->next->prev=t;
       p->next=t;
}
}//min:O(1), max:O(n)


int DoublyLL::Delete(int index){
Node*p;
int x=-1;
if(index<1||index>LengthDLL()){
    return -1;
}
if(index==1){
    p=first;
    first=first->next;
    if(first) first->prev=NULL;
    x=p->data;
    delete p;
}else 
{
    p=first;
    for(int i=0; i<index-1; i++){
        p=p->next;
    }
 p->prev->next=p->next;
 //there is no next or prev to null
 //so we check first if p->next!=NULL
 if(p->next)
   p->next->prev=p->prev;
    x=p->data;
    delete p;
}
return x;
}
//min:O(1), max:O(n)

int DoublyLL::LengthDLL(){
Node*p=first;
    int count =0;
    while(p!=NULL){
        count++;
        p=p->next;
    }
    return count;
}
//O(n)

int DoublyLL::Max(){
Node* p=first;
int x=INT_MIN;
while(p!=NULL){
   if(p->data>x)
   x=p->data;
   p=p->next;
}return x;
}//O(n)

int DoublyLL::Min(){
Node* p=first;
int x=INT_MAX;
while(p!=NULL){
   if(p->data<x)
   x=p->data;
   p=p->next;
}return x;
}//O(n)


int DoublyLL::LSearch(int key){
Node*p=first;
int index=0;
    while(p!=NULL){
        if(key==p->data){
            return index;
        }
        p=p->next;
        index++;
    }
    return -1;
}//min:O(1), max:O(n)


bool DoublyLL::isSorted(){
int x=INT_MIN;
    Node*p=first;
    while(p!=NULL){
        if(p->data<x){
            return false;
        }
        x=p->data;
        p=p->next;

    }
    return true;
}//min:O(1), max:O(n)


void DoublyLL::ReverseDLL(){
    Node*temp,*p=first;
    while(p){
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;
        //this is checked before swapping while in loop
        if(p!=NULL && p->next==NULL){
         first=p;
        }
    }
}

int main(){
    int Arr[]={9,29,447,12,44,122,5,23};
DoublyLL d(Arr, sizeof(Arr)/sizeof(Arr[0]));
cout<<"Displaying doubly linked list:"<<endl;
d.DisplayDLL();
cout<<"\nlength of doubly ll: "<<d.LengthDLL()<<"\nMaximum number: "<<d.Max();
cout<<"\nMinimum Number: "<<d.Min()<<endl;
d.Insert(0,17);
d.Insert(5,90);
cout<<"\nLength after inserting two elements: "<<d.LengthDLL()<<endl;
cout<<"Doubly LL is sorted: "<<boolalpha<<d.isSorted()<<endl;
cout<<"Searching for index of element: 12....\n";
cout<<"Element found at index: "<<d.LSearch(12)<<endl;
d.DisplayDLL();
}