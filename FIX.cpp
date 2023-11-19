# include <iostream>
# include <ctype.h>
# include <stack>
using namespace std ;

int priority(char s){
    if(s == '^')    
        return 3 ;
    else if(s=='*' || s=='/')
        return 2 ;
    else if(s=='+' || s=='-')
        return 1 ;
    else 
        return 0 ;
}

string infixToPostfix(string infix){
    string postfix="" ;
    stack<int> graphic ;
    char save;
    int i=0;
    while(infix[i]!='\0'){
        if(infix[i]=='(')
            graphic.push(infix[i]) ;
        else if(infix[i]==')'){
            //postfix+=graphic.top() ;
            while(graphic.top()!='('){
                postfix+=graphic.top() ;
                graphic.pop() ;
            }
            graphic.pop() ;
        }
        else if(infix[i]>='a' && infix[i]<='z'|| infix[i]>='A'&& infix[i]<='Z')
            postfix+=infix[i] ;
        else{
            while(!graphic.empty() && priority(infix[i] <= priority(graphic.top()))){
                postfix+=graphic.top() ;
                graphic.pop() ;
            }
            graphic.push(infix[i]) ;
        }
        i++ ;
    }
    if(!graphic.empty()){
        postfix+=graphic.top() ;
        graphic.pop() ;
    }
    return postfix ;
}

int main(){
    string infix = "((a+(b*c))-d)"; 
    string postfix;
    postfix = infixToPostfix(infix);
    cout << postfix ;
    return 0 ;
}