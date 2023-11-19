# include <iostream>
using namespace std ;

class Node{
    public:
    int data ;
    Node* next ;
    Node(int ele=-1){
        data = ele ;
        next = NULL ;
    }
};

class HeadQ{
    public:
    int count ;
    Node* front ;
    Node* rear ;
    HeadQ(){
        count = 0 ;
        front = rear = NULL ;
    }
};

class Stack{
    Node* Top ;
    public:
    Stack(){
        Top = NULL;
    }
    bool push(int Data){
        Node *to_add = new Node(Data) ;
        to_add->next = Top ;
        Top = to_add ;
        return true ;
    }
    bool pop(){
        if(Top!=NULL){
            Top = Top->next ;
            return true ;
        }
        else
            return false ;
    }
    bool empty(){   return (Top==NULL)?true:false;  }
    int top(){  return (empty())?-1:Top->data;  }
    void destroy(){
        Node *t ;
        while(Top!=NULL){
            t = Top ;
            Top = Top->next ;
            delete t ;
        }
    }
};

class Queue{
    HeadQ* head ;
    public:
    Queue(){    head = new HeadQ();    }
    bool enqueue(int dat){
        Node* to_add = new Node(dat) ;
        if(head->count==0)
            head->front = to_add ;
        else
            head->rear->next = to_add ;
        head->rear = to_add ;
        head->count++ ;
        return true ;
    }
    bool dequeue(){
        if(head->count==0)
            return false ;
        else
            head->front = head->front->next ;
        head->count-- ;
        if(head->count==0)
            head->front = head->rear = NULL ;
        return true ;
    }
    bool empty(){   return (head->count==0)?true:false ;    }
    int Qfront(){
        return (empty())?-1:head->front->data;
    }
    int Qrear(){
        return (empty())?-1:head->rear->data;
    }
    void destroy(){
        Node* temp ;
        while(head->front!=NULL){
            temp = head->front ;
            head->front = head->front->next ;
            delete temp ;
        }
        cout << "Queue Destroyed" << endl ;
        return ;
    }
    int count(){
        return head->count ;
    }

};

int main(){
    
    return 0 ;
}