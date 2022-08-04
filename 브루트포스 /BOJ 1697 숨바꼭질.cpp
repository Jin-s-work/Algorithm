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
#include <unordered_map>
#include <set>
#include <sstream>

// control i처
#define MAX 987654321
#define mod 10007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h;

// 전체 수에 대하여 그냥 check 배열을 만들어줌
bool check[100011];
int BFS(int now, int cnt){
    
    queue<pair<int, int>>q;
    q.push({now, cnt});
    check[now] = true;
    
    while(!q.empty()){
        
        n = q.front().first;
        m = q.front().second;
        q.pop();
        
        if(n == k)
            return m;
        // 같아질 경우 m을 리턴한다.
        
        
        if(n + 1 < 100000 && !check[n+1]){
            q.push({n+1, m+1});
            check[n+1] = true;
        }
        // 범위를 만족하고 아직 방문하지 않았을 경우 queue에 -1한 값을 넣어주고 true로 해준다.
        if(n - 1 >= 0 && !check[n-1]){
            q.push({n-1, m+1});
            check[n-1] = true;
        }
        
        if(n*2 <= 100000 && !check[n*2]){
            q.push({n*2, m+1});
            check[n*2] = true;
        }
    }
    // 범위나 check에 위반 되지않을 경우의 값을 queue에 넣어서 확인해준다.
    
    return 0;
}




int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n >> k;
    
    cout << BFS(n, 0);
    
    // DFS를 사용하여 모든 경우를 탐색할 경우 +1, -1 을 모두 탐색하기에 스택오버플로우
    // 따라서 BFS를 사용해야 한다.
    
    return 0;
    
}

// 원래 하던 대로 했는데 계속 outofbound가 떠서 새롭게 pair로 하고 몇가지 바꾸어 봄
