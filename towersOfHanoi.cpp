# include <iostream>
# include <stack>
using namespace std ;

stack<int> pole[3] ;
char rod[] = {'S','A','D'} ;
int src=0,aux=1,dst=2 ;

void moveDisk(int a,int b){
    if(pole[b].empty() || (!pole[a].empty() && pole[a].top() < pole[b].top())){
        cout << "Move Disk "<< pole[a].top() << "from " << rod[a] <<" to" << rod[b] << endl ;  
        pole[b].push(pole[a].top()) ;
        pole[a].pop() ;
    }
    else    
        moveDisk(b,a) ;
}

void towersOfHanoi(int N){
    for(int i=N;i>=1;i--)
        pole[src].push(i) ;
    if(N%2==0) 
        swap(dst,aux) ;
    int totalMoves = ( 1 << N ) - 1 ;
    for(int i=1;i<=totalMoves;i++){
        if(i%3==0)
            moveDisk(aux,dst) ;
        else if(i%3==1)
            moveDisk(src,dst) ;
        else    
            moveDisk(src,aux) ;
    }
}

int main(){
    towersOfHanoi(2) ;
}