# include <iostream>
using namespace std ;
class Edge;
class Vertex{
    public:
    char data ;
    Vertex *nextVertex ;
    Edge *firstEdge ;
    bool instack, processed ;
    Vertex(char d){
        data = d ;
        nextVertex = NULL ;
        firstEdge = NULL ;
        instack = processed = false ;
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
    Node *next ;
    Vertex *data ;
    Node(Vertex *v){
        data = v ;
        next = NULL ;
    }
};
class Stack{
    int count ;
    Node *top ;
    public:
    Stack():count(0){top=NULL;}
    void push(Vertex *v){
        Node *to_add = new Node(v) ;
        if(!top) top = to_add ;
        else{
            to_add->next = top ;
            top = to_add ;
        }
        count++ ;
    }
    Vertex* pop(){
        if(!top)    return NULL ;
        else{
            count-- ;
            Vertex *ans = top->data ;
            Node *temp = top ;
            top = top->next ;
            delete temp ;
            return ans ;
        }
    }
    Node* topStack(){
        return top ;
    }
};
class Queue{
    Node *front,*rear ;
    public:
    int count ;
    Queue():count(0){front=rear=NULL;}
    void enqueue(Vertex *x){
        Node *to_add = new Node(x), *temp=front ;
        if(!front)  front = rear = to_add ;
        else{
            rear->next = to_add ;
            rear = to_add ;
        }
        count++;
    }
    Vertex* dequeue(){
        Node *temp = front ;
        if(!front) return NULL ;
        front = front->next ;
        Vertex *ans = temp->data ;
        delete temp ;
        count-- ;
        return ans ;
    }
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
            temp->nextVertex  = to_add ;
        }
        count++ ;
    }
    bool insertEdge(char x, char y){
        Vertex *xtemp=First, *ytemp=First ;
        while(xtemp && xtemp->data!=x)
            xtemp = xtemp->nextVertex ;
        while(ytemp && ytemp->data!=y)
            ytemp = ytemp->nextVertex ;
        if(!xtemp || !ytemp)    return false ;
        Edge *XtoY = new Edge(), *YtoX = new Edge(), *temp ;
        XtoY->content = ytemp ;
        temp = xtemp->firstEdge ;
        if(!temp)   xtemp->firstEdge = XtoY ;
        else{
            while(temp->nextEdge)   temp = temp->nextEdge ;
            temp->nextEdge = XtoY ;
        }
        YtoX->content = xtemp ;
        temp = ytemp->firstEdge ;
        if(!temp)   ytemp->firstEdge = YtoX ;
        else{
            while(temp->nextEdge)   temp = temp->nextEdge ;
            temp->nextEdge = YtoX ;
        }
        return true ;
    }
    void DFS(){
        cout << "DFS of Graph : " ;
        if(!First){
            cout << "Empty Graph \n" ;
            return ;
        }
        Vertex *vertex = First ;
        Stack s ;
        s.push(vertex) ;
        vertex->instack = vertex->processed = true ;
        int visitedVertex = 1 ;
        cout << vertex->data << "\t" ;
        while(count!=visitedVertex){
            Edge *adj = s.topStack()->data->firstEdge ;
            while(adj && adj->content->processed==true)
                adj = adj->nextEdge ;
            if(adj){
                s.push(adj->content) ;
                adj->content->instack = adj->content->processed = true ;
                cout << adj->content->data << "\t" ;
                visitedVertex++ ;
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
                        cout << v->data << "\t" ;
                        visitedVertex++ ;
                    }
                }
            }
        }
        cout << endl ;
    }
    void BFS(){
        Queue q ;
        Vertex *v = First ;
        q.enqueue(v) ;
        cout << "Breadth-First Traversal : " ;
        while(q.count!=0){
            v = q.dequeue() ;
            v->instack = v->processed = true ;
            cout << v->data << "\t" ;
            Edge *adj = v->firstEdge ;
            while(adj){
                if(adj->content->processed!=true && adj->content->instack!=true){
                    q.enqueue(adj->content) ;
                    adj->content->instack = true ;
                }
                adj = adj->nextEdge ;
            }
        }
        cout << endl ;
    }
    void MST(){
        if(First==NULL) return ;
        Vertex* temp = First ;
        temp->instack = true ;
        bool totalCount=false ;
        int sum=0, min ;
        while(!tc){
            totalCount = true ;
            temp = First ;
            min = 9999 ;
            Edge* minEdge = NULL ;
            Vertex* src = NULL ;

            while(temp){
                if(temp->instack==true && temp->firstEdge!=NULL){
                    Edge* a = temp->firstEdge ;
                    while(a){
                        if(a->content->instack!=true){
                            totalCount = false ;
                            if(a->wt < min){
                                min = a->wt ;
                                minEdge = a ;
                                src = t ;
                            }
                        }
                        a = a->nextEdge ;
                    }
                }
                temp = temp->nextVertex ;
            }
            if(minEdge!=NULL){
                minEdge->content->instack = true ;
                sum+=min ;
                cout << src->data << "-> "<<minEdge->adj->data << "  " << min << endl ;
            }
        }
    }
};

int main(){
    int option ;
    char a,b,c,y ;
    Graph g ;
    while(1){
        cout << "Enter options : \n1. InsertVertex\n2. InsertEdge\n3. DFS\n4.DFS 5.MST0. ABORT\n" ;
        cin >> option ;
        switch(option){
            case 1:
                label:
                cout << "Enter Vertex : " ; cin >> a ;
                g.insertVertex(a) ;
                cout << "Do You wanna Enter another vertex(y/n)? : " ; cin >> y ;
                if(y=='y') goto label ;
                break ;
            case 2:
                label1:
                cout << "Enter two vertices (EDGE) :  " ; cin >> b >> c ;
                g.insertEdge(b,c) ;
                cout << "Do You wanna Enter another Edge(y/n)? : " ; cin >> y ;
                if(y=='y') goto label1 ;
                break ;
            case 3:
                g.DFS() ;
                break ;
            case 4:
                g.BFS() ;
                break ;
            case 5:
                g.MST() ;
                break ;
            case 0:
                goto exit1 ;
        }
    }
    exit1:
    return 0 ;
}