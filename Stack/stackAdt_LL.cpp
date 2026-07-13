#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

class StackLL{
    private:
    Node *Top;

    public:
     StackLL(){
        Top=NULL;
     }

    ~StackLL(){
    if(!Top)
     return;
      Node *p=Top;
       while(p){
        Node *temp=p;
        p=p->next;
       delete temp;
       }
       Top=NULL;
    }

     void push(int x){
        Node *t= new Node;
        if(t==NULL){
            cout<<"stack overflow!\n";
        }
        else{
            t->data=x;
            t->next=Top;
            Top=t;

        }
     }


     int pop(){
        int x=-1;
        Node*p= Top;
        if(!Top){
         cout<<"Stack underflow!\n";
        }
        else 
        {
            x= Top->data;
            Top=Top->next;
            delete p;
        }
        return x;
     }



     bool isEmpty(){
        if(!Top) return true;
        else return false; 
     }

     bool isFull(){
       Node *t= new Node;
       if(t) return false;
       else {
        delete t;
        return true;
       }
     }

     int stackTop(){
        if(Top) return Top->data;
        else return -1;
     }

    int count(){
        Node *p=Top;
        int count=0;
        while(p){
            count++;
            p=p->next;
        }
        return count;
    }
     int peek(int position){
     Node*p=Top;
     for(int i=0; i<position-1&&p!=NULL; i++){
     p=p->next;
     }
     if(p) return p->data;
     else return -1;
     }

    void display(){
        cout<<"Display of elements of stack:\n";
        Node *p=Top;
        while(p){
            cout<<p->data<<" ";
           p=p->next;
        }cout<<"\n";
    }

};

int main(){
     
StackLL s;
s.push(90);
s.push(167);
s.push(78);
s.push(88);
s.push(356);

cout<<"Length of stack: "<<s.count()<<endl;
s.display();
cout<<"popped value from stack: "<<s.pop()<<endl;
s.display();
cout<<"Length of stack: "<<s.count()<<endl;
cout<<"Top value from stack: "<<s.stackTop()<<endl;
cout<<"peeked value from stack at position 3: "<<s.peek(3)<<endl;

    return 0;
}