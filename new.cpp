# include <iostream>
using namespace std;

class Edge;
class Vertex{
    public:
    char data ;
    bool instack, processed ;
    Vertex *nextVertex ;
    Edge *firstEdge ;
    Vertex(char x){
        data = x ;
        instack = processed = false ;
        nextVertex = NULL ;
        firstEdge = NULL ;
    }
};
class Edge{
    public:
    Vertex *content ;
    Edge *nextEdge ;
    Edge(){
        content = NULL ;
        nextEdge = NULL ;
    }
};
class Node{
    public:
    Node *next;
    Vertex *data ;
    Node(Vertex *v){
        data = v ;
        next =NULL ;
    }
};
class Stack{
    Node *top ;
    public:
    int count ;
    Stack(): count(0){top=NULL;}
    void push(Vertex *v){
        Node *to_add = new Node(v) ;
        if(!top)    top = to_add ;
        else{
            to_add->next = top ;
            top = to_add ;
        }
        count++ ;
    }
    Vertex* pop(){
        if(!top)    return NULL ;
        else{
            Node *temp = top ;
            top = top->next ;
            Vertex *v = temp->data ;
            delete temp ;
            count--;
            return v ;
        }
        
    }
    Node* topStack(){return (top)?top:NULL;}
};
class Graph{
    int count ;
    Vertex *First ;
    public:
    Graph():count(0){First=NULL;}
    void insertVertex(char ele){
        Vertex *to_add = new Vertex(ele), *temp=First ;
        if(!First)  First = to_add ;
        else{
            while(temp->nextVertex) 
                temp = temp->nextVertex ;
            temp->nextVertex = to_add ;
        }
        count++;
    }
    bool insertEdge(char x, char y){
        Vertex *xtemp=First, *ytemp=First ;
        while(xtemp && xtemp->data!=x)
            xtemp = xtemp->nextVertex ;
        while(ytemp && ytemp->data!=y)
            ytemp = ytemp->nextVertex ;
        if(!xtemp || !ytemp)    return false ;
        Edge *XtoY = new Edge(), *YtoX = new Edge(), *temp;
        XtoY->content = ytemp ;
        temp = xtemp->firstEdge ;
        if(!temp)   xtemp->firstEdge = XtoY ;
        else{
            while(temp->nextEdge)
                temp = temp->nextEdge ;
            temp->nextEdge = XtoY ;
        }
        YtoX->content = xtemp ;
        temp = ytemp->firstEdge ;
        if(!temp)   ytemp->firstEdge = YtoX ;
        else{
            while(temp->nextEdge)  
                temp = temp->nextEdge ;
            temp->nextEdge = YtoX ;
        }
        return true ;
    }
    void DFS(){
        cout << "DFS of the Graph : " ;
        if(!First){
            cout << "Empty Graph\n" ;
            return ;
        }
        Stack s ;
        Vertex *temp = First ;
        s.push(temp) ;
        temp->instack = temp->processed = true ;
        int visitedVertex = 1 ;
        cout << temp->data << "\t" ;
        while(count!=visitedVertex){
            Edge *adjaceny = s.topStack()->data->firstEdge ;
            while(adjaceny && adjaceny->content->processed==true)
                adjaceny = adjaceny->nextEdge ;
            if(adjaceny){
                s.push(adjaceny->content) ;
                adjaceny->content->instack = adjaceny->content->processed = true ;
                visitedVertex++ ;
                cout << adjaceny->content->data << "\t" ;
            }
            else{
                Vertex *v = s.pop() ;
                v->instack = false ;
                if(s.topStack()==NULL){
                    v = First->nextVertex ;
                    while(v && v->processed==true)
                        v = v->nextVertex ;
                    if(v){
                        s.push(v) ;
                        v->instack = v->processed = true ;
                        visitedVertex++ ;
                        cout << v->data << "\t" ;
                    }
                }
                
            }
        }
        cout << endl ;
    }
};

int main(){
    Graph g ;
    int option=0;
    char a,b,c,y ;
    bool checking ;
    while(1){
        cout << "Enter option : \n1) InsertVertex\n2) InsertEdge3) DFS\n0) ABORT" ;
        cin >> option ;
        switch(option){
            case 1:
                cout << "\n--INSERTION OF VERTEX--\nEnter data : " ;
                cin >> a ;
                g.insertVertex(a) ;
                break;
            case 2:
                cout << "\n--INSERTING AN EDGE--\nEnter the two vertices : " ;
                cin >> b >> c ;
                checking = g.insertEdge(b,c) ;
                if(!checking)  cout << "Egde Failed\n" ;
                break ;
            case 3: 
                g.DFS() ;
                break ;
            case 0:
                goto label ;
        }

    }
    label:
    return 0 ;
}