#include <iostream>
using namespace std;

class queueArr_Cir{
private:
int size; 
int front; 
int rear;
int *Q;

public:
queueArr_Cir(){
    size=0; front=rear=-1;
     Q=nullptr;
}

queueArr_Cir(int s){
size=s; front=rear=-1;
Q=new int[size];
}

~queueArr_Cir(){
delete []Q;
}

void enqueue(int x){
if((rear+1)%size==front) cout<<"Queue is already full!"<<endl;
else{
    rear=(rear+1)%size;
    Q[rear]=x;
}
}

int dequeue(){
    int x=-1;
    if(front==rear) cout<<"Queue is empty!"<<endl;
    else{
        front=(front+1)%size;
        x=Q[front];
    }
    return x;
}

void display(){
    cout<<"elements of queue:\n";
    for(int i=front+1; i<=rear; i++ ){
        cout<<Q[i]<<" ";
    }cout<<"\n";
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
int main(){
queueArr_Cir q(10);
q.enqueue(92);
q.enqueue(98);
q.enqueue(35);
q.enqueue(62);
q.enqueue(3);
q.enqueue(93);
q.enqueue(19);
q.enqueue(60);
q.display();

cout<<"length of queue: "<<q.count()<<endl;
cout<<"dequeued element from queue is: "<<q.dequeue()<<endl;
cout<<"length of queue: "<<q.count()<<endl;
q.display();
    return 0;
}