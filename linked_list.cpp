#include <iostream>

using namespace std;

class Node{
 public: 
 int data;
 Node *next;
};

class LinkedList{
 public:
    Node *first;

    public:
    LinkedList(){
    first=NULL;
    }
    LinkedList(int A[], int n, bool isCircular);
    void Display();
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
     ~LinkedList();
};


LinkedList::LinkedList(int A[], int n, bool isCircular){
int i=0;
 Node *t,*last;
    if(isCircular==false){
 first=new Node;
 first->data=A[0];
 first->next=NULL;
 last=first;

 for(i=1; i<n; i++){
 t=new Node;
 t->data=A[i];
 t->next=NULL;
 last->next=t;
 last=t;
}
 }else{
 
 first=new Node;
 first->data=A[0];
 first->next=first;
 last=first;

 for(i=1; i<n; i++){
 t=new Node;
 t->data=A[i];
 t->next=last->next;
 last->next=t;
 last=t;
}
 }
 }



 void LinkedList::Display(){
      Node*p=first;
    while(p!=NULL){
        cout<<p->data<<"  ";
        p=p->next;
    }
 }

 int LinkedList:: LengthLL(){
      Node*p=first;
    int count =0;
    while(p!=NULL){
        count++;
        p=p->next;
    }
    return count;
 }


int LinkedList::SumEle(){
      Node*p=first;
    int sum=0;
     while(p){
        sum+=p->data;
        p=p->next;
    }
    return sum;
}


int LinkedList:: Max(){
    Node*p=first;
    int x=INT_MIN;
   while(p){
    if(p->data > x){
        x=p->data;
    }
    p=p->next;
   }
   return x;
}


int LinkedList:: Min(){
    Node *p=first;
    int x= INT_MAX;
   while(p){
    if(p->data < x){
        x=p->data;
    }
p=p->next;
   }
   return x;
}

void LinkedList::Insert(int index, int x){
    Node *t, *p=first;
    if(index<0 ||index>LengthLL()){
        return;
    }
    t=new Node;
    t->data=x;
    t->next=NULL;

    if(index==0){
       t->next=first;
        first=t;
    }
    else{
       for(int i = 0; i < index - 1; i++){
            p = p->next;        // ONLY traverse
        }
        t->next = p->next;      
        p->next = t; 
    }
    
}

bool LinkedList::isLoop(){
    Node *slow,*fast;
    slow=fast=first;
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


void LinkedList::DisplayCir(){
 if(first == NULL){
        cout << "Empty list" << endl;
        return;
    }
    
    if(!isLoop()){
        cout << "Error: Not a circular list" << endl;
        return;
    }
    Node *p=first;
do{
    cout<<(p->data)<<" ";
    p=p->next;

}while(p!=first);
cout<<"\n";
}


int LinkedList:: Delete(int index){
Node*p, *q=NULL;
int x=-1;
if(index<1||index>LengthLL()){
    return -1;
}
if(index==1){
    p=first;
    first=first->next;
    x=p->data;
    delete p;
}else 
{
    p=first;
    for(int i=0; i<index-1; i++){
        q=p;
        p=p->next;
    }
    q->next=p->next;
    x=p->data;
    delete p;
}
return x;
}

bool LinkedList::isSorted(){
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
}

int LinkedList::LSearch(int key){
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
}

// LinkedList::~LinkedList(){
//     Node*p;
//     while(first){
//         first=first->next;
//         delete p;
//         p=first;
//     }
// }

LinkedList::~LinkedList(){
    if(first == NULL) return;
    
    if(isLoop()){
        // Break circular link
        Node *p = first;
        while(p->next != first){
            p = p->next;
        }
        p->next = NULL;  // now linear
    }
    
    // Delete as linear
    Node *p = first;
    while(p){
        Node *temp = p;
        p = p->next;
        delete temp;
    }
    first = NULL;
}


int main(){
  int Arr[]={2,4,7,9,1};
LinkedList l1(Arr, 5,false);

   cout<<"length of linked list: "<<l1.LengthLL()<<endl;
   cout<<"Display the elements: "<<endl;

l1.Display();
cout<<"Maximum number: "<<l1.Max()<<endl;
cout<<"Minimum number: "<<l1.Min()<<endl;
int i=l1.LSearch(9);
if(i==-1)cout<< "Key not found"<<endl; else cout<<"Key found at index "<<i+1<<endl; 
cout<<"LinkedList is Sorted: "<<boolalpha<<l1.isSorted()<<endl;
LinkedList l2(Arr,5,true);
cout<<"Linkedlist l1 is loop: "<<boolalpha<<l1.isLoop()<<endl;
cout<<"Linkedlist l2 is loop: "<<boolalpha<<l2.isLoop()<<endl;
cout<<"Displaying circular LL:"<<endl;
l2.DisplayCir();

}
