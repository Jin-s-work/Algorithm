#include <iostream>  // stdio.h 와 같은 것
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstdio>
#include <math.h>

using ll = long long;
using namespace std;
int m,l;
int k;
int num = 0;

int n,r,c;


void recur(int x, int y, int size){
    if(x == r && y == c){    // cx가 행 cy가 열
        cout << num << '\n';
        exit(0);
    }
    if(size == 1){
        num++;
        return;
    }
    if(!(x <= r && r<x+size && y <= c && c<y+size)){
        num += size*size;
        return;
    }
        
    
    recur(x,y,size/2);                      // 2사분면
    recur(x,y+size/2,size/2);               // 1사분면
    recur(x+size/2,y,size/2);               // 3사분면
    recur(x+size/2,y+size/2,size/2);        // 4사분면
        // 왜냐면 z방향의 순서가 2->1->3->4이기에 이 순서이다.
}

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n >> r >> c;
    
    recur(0,0,pow(2,n));
    
    
    
    return 0;
}
