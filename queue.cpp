# include <iostream>
using namespace std ;

class Node{
    public:
        int data   ;
        Node* next ;
        Node(int ele=0){
            this -> data = ele  ;
            this -> next = NULL ;
        }
};

class LinkedList{
    int count ;
    Node* Head ;
    public:
    LinkedList()  {    this -> Head = NULL ; count = 0 ;   }
    Node* getHead(){return Head ;}
    void insertNextToLoc(int loc,int dataIn){
        Node *to_add = new Node(dataIn), *temp=Head ;  count++ ;
        if(loc == 0){
            to_add -> next = Head ;
            Head = to_add ;
            return ;
        }
        for(int i=1;i<loc;i++)
            temp = temp -> next ;
        if(temp->next==NULL){
            temp -> next = to_add ;
            to_add -> next = NULL ;
            return ;
        }
        to_add -> next = temp -> next ;
        temp -> next = to_add ;
    }

    void display(){
        Node* temp = Head ;
        while(temp!=NULL){
            cout << " -> " << temp -> data ;
            temp = temp -> next ;
        }
        cout << endl << "Count :" << count << endl;
    }

    void deletionNextToLoc(int loc){
        count-- ;
        Node* temp = Head ;
        if(loc==0){
            Head = Head -> next ;
            return ;
        }
        for(int i=1;i<loc;i++)
            temp = temp -> next ;
        temp -> next = temp -> next -> next ;
    }

    void midPrint(){
        Node* temp = Head ;
        for(int i=1;i<=count/2;i++)
            temp = temp -> next ;
        cout << temp -> data ;
    }

    void reverse(){
        Node *pre=NULL, *&curr=Head, *forward=curr->next ;
        while(curr!=NULL){
            curr -> next = pre ;
            pre = curr ;
            curr = forward ;
            if(forward!=NULL)
            forward = forward -> next ;
        }
        curr = pre ;
    }

    void rotate(int k){
        Node* temp = Head;
        for(int i=1;i<k;i++)
            temp = temp -> next ;
        Node* back_list = temp -> next , *tail=back_list;
        temp -> next = NULL ;
        while(tail->next!=NULL)
            tail = tail -> next ;
        tail -> next = Head ;
        Head = back_list;
    }

    void deleteFromLast(int N){
        int cnt =1 ;
        Node* temp = Head ;
        while(temp!=NULL){
            temp = temp -> next ;
            cnt++ ;
        }
        Node* temp1 = Head ;
        for(int i=1;i<(cnt-N-1);i++)
            temp = temp -> next ;
        temp -> next = temp -> next -> next ;
    }

    void revDisplay(Node* temp){
        if(temp->next!=NULL)
            revDisplay(temp->next) ;
        cout << temp->data << "  " ;
    }
};

int main(){
    LinkedList list ;
    list.insertNextToLoc(0,1);
    list.insertNextToLoc(1,2);
    list.insertNextToLoc(2,3);
    list.insertNextToLoc(3,4);

    list.display();
    list.revDisplay(list.getHead()) ;
    return 0 ;
}