
#include <iostream>  // stdio.h 와 같은 것
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <cstring>
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
int h;

int graph[1001][1001];
bool check[1001];

void DFS(int x){
    check[x] = true;        // x에 들어간 표시를 하고
    cout << x << " ";       // 출력
    
    for(int i=1;i<=n;i++)
        if(graph[x][i] && !check[i])        // 0-n 동안 graph x에서 i로 가는 길이 true이고
            DFS(i);                         // check가 아직 지나가지 않았다면 DFS해준다.
    // 즉 x에서 i로 가는 길이 1이고(간선이 존재하고) i를 아직 가지 않았을 경우 거기로 가봄
    
    // 밑에서 graph[a][b]와 같은 경우 a와 b로 바로 넣어주므로
    // i도 맞게 해주는 것이 맞다.
}

void BFS(int x){
    
    queue<int>q;
    q.push(x);
    check[x] = true;        // BFS에서는 큐를 사용하여 x를 넣고, x를 방문했다고 체크해준다.
    
    while(!q.empty()){              // 큐가 비어있지 않는 동안
        int tmp = q.front();
        q.pop();                    // q의 맨 앞을 저장하고 뺌
        
        check[tmp] = true;          // 이 큐의 맨 앞 부분을 true로 표시를 하고 출력해줌
        cout << tmp << " ";
        
        for(int i=1;i<=n;i++){
            if(graph[tmp][i] && !check[i]){
                q.push(i);
                check[i] = true;
            }
            // DFS와 마찬가지로 간선이 있고 아직 안들어갔을 경우 push
            // 그러고 방문 했다고 표시해줌
            
            // 하지만 여기서 DFS와 다른 것은 BFS는 연결된 노드들을 모두 확인하면서 가므로
            // 여기서 for문과 큐를 통하여 큐에 들어갈 수 있는 i들을 모두 넣어주고 저장해놓고, 넘어간다.
            
            // DFS에서는 보이는데로 바로 들어가기에 queue가 필요가 없다.
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
        graph[a][b] = 1;
        graph[b][a] = 1;        // 양방향에 간선이 있음을 표시
    }
    
    DFS(v);     // 시작하는 정점의 번호가 v
    cout << '\n';

    for(int i=0;i<=1001;i++)
        check[i] = false;       // 다시 해야 하므로 초기화
    
    BFS(v);
    cout << '\n';
    
    
    return 0;
}


//
