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

// control i
#define MAX 987654321
#define mod 10007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h;

vector<pair<int, int>> v[300001];
int dist[300001];

void dijkstra(int start){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // 우선순위 큐를 내림차순으로 설정
    
    pq.push({0, start});
    dist[start] = 0;
    // 먼저 시작 부분을 넣어주고, dist도 시작이므로 0으로 시작
    
    while(!pq.empty()){
        int now = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        
        if(cost > dist[now])
            continue;
        // 비용이 현재의 dist보다 크면 넘어간다.
        
        for(int i=0;i<v[now].size();i++){
            int next = v[now][i].second;
            int nextcost = v[now][i].first;
            // v[now][i]로 해서 다음 부분을 미리 봐줌
            
            if(cost + nextcost < dist[next]){
                dist[next] = cost + nextcost;
                pq.push({dist[next], next});
            }
            // 원래의 cost와 다음 cost를 합한게 더 작으면, 새로 갱신해주고
            // dist[next], next를 우선순위 큐에 넣어준다.
        }
        
    }
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x;
    
    cin >> n >> m >> k >> x;
    
    for(int i=1;i<=n;i++){
        dist[i] = MAX;
    }
    // 처음 모든 dist 배열을 제일 크게 놔준다.
    
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back({1, b});
    }
    // 벡터에 a,b를 넣어준다.
    
    dijkstra(x);
    bool check = false;
    // 시작을 x로 하여 다익스트라를 돌림
    
    for(int i=1;i<=n;i++){
        if(dist[i] == k){
            cout << i << '\n';
            check = true;
        }
        // dist가 k인 경우가 있으면 출력
    }
    
    if(!check)
        cout << "-1" << '\n';
    // 한번 도 안되었을 경우 -1을 출력
    
    
    
    
    return 0;

}


