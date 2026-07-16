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

  bool isBalance(const char *exp){
    for(int i=0; exp[i]!='\0'; i++){
        if(exp[i]=='(') 
         push(exp[i]);
        else if(exp[i]==')'){
            if(isEmpty())  return false;
            else pop();
        }
    }
    return isEmpty()? true:false;
}


 bool multiParenisBalance(const char *exp){
    for(int i=0; exp[i]!='\0'; i++){
        if(exp[i]=='(' || exp[i]=='['||exp[i]=='{') 
         push(exp[i]);
        else if(exp[i]==')'|| exp[i]==']'||exp[i]=='}'){
            if(isEmpty())  return false;
            char x=pop();
            int diff=exp[i]-x;
           if(diff!=1 && diff!=2)
           return false;
        }
    }
    return isEmpty()? true:false;
}

void push(char x){
if(isFull()){
cout<<"Stack overflow!\n";
}else
s[++Top]=x;
}

int stackTop(){
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
  const  char *exp="((a+b)*(c-d))";
   Stack parenS(strlen(exp));
cout<<"parenthesis are balanced ? "<<parenS.isBalance(exp)<<endl;
const char *exp2="{([a+b]*[c-d])/e})";
  Stack multiParenS(strlen(exp2));
  cout<<"multi parenthesis are balanced ? "<<multiParenS.multiParenisBalance(exp2)<<endl;
    return 0;
}