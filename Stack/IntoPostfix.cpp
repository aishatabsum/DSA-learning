#include <iostream>
#include <cstring>
using namespace std;


class Stack{
    public:
  int size;
  int Top; 
  char* s;

public:
  Stack(){
    size=0;Top=-1;
    s=nullptr;
  }

  Stack(int sz){
    size=sz;
    Top=-1;
    s= new char[size];
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

void push(char x){
if(isFull()){
cout<<"Stack overflow!\n";
}else
s[++Top]=x;
}

char stackTop(){
    if(!isEmpty())
return s[Top];
else return -1;
}

~Stack() {
      delete s; 
    }

char pop(){
if(isEmpty()){
cout<<"Stack underflow!\n";
return -1;
}else
return s[Top--];
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
 const char *infix="a+b*c-d/e";
 Stack st(strlen(infix)+1);
 char* InfixToPostfix = st.convert(infix);
   cout<<"Infix to postfix converted: "<<InfixToPostfix<<endl;
    return 0;
}