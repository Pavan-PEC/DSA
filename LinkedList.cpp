# include <iostream>
# include <stack>
using namespace std ;

class Node{
    public:
    int data ;
    Node* next ;
    Node(int ele){
        this -> data = ele  ;
        this -> next = NULL ;
    }
};

class LinkedList{
    int count ;
    Node* Head ;
    public:
    LinkedList(int element){  
        Head = new Node(element) ;  
        count = 1 ;
    }
    Node* getHead(){    return Head ;   }
    void insertatloc(int ele, int loc){
        Node* to_add = new Node(ele), *temp = Head ; int cnt=1;  count++ ;

        if(loc==0){
            to_add -> next = Head ;
            Head = to_add ;
            return ;
        }

        while(cnt < loc){
            cnt++ ;
            temp = temp -> next ;
        } 
        to_add -> next = temp -> next ;
        temp -> next   = to_add       ;
    }
    void display(){
        Node* temp = Head ;
        while(temp!=NULL){
            cout << temp -> data << "  " ;
            temp = temp -> next ;
        }
        cout << endl ;
    }
    void fun(){
        count-- ;
        Node* temp = Head, *pre ;
        while(temp -> next -> data >= 0 ){
            pre  = temp ;
            temp = temp -> next ;
        }
        pre -> next = temp -> next ;
    }
    bool RevAdd(int x,LinkedList Ex){
        Node *temp=Head, *prev, *Nhead=Ex.getHead();
        while(temp!=NULL && temp->data != x){
            prev = temp ;
            temp = temp->next ;
        }
        if(temp==NULL && prev->data!=x)
            return false ;
        
        stack<int> store ;
        while(Nhead!=NULL){
            store.push(Nhead->data) ;
            Nhead = Nhead->next ;
        }
        while(!store.empty()){
            Node *to_add = new Node(store.top()) ;
            store.pop() ;
        }
        if(prev==NULL){

        }
    }

};

int main(){
    LinkedList PIN(6) ;
    PIN.insertatloc(3,1) ;
    PIN.insertatloc(10,2) ;
    PIN.insertatloc(9,0) ;
    PIN.insertatloc(12,4) ;
    PIN.insertatloc(99,5) ;
    PIN.insertatloc(-2,4) ;
    LinkedList L(1) ;
    for(int i=1;i<7;i++)
        L.insertatloc(i+1,i) ;
    L.display() ;
    PIN.RevAdd(3,L) ;
    PIN.display() ;
    return 0 ;
}