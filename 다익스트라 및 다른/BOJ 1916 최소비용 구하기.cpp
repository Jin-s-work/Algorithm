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


int dist[1001];
vector<pair<int, int>>v[1001];

void dijkstra(int start){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    
    pq.push({0, start});
    dist[start] = 0;
    
    while(!pq.empty()){
        int now = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        
        if(cost > dist[now])
            continue;
        
        for(int i=0;i<v[now].size();i++){
            int next = v[now][i].second;
            int nextcost = v[now][i].first;
            
            if(nextcost + cost < dist[next]){
                dist[next] = nextcost + cost;
                pq.push({dist[next], next});
            }
            
        }
        
    }
    
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    
    
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        // 출발도시 도착도시 버스비용
        v[a].push_back({c, b});
    }
    
    int start, end;
    cin >> start >> end;
    
    for(int i=1;i<=n;i++){
        dist[i] = MAX;
    }
    // n을 입력 받기도 전에 해버리니까 당연히 틀림.. 밑으로 내렸다.
    
    dijkstra(start);
    cout << dist[end];
    
    // 그래도 다익스트라 구조에 익숙해졌다.
    // 외웠다고 하는게 맞긴 함
                           
    return 0;

}
