#include <iostream>
#include<cstring>

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


bool isOperand(char x){
    if(x=='+'||x=='-'||x=='*'||x=='/'){
        return false;
    }else
    return true;
 }

 int preced(char x){
    if(x=='+'||x=='-') return 1;
    else if(x=='*'||x=='/') return 2;
    else return 0;
 }

 char*  convert(const char*infix){
  char *postfix=new char[strlen(infix)+1];
  int i=0, j=0;
   while(infix[i]!='\0'){
  if(isOperand(infix[i]))
  postfix[j++]=infix[i++];
  else{
    if(preced(infix[i])>preced(stackTop())){
        push(infix[i++]);
    }else{
        postfix[j++]=pop();
    }
}
  }
  while(!isEmpty()){
    postfix[j++]=pop();
 }
 postfix[j]='\0';
 return postfix;
}

int evaluate(char* postfix){
int x1,x2,i,r;
    for(int i=0; postfix[i]!='\0'; i++){
    if(isOperand(postfix[i]))  push(postfix[i]-'0');
    else{
  x2=pop();
  x1=pop();
  switch(postfix[i]){
    case '+': r=x1+x2; push(r); break;
    case '-':  r=x1-x2; push(r); break;
    case '*':  r=x1*x2; push(r); break;
    case '/':  r=x1/x2; push(r); break;
  }
    }
}return pop();
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

  void reverse(){
    int start=0, end=Top;
    while(start<end){
        int temp=A[start];
        A[start]=A[end];
        A[end]=temp;
        start++;end--;
    }
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
const char *infix="3*5+6/2-4";
 stack st(strlen(infix)+1);
 char* InfixToPostfix = st.convert(infix);
   cout<<"Infix to postfix converted: "<<InfixToPostfix<<endl;
int result=st.evaluate(InfixToPostfix);
cout<<"Result of postfix evaluation: "<<result<<endl;


    return 0;
}