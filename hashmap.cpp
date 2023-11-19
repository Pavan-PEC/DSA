# include <iostream>
using namespace std ;

class Node{
    public:
    int data ;
    Node* next ;
    Node(int ele){
        data = ele ;
        next = NULL ;
    }
};
class Head{
    public:
    int count ;
    Node* first; 
    Head(){
        count = 0 ;
        first = NULL ;
    }
};
class HashMap{
    Head **hashTable;
    int size;
    int hash(int key){
        return key%size;
    }
    public:
    HashMap(int Size){
        hashTable = new Head*[size=Size] ;
        for(int i=0;i<size;i++)
            hashTable[i] = new Head() ;
    }
    bool insert(int key){
        int index = hash(key) ;
        Node* to_add = new Node(key) ;
        to_add->next = hashTable[index]->first ;
        hashTable[index]->first = to_add ; 
        hashTable[index]->count++;
        return true ;
    }
    void display(){
        int i=0;
        Node* temp;
        while(i<size){
            temp = hashTable[i]->first ;
            while(temp){
                cout << temp->data << "  " ;
                temp = temp->next ;
            }
            cout << endl ;
            i++;
        }
    }
    bool search(int key){
        int i=0 ;
        Node *temp = hashTable[hash(key)]->first;
        while(temp && temp->data!=key)
            temp = temp->next ;
        return (temp)?true:false;
    }
    bool deleter(int key){
        Node *pre=hashTable[hash(key)]->first,*cur=pre->next ;
        while(cur){
            if(cur->data==key) pre->next = cur->next ;
            pre = cur ;
            cur = cur->next ;
        }
        return true ;
    }
};


int main(){
    HashMap l(5);
    for(int i=0;i<22;i++)
        l.insert(i) ;
    cout << l.deleter(12) ;
    l.display() ;
    return 0 ;
}