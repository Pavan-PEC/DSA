# include <iostream>
using namespace std ;
// implementing Circulat Doubly Linked List

class Node{
	public:
	int data ;
	Node *forw,*prev ;
	Node(int ele){
		data = ele ;
		forw = prev = NULL ;
	}
};
class Head{
	public:
	int count ;
	Node *front, *rear ;
	Head(){
		count = 0 ;
		front = rear = NULL ;
	}
};

class CDLL{
	Head* First ;
	public:
	CDLL(){
		First = new Head() ;
	}	
	bool search(Node* &pre,Node* &ploc,int key){
		ploc = First->front ;
		pre = First->rear;
		if(!ploc) return false ;
		do{
			if(ploc->data < key){
				pre = ploc ;
				ploc = ploc->forw ;
			}
			else break ;
		}while(ploc!=First->front);
		return (ploc->data==key)?true:false;
	}
	bool insert(int key){
		cout << "\n----Done----\n";
		Node *to_add = new Node(key),*pre,*curr ;
		if(!First->front){
			First->front = First->rear = to_add ;
			to_add->forw = to_add->prev = to_add ;
			First->count++;
			return true ;
		}
		if(search(pre,curr,key)) return false ;
		to_add->forw = pre->forw ;
		to_add->prev = pre ;
		pre->forw->prev = to_add ;
		pre->forw = to_add ;
		if(First->rear==pre)
			(pre->data<key)?First->rear = to_add : First->front = to_add ;
		First->count++;
		
		return true ;
	}
	void displayFront(){
		if(!First->front){
			cout << "Empty List" ; return ;
		}
		Node* temp =First->front ;
		do{
			cout << temp->data << "  " ;
			temp = temp->forw ;
		}while(temp!=First->front);
		cout << endl ;
	}
	
	void displayBack(){
		if(!First->front){
			cout << "Empty List" ; return ;
		}
		Node* temp =First->rear ;
		do{
			cout << temp->data << "  " ;
			temp = temp->prev;
		}while(temp!=First->rear);
		cout << endl ;
	} 
	bool full(){
	Node* add = new Node(-1) ;
	return (!add)? true : false ;
	}
	bool empty(){
		return (First->front==NULL)? true : false ;
	}
	int count(){	return First->count ;	}	
};


int main(){
Node *pre,*cur;
	CDLL list ;
	int choice,x ;
	while(1){
		cout << "1.insert\t2.search\t3.full\t4.empty\t5.list count\t6.Displayback\t7.displayFront\t0.ABORT\n" ;
		cin >> choice ;
		switch(choice){
			case 1 :
			cout << "Enter elemnet to be inserted : " ; cin >> x ; list.insert(x) ;
			break ;
			case 2 :
			cout << "Enter elemnet to be search : " ; cin >> x ; 	cout << list.search(pre,cur,x) ;
			break ;		
			case 3 :
			cout << (list.full())?"List is FULL\n":"List is NOT FULL\n";
			break ;		
			case 4 :
			cout << (list.empty())?"List is EMPTY\n":"List is NOT EMPTY\n";
			break ;
			case 5 :
			cout << "No. of nodes in List : " <<list.count() << endl;
			break ;
			case 6 :
			cout << "List Displayed from rear :  " ; 
			list.displayBack();
			break ;
			case 7 :
			cout << "List Displayed from front :  " ;
			list.displayFront() ;
			break ;
			default:
			goto label;
			break ;
			
		}
	}
	label:
	return 0 ;
}
