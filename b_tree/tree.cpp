#include <iostream>
using namespace std;


class Node{
public:
int data;
Node *left;
Node* right;
};

//queue for storing addresses
class queue{
private:
int size; 
int front; 
int rear;
Node **Q;

public:
queue(){
    size=0; front=rear=-1;
     Q=nullptr;
}
queue(int s){
size=s; front=rear=-1;
Q=new Node*[size];
}

~queue(){
delete []Q;
}

void enqueue(Node* x){
if(rear==size-1) cout<<"Queue is already full!"<<endl;
else{
    rear++;
    Q[rear]=x;
}
}

    Node* dequeue(){
   Node* x=NULL;
    if(front==rear) cout<<"Queue is empty!"<<endl;
    else{
        front++;
        x=Q[front];
    }
    return x;
}

int count(){
    if(isEmpty()) return 0;
    else return rear-front;
}
bool isFull(){
return rear==size-1? true:false;
}
bool isEmpty(){
return front==rear? true:false;
}
};


class tree{
public:
Node* root;

tree(){
root=NULL;
}
void destroy(Node* p) {
    if(p) {
        destroy(p->left);
        destroy(p->right);
        delete p;
    }
}

~tree(){
    destroy(root);
}

void create(){
Node*p, *t;
int x=-1;
queue q(10);
cout<<"Enter the root value: "; cin>>x;
root=new Node;
root->data=x; root->left=root->right=NULL;
q.enqueue(root);
while(!q.isEmpty()){
    p=q.dequeue();
    cout<<"Enter left child of "<<p->data<<" : ";cin>>x;
    if(x!=-1){
        t=new Node;
        t->data=x;
        t->left=t->right=NULL;
        p->left=t;
        q.enqueue(t);
    }
     cout<<"Enter right child of "<<p->data<<": ";cin>>x;
    if(x!=-1){
        t=new Node;
        t->data=x;
        t->left=t->right=NULL;
        p->right=t;
        q.enqueue(t);
    }
}
}

void levelOrder(Node*root){
    queue q(100);
    cout<<root->data;
q.enqueue(root);

while(!q.isEmpty()){
    root=q.dequeue();
    if(root->left){
        cout<<root->left->data;
        q.enqueue(root->left);
    }
    if(root->right){
        cout<<root->right->data;
        q.enqueue(root->right);
    }
}

}
void preOrder(Node*p){
   if(p){
    cout<<p->data<<" ";
    preOrder(p->left);
     preOrder(p->right);
   }
}

void InOrder(Node*p){
   if(p){
     InOrder(p->left);
    cout<<p->data<<" ";
     InOrder(p->right);
   }
}

void postOrder(Node*p){
   if(p){
     postOrder(p->left);
     postOrder(p->right);
    cout<<p->data<<" ";
   
   }
}

int count(Node*p){
    if(p){
        return count(root->left)+count(root->right)+1;
    }else
    return 0;
}

int height(Node* root){
int x=0,y=0;
if(root==0){
    return 0;
}
x=height(root->left);
y=height(root->right);
if(x>y){
    return x+1;
}else 
return y+1;
}

};

int main(){
    tree t;
    t.create();
cout<<"Displaying binary tree!(pre order traversal):\n";
t.preOrder(t.root);
cout<<"Displaying binary tree!(In order traversal):\n";
t.InOrder(t.root);
cout<<"Displaying binary tree!(post order traversal):\n";
t.postOrder(t.root);

    return 0;
}