# include <iostream>
using namespace std ;
class Node{
    public:
    int data ;
    Node *front,*back ;
    Node(int ele){
        data = ele ;
        front = back = NULL ;
    }
};
class Head{
    public:
    int count ;
    Node *head,*rear ;
    Head(){
        count = 0 ;
        head = rear = NULL ;
    }
};
class CDLL{
    Head* First ;
    public:
    CDLL(){First=new Head();}
    bool search(Node* &pre,Node* &cur,int key){
        pre = First->rear ;
        cur = First->head ;
        if(!cur) return false ;
        do{
            if(cur->data<key){
                pre = cur ;
                cur = cur->front ;
            }
            else break ;
        }while(cur!=First->head) ;
        return (cur->data==key)? true : false ;
    }
    bool insert(int key){
        Node *pre,*cur,*to_add = new Node(key);
        if(search(pre,cur,key)) return false ;
        First->count++ ;
        if(!First->head){
            to_add->back = to_add->front = to_add ;
            First->head = First->rear = to_add ;
            return true ;
        }
        to_add->front = pre->front ;
        to_add->back = pre ;
        //pre->front->back = to_add ;
        //pre->front = to_add ;
        pre->front = pre->front->back = to_add ;
        if(pre==First->rear)
            (pre->data<key)? First->rear = to_add : First->head = to_add ;
        return true ;
    }

    void display(){
        Node *temp = First->head ;
        cout << "List(Front) : \n" ;
        if(!temp)    return ;
        do{
            cout << temp->data << " " ;
            temp = temp->front ;
        }while(temp!=First->head) ;
        cout << endl << "List(Back)  : \n" ;
        temp = First->rear ;
        do{
            cout << temp->data << "  " ;
            temp = temp->back ;
        }while(temp!=First->rear) ;
        cout << endl ;
    }
};

int main(){
    CDLL c ;
    c.insert(23) ;
    c.insert(13) ;
    c.insert(43) ;    
    c.insert(53) ;
    c.insert(3) ;
    c.display();
    return 0 ;
}