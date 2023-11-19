# include <iostream> 
using namespace std ;

class Node{
    public:
    int data ;
    Node *back,*front ;
    Node(int ele=-1){
        data = ele ;
        back = front = NULL ;
    }
};

struct First{
    int count ;
    Node *back, *front ;
};

class DoubleLL{
    First* Head ;
    public:
    DoubleLL(){  
        Head = new First ;
        Head -> count = 0 ;
        Head -> back = Head -> front = NULL ;
    }
    bool search(Node* &pre,Node* &cur,int target){
        pre = NULL ;
        cur = Head -> front ;
        while(cur!=NULL  && cur -> data < target){
            pre = cur ;
            cur = cur -> front ;
        }
        if(!cur)
            return false ;
            //cout << "I am in 2" << endl ;
        else if(target==cur->data)
            return true ;
        else 
            return false ;
    }
    bool insert(int ele){
        Node *pre,*cur,*to_add=new Node(ele);
        if(search(pre,cur,ele))
            return false ;
        Head -> count++ ;
        if(!pre){
            to_add->front = Head->front ;
            if(cur)
            cur->back = to_add ;
            Head->front = to_add ;
            return true ;
        }
        to_add->front=pre->front ;
        pre->front = to_add ;
        if(cur)
            cur->back = to_add ;
        else    
            Head -> back = to_add ;
        to_add->back = pre ;
        return true ;
    }
    void display(){
        Node* temp = Head->front ;
        cout << "\nCount : " << Head -> count << "\nFront : " <<endl ;
        while(temp){
            cout << " -->" << temp->data ;
            temp = temp -> front ;
        }
        cout << endl << "Back : " << endl ;
        temp = Head -> back ;
        while(temp){
            cout << " -->" << temp->data ;
            temp = temp -> back ;
        }
        cout << endl ;
    }

};

int main(){
    DoubleLL List ;
    cout << List.insert(2) ;
    cout << List.insert(3);
    cout << List.insert(1);
    cout << List.insert(6);
    cout << List.insert(5);
    List.display() ;
    return 0 ;
}