# include <iostream>
# include <queue>
using namespace std;

class Node{
    public:
    int data ;
    Node *left,*right ;
    Node(int ele){
        data = ele ;
        left = right = NULL ;
    }
};

Node* root = NULL ;

Node* buildTree(Node* temp,int key){
    if(!temp)
        return new Node(key) ;
    else if(temp->data > key)
        temp->left = buildTree(temp->left,key) ;
    else if(temp->data < key)
        temp->right = buildTree(temp->right,key) ;
    return temp ;
}

void inorder(Node* temp){
    if(temp){
        inorder(temp->left) ;
        cout << temp->data << "  " ;
        inorder(temp->right) ;
    }
}

void levelOrderTraversal(Node* temp){
    Node* curr = temp ;
    queue<Node*> q ;
    while(temp){
        cout << temp->data << "  " ;
        if(temp->left)  q.push(temp->left) ;
        if(temp->right) q.push(temp->right) ;
        if(!q.empty()){
            curr = q.front() ;
            q.pop() ;
        }
        else    
            curr = NULL ;
    }
}

Node* deleteBST(Node* temp,int key){
    if(!temp)   
        return NULL ;
    else if(temp->data < key)
        temp->right = deleteBST(temp->right,key) ;
    else if(temp->data > key)
        temp->left = deleteBST(temp->left,key) ;
    else{
        Node* succ ;
        if(!temp->left){
            succ = temp->right ;
            delete temp ;
            return succ ;
        }
        else if(!temp->right){
            succ = temp->left ;
            delete temp ;
            return succ ;
        }
        else{
            Node* succParent = temp ;
            succ = temp->right ;
            while(succ->left){
                succParent =  succ ;
                succ = succ->left ;
            }
            if(succParent!=temp)
                succParent->left = succ->right ;
            else    
                succParent->right = succ->right ;
            temp->data = succ->data ;
            delete succ ;
            return temp ;
        }
    }
    
}

int HeightOfTree(Node* temp){
    if(!temp)   
        return 0 ;
    int Ltree = HeightOfTree(temp->left) ;
    int Rtree = HeightOfTree(temp->right) ;
    return (Ltree>Rtree)? Ltree+1 : Rtree+1 ;
}

