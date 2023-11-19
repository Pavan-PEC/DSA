# include <iostream>
using namespace std ;

class Node{
    public:
    char data ;
    Node* next ;
    Node(char ele='\0',Node* ptr=NULL){
        data = ele ;
        next = ptr ;
    }
};

class LinkedList{
    Node* Head ;
    public:
    LinkedList(string str){
        Head = NULL ;
        int i = 0 ;
        Node *tail=Head ;
        while(str[i]!='\0'){
            Node *to_add = new Node(str[i]) ;
            (Head==NULL)?Head = tail = to_add : tail = tail->next = to_add ;
            i++ ;
        }
    }
    int position(char tar){
        Node *temp = Head ;
        int cnt=1;
        while(temp && temp->data!=tar){
            temp = temp->next ;
            cnt++ ;
        }
        return (temp)?cnt:-1 ;
    }
    void deleteNode(char tar){
        Node *temp = Head,*prev;
        while(temp->next && temp->data!=tar){
            prev = temp ;
            temp = temp->next ;
        }
        if(temp==Head)
            Head = Head->next ;
        else if(temp->data==tar)
            prev->next = temp->next ;
        else    
            cout <<tar << " Does not exists in the List" << endl ;
    }

    void display(){
        Node *temp = Head ;
        while(temp){
            cout << temp->data  ;
            temp = temp->next ;
        }
        cout << endl ;
    }
};

int main(){
    LinkedList W1("IMPOSSIBLE") ;
    cout << W1.position('O') << endl << W1.position('o') << endl ;
    W1.deleteNode('p') ;
    W1.deleteNode('M') ;
    W1.display() ;
    return 0 ;
}