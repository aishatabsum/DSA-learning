#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
  };

class queueLL{
  Node *front;
  Node* rear;
public:
  queueLL(){
   front=rear=NULL;
  }
  ~queueLL(){
  Node*p=front;
  while(p){
   Node* temp;
   temp=p;
   p=p->next;
   delete temp;
  }

  
  }
   void enqueue(int x){
Node *t=new Node;
if(isFull()){
    cout<<"Queue is full!\n";
}
else{
    t->data=x;
    t->next=NULL;
    //first node
    if(isEmpty()) front=rear=t;
    else{
        rear->next=t;
        rear=t;
    }
  }
}//O(1)

    int dequeue(){
        int x=-1;
        Node*p;
     if(isEmpty()) cout<<"Queue is empty!\n";
    else{
        p=front;
        front=front->next;
        x=p->data;
        delete p;
    }
    return x;
    }//O(1)

    void display(){
        Node*p=front;
        cout<<"Elements of Queue:\n";
        while(p){
            cout<<p->data<<" ";
            p=p->next;
        }cout<<"\n";
    }
    
    bool isFull(){
     Node*t = new Node;
     return t==NULL? true:false;
    }


   bool isEmpty(){
        return front==NULL? true:false;
    }
};


int main(){
    queueLL q;
q.enqueue(92);
q.enqueue(98);
q.enqueue(35);
q.enqueue(62);
q.enqueue(3);
q.enqueue(93);
q.enqueue(19);
q.enqueue(60);
q.display();
cout<<"Dequeued element : "<<q.dequeue()<<endl;
q.display();
     return 0;
}