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


vector<pair<int,int>>v[300001];
int dist[300001];
// 넣어줄 벡터와 거리를 넣어줄 dist

void dijkstra(int start){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    // 내림차순으로 정렬하여 우선순위 큐에 넣어준다.
    
    pq.push({0,start});     // cost를 정렬시켜주어야 하므로 cost,index 순으로 넣어주는 것
    dist[start] = 0;
    
    while(!pq.empty()){
        int now = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        
        if(cost > dist[now])        // 원래의 dist 테이블 보다 크면 그냥 넘어감
            continue;               // 작을 경우에만 진행한다.
        // 그냥 cost 자체가 크면 넘어간다.
        
        for(int i=0;i<v[now].size();i++){       // 거기의 v[now]에 관해서
            int next = v[now][i].second;        // 그 다음에 해당하는 부분을 탐색하는 것이다.
            int nextcost = v[now][i].first;     // *** BFS ***
            
            if(cost + nextcost < dist[next]){   // 작을 경우엔 갱신하고 넣어주고 실행
                dist[next] = cost + nextcost;   // BFS와 완전히 같다.
                pq.push({dist[next], next});
            }
            // 현재와 다음 코스트를 더한 값이 원래의 dist보다 작을 경우 갱신하고, pq에 넣어준다.
            // dist[next]가 cost, next가 now로 되는 것
        }
        
    }
    
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    int x;
    cin >> n >> m >> k >> x;
    // 최단 거리 : k, 출발 도시 : x
    
    for(int i=1;i<=n;i++){
        dist[i] = MAX;
    }
    
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back({1,b});
    }
    // 벡터에 a,b를 넣어준다.
    // a->b에 1을 넣어 갈 수 있음을 표시
    // 최단 거리만 표시한다.
    
    dijkstra(x);
    // x가 시작
    bool check = false;
    
    for(int i=1;i<=n;i++){
        if(dist[i] == k){       // dist가 k인 부분에서 출력한다.
            cout << i << '\n';
            check = true;
        }
    }
    
    if(!check)                  // true로 한번이라도 안 바뀌었을 경우 -1을 출력
        cout << -1 << '\n';
    
                           
    return 0;

}



