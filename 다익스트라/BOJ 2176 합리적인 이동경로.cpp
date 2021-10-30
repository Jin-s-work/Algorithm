
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

int dist[1001];
int arr[1001];
// 여기서의 arr[i]는 i번 노드에서 출발하는 합리적인 이동경로의 수이다.

// 다익스트라를 사용하여 거꾸로 2번 노드 부터 탐색을 한다.
void dijk(vector<vector<pair<int, int>>> &graph){
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    
    pq.push({0,2});
    // 처음엔 0과 2를 넣어준다.
    dist[2] = 0;
    // 2로의 dist는 처음엔 0
    arr[2] = 1;
    // 2에서는 1로 가는 방법이 1개로 시작
    
    while(pq.size()){
        auto now = pq.top();
        pq.pop();
        // 현재 우선순위 큐에 있는 값을 now에 저장해준다.
        
        if(now.first > dist[now.second])
            continue;
        
        for(auto k : graph[now.second]){
            int nowdist = k.second + now.first;
            // 현재의 거리
            
            if(nowdist < dist[k.first]){
                dist[k.first] = nowdist;
                pq.push({nowdist, k.first});
            }
            // dist[k.first]가 더 클 경우 현재의 거리를 넣어주고,
            // 우선순위 큐에 현재의 거리와 k.first를 넣어준다.
            
            if(now.first > dist[k.first])
                arr[now.second] += arr[k.first];
        }   // 현재 노드 까지의 최단 경로의 길이가 다음 노드까지 최단 경로의 길이보다 크면
            // 다음 노드와 현재 노드 사이에 합리적인 이동경로가 존재하는 것을 알 수가 있다.
        
            // 따라서 위를 만족할 경우 점화식을 사용하여 dp[현재 노드] += dp[다음 노드]
            // 를 통하여 역방향으로 최단 경로를 탐색해준다.
    }
}
// 만약에 2번 노드와 1번 노드만 존재하고, 둘이 연결 되어있다고 할 때
// 1. 2번 노드에서 탐색 한 후, 1번 노드를 큐에 삽입한다.
// 2. 큐에 꺼낸 1번 노드는 2번 노드와 합리적인 경로가 존재하므로, 2번에서 출발했을 경우,
// 합리적인 이동 경로의 수를 1번 노드와 합산하면 dist를 채울 수가 있다.

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    

    cin >> n >> m;
    
    fill(dist, dist + 1001, 2147483647);
    // 답은 이 수 즉 int형 최대 수를 넘지 않으므로, 최대로 모두 설정해준다.
    
    vector<vector<pair<int, int>>> v(n+1);
    // 이 벡터를 위에다 놓으면 메모리 초과가 된다.
    
    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }   // a에서 b의 값을 c로 하고, b에서 a를 c로 한다.
    
    dijk(v);
    // 다익스트라 진행
    cout << arr[1];

    
    return 0;
}


// 이러한 그래프 문제와 다익스트라 문제를 더 풀어보아야 할듯....
// 이해는 갈듯 말듯 하는데 좀 아직은 이해가 안되는 것 같다.
// priority_queue 또한 마찬가지
