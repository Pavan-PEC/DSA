# include <iostream>
using namespace std ;

class Node{
    public:
    int data ;
    Node* next ;
    Node(int ele=-1){
        data = ele;
        next = NULL ;
    }
};

class PositionList{
    Node *Head;
    public:
    Node* getHead(){return Head ;}
    PositionList(){ Head=NULL; }
    bool search(Node* &pre,Node* &cur,int tar){
        pre = NULL ;
        cur = Head ;
        while(cur && cur->data < tar){
            pre = cur ;
            cur = cur->next ;
        }
        if(!cur)
            return false ;
        else if(cur->data==tar)
            return true ;
        else    
            return false ;
    }
    bool AddPosition(int tar){
        Node *pre,*cur,*to_add = new Node(tar) ;
        if(search(pre,cur,tar))
            return false ;
        if(!pre){
            to_add->next = Head ;
            Head = to_add ;
            return true ;
        }
        to_add->next = pre->next ;
        pre->next = to_add ;
        return true ;
    }
    void display(){
        Node* temp = Head ;
        while(temp){
            cout << " -->" << temp->data ;
            temp = temp->next ;
        }
        cout << endl ;
    }
};

class Word{
    public:
    string data ;
    Word* next ;
    Word(string Data=""){
        data = Data ;
        next = NULL ;
    }
};

class WordList{
    Word* Head ;
    public:
    WordList(){ Head = NULL ; }
    Word* getHead(){return Head ;}
    bool InsertAt(string word,int position){
        Word *to_add = new Word(word), *temp = Head ;
        if(position==1){
            to_add->next = Head ;
            Head = to_add ;
            return true ;
        }
        for(int i=1;i<position-1;i++){
            if(!temp){
                cout << "Location Exceeds the List \n" ;
                return false ;
            }
            temp = temp->next ;
        }
        to_add->next = temp->next ;
        temp->next = to_add ;
        return true ;
    }
    bool deleter(int pos){
        Word *temp = Head ;
        if(pos==1){
            Head = Head->next ;
            return true ;
        }
        for(int i=1;i<pos-1;i++){
            if(!temp){
                cout << "Location Exceeds the List \n" ;
                return false ;
            }
            temp = temp->next ;
        }
        temp->next = temp->next->next ;
        return true ;
    }
    int DeleteFrom(PositionList positions){
        Node* temp = positions.getHead() ;
        int cnt=0;
        while(temp){
            deleter(temp->data-cnt) ;
            temp = temp->next ;
            cnt++ ;
        }
        return cnt ;
    }
    bool InsertListBefore(string word,WordList myList){
        Word *temp = Head,*Nhead=myList.getHead(),*Ntail=Nhead,*prev;
        while(temp && temp->data!=word){
            prev = temp ;
            temp = temp->next ;
        }
        while(Ntail->next)
            Ntail = Ntail->next ;
        prev->next = Nhead ;
        Ntail->next = temp ;
        return true ;
    }
    void Display(){
        Word* temp = Head ;
        while(temp){
            cout << temp->data << "  " ;
            temp = temp->next ;
        }
        cout << endl ;
    }
};

int main(){
    PositionList P;
WordList L1, L2; //Expected Output
cout<<"\n"<<L1.InsertAt("FAILED", 1); //true
cout<<"\n"<<L1.InsertAt("DSLAB", 2); //true
cout<<"\n"<<L1.InsertAt("IN", 2); //true
cout<<"\n"<<L1.InsertAt("I", 1); //true
cout<<"\n"<<L1.InsertAt("WILL",2); //true
cout<<endl<<L1.InsertAt("BE",3); //true
cout<<endl<<P.AddPosition(4); //true
cout<<endl<<P.AddPosition(3); //true
cout<<endl<<L2.InsertAt("GRADE", 1); //true
cout<<endl<<L2.InsertAt("GET", 1); //true
cout<<endl<<L2.InsertAt("S", 2); //true
L1.Display(); //I WILL BE FAILED IN DS LAB
L2.Display(); //GET S GRADE
P.display(); //3 4
cout<<endl<<L1.DeleteFrom(P); //2
L1.Display();
cout<<endl<<L1.InsertListBefore("IN", L2); //true
L1.Display(); // I WILL GET S GRADE IN DS LAB
    return 0 ;
}