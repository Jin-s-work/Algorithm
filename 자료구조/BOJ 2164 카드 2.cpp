
#include <iostream>  // stdio.h 와 같은 것
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <functional>
#include <map>
#include <set>

// control i
#define MAX 987654321
#define mod 1000000007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h, w;




int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    queue<int>q;
    
    for(int i=1;i<=n;i++){
        q.push(i);
    }
    
    while(q.size() > 1){
        q.pop();
        q.push(q.front());      // 제일 위에 있는 것을 q에 push 해주고
        // 즉 push는 뒤에다 하는 것
        q.pop();                // 제일 위를 pop
    }
    
    cout << q.front();
    
    return 0;

}


// 1번이 제일 위에 n번카드가 제일 아래

// 한 장 남을때 까지
// 1. 제일 위 카드 바닥에 버림
// 2. 그러고 제일 위에 있는 카드를 제일 아래로
