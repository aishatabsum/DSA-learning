#include <iostream>
using namespace std;
class stack{
   private:

   int size;
    int Top;
    int *A;
public:

stack(){
Top=-1;
size=0;
A=nullptr;
}

stack(int s){
Top=-1;
size=s;
A =new int[size];
}

void push(int x){
if(isFull()){
    cout<<"Stack overflow!\n";
}else
A[++Top]=x;
}

~stack() {
        delete[] A;
    }

int pop(){
if(isEmpty()){
    cout<<"Stack underflow!\n";
    return -1;
}else
return A[Top--];
}

void display(){
    cout<<"Stack (top to bottom): ";
    for(int i=Top; i>=0; i--){
        cout<<A[i]<<" ";
    }
    cout<<"\n";
}
void change(int position, int newEle){
if(Top-position+1 <0 || Top-position+1>Top){
    cout<<"Invalid Position1\n";
    
}else 
   A[Top-position+1]=newEle;
}

//look at which position
int peek(int position){
//position to index
if(Top-position+1 <0 || position<0){
    cout<<"Invalid Position1\n";
    return -1;
}else 
return A[Top-position+1];
}

//returns the top value- also called peek()
int stackTop(){
    if(!isEmpty())
return A[Top];
else return -1;
}

int length(){
return Top+1;
}

bool isEmpty(){
if(Top==-1)  return true;
else return false;

}

bool isFull(){
    if(Top==size-1)   return true;
    else return false;
}
};


int main(){

    stack s(10);
    s.display();
    s.push(12);
    s.push(177);
    s.push(73);
    s.push(100);
cout<<"Length of stack: "<<s.length()<<endl;


    s.display();
    cout<<"Popped element: "<<s.pop()<<"\n";
    s.display();
cout<<"Length of stack: "<<s.length()<<endl;

cout<<"Value at top of stack: "<<s.stackTop()<<endl;
cout<<"Peeked value at position 2(top-bottom): "<<s.peek(2)<<endl;

return 0;
}