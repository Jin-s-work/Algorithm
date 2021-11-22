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


int arr[1001][1001] = {0};
int check[1001] = {0};

void DFS(int now){
    check[now] = 1;
    cout << now << " ";
    // 지나는 now를 그냥 모두 출력해주면 편하다.
    for(int i=1;i<=n;i++){
        if(!check[i] && arr[now][i]){
            DFS(i);
        }
    }
}

void BFS(int now){
    
    queue<int>q;
    q.push(now);
    check[now] = true;
    // 처음의 now에도 물론 true 해주어야 한다.
    
    while(!q.empty()){
        int x = q.front();
        q.pop();
        
        check[x] = true;
        cout << x << " ";
        
        for(int i=1;i<=n;i++){
            if(arr[x][i] && !check[i]){
                q.push(i);
                check[i] = true;
            }
            // true일 경우 가는 경로를 모두 queue에 push해준다.
        }
    }
    
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int v;
    cin >> n >> m >> v;
    
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        arr[a][b]++;
        arr[b][a]++;
    }
    
    DFS(v);
    cout << '\n';
    
    for(int i=0;i<=1001;i++){
        check[i] = false;
    }
    
    BFS(v);
    
    
    
    return 0;

}


// DFS, BFS의 기본적인 틀이므로, 자주 익혀가며 푸는게 좋을 듯

// DFS는 보통 파고들면서 찾고, BFS는 큐를 사용하여 큐에 push하고 pop하며 없어질 때까지 한다.
