# include <iostream>
# include <queue>
using namespace std ;

class Node{
    public:
    int data ;
    Node *left,*right ;
    Node(int h=0){
        data = h ;
        left = right = NULL ;
    }
};

class Tree{
    Node *root ;
    Node* insert(Node* node,int val){
        if(!node)
            return new Node(val) ;
        else if(node->data < val)
            node->right = insert(node->right,val) ;
        else if(node->data > val)
            node->left = insert(node->left,val) ;
        return node ;
    }
    public:
    Tree(){     root = NULL ;      }
    Node* buildTree(){
        int ele ;
        cout << "Enter Number : " ; cin >> ele ;
        Node* temp = new Node(ele) ;
        if(ele==-1) return NULL ;
        cout << "Left to " << ele << "  " ;
        temp->left = buildTree() ;
        cout << "Right to " << ele << "  " ;
        temp->right = buildTree() ;
        return temp ;
    }
    void insert(int val){
        root = insert(root,val) ;
    }
    void levelOrderTraversal(){
        queue<Node*>  q ;
        q.push(root) ;
        q.push(NULL) ;
        
        while(!q.empty()){
            Node* temp = q.front() ;
            q.pop() ;

            if(!temp){
                cout << endl ;
                if(!q.empty())
                    q.push(NULL) ;
            }
            else{
            cout << temp->data << "  " ;
            if(temp->left)  q.push(temp->left) ;
            if(temp->right) q.push(temp->right) ;
            }
        }
    }
};

int main(){
    Tree tea ;
    tea.insert(8) ;
    tea.insert(3) ;
    tea.insert(10) ;
    tea.insert(1) ;
    tea.insert(6) ;
    tea.insert(12) ;
    tea.levelOrderTraversal() ;
    return 0 ;
}