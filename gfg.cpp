# include <iostream>
# include <queue>
using namespace std ;

class Node{
    public:
    int data ;
    Node *left,*right ;
    public:
    Node(int le){
        data = le ;
        left = right = NULL ;
    }
};

Node* root = NULL ;

Node* BinaryTree(Node* tree,int val){
    if(!tree)
        return new Node(val) ;
    else if(tree->data < val)
        tree->right = BinaryTree(tree->right,val) ;
    else if(tree->data > val)
        tree->left = BinaryTree(tree->left,val) ;
    return tree ;
}

Node* deleter(Node* tree,int key){
    if(!tree)
        return NULL ;
    else if(tree->data < key )
        tree->right = deleter(tree->right,key) ;
    else if(tree->data > key)
        tree->left = deleter(tree->left,key) ;
    else{
        Node* suc ;
        if(!tree->left){
            suc = tree->right ;
            delete tree ;
            return suc ; 
        }
        else if(!tree->right){
            suc = tree->left ;
            delete tree ;
            return suc ;
        }
        else{
            Node* sucparent = tree ;
            suc = tree->right ;
            while(suc->left){
                sucparent = suc ;
                suc = suc->left ;
            }
            if(sucparent!=tree)
                sucparent->left = suc->right ;
            else    
                sucparent->right = suc->right ;

            tree->data = suc->data ;
            delete suc ;
            return tree ;
        }
    }
}

bool search(Node* tree,int ket){
    if(!tree)
        return false ;
    else if(tree->data < ket)
        search(tree->right,ket) ;
    else if(tree->data > ket)
        search(tree->left,ket) ;
    else
        return true ;
}

int height(Node* tree){
    if(!tree)   return 0 ;
    int Ltree = height(tree->left) ;
    int Rtree = height(tree->right) ;
    return (Ltree>Rtree)? Ltree+1 : Rtree+1 ;
}

void levelOrderTraversal(Node* tree){
    Node* curr = tree ;
    queue<Node*> q ;
    while(curr){
        cout << curr->data << "  " ;
        if(curr->left)  q.push(curr->left)  ;
        if(curr->right) q.push(curr->right) ;
        if(!q.empty()){
            curr = q.front() ;
            q.pop() ;
        }
        else    
            curr = NULL ;
    }
}


