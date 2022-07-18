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

// control i
#define MAX 987654321
#define mod 10007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h;


int arr[1001][1001] = {0};
int check[1001] = {0};

void DFS(int now){
    check[now] = 1;         // 일단 들어온 now에 대하여 true를 해주고 출력한다.
    cout << now << " ";
    
    for(int i=1;i<=n;i++){
        if(!check[i] && arr[now][i])
            DFS(i);             // 위의 조건이 만족될 경우 파고든다.
    }
}

void BFS(int now){
    queue<int>q;
    q.push(now);                // 큐에 지금의 값을 넣어주고 시작
    check[now] = 1;             // 지나왔으므로 true
    
    while(!q.empty()){          // 큐가 끝날때까지
        int x = q.front();
        q.pop();
        
        check[x] = true;        // 제일 위의 경우 지났으므로 true로 해주고
        cout << x << " ";       // 출력한다.
        
        for(int i=1;i<=n;i++){
            if(!check[i] && arr[x][i]){     // 다음의 경우 조건을 만족할때 queue에 넣어주고
                q.push(i);
                check[i] = true;            // 다시 하나하나 시작한다.
            }
        }
        
    }
    
    
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> m >> k;
    
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        arr[a][b]++;
        arr[b][a]++;
        
    }
    
    DFS(k);
    cout << '\n';
    
    for(int i=0;i<=1001;i++){
        check[i] = false;
    }
    // BFS를 해주어야 하므로 갱신해준다.
    
    BFS(k);
    
    
    
    
    return 0;

}


