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


vector<pair<int, int>>vec[300001];
int dist[300001];
int v,e;

void dijkstra(int start){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    pq.push({0, start});
    dist[start] = 0;
    
    while(!pq.empty()){
        int now = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        // 왜 안돌아가나 했더니 pop을 안해줌..
        
        if(cost > dist[now])
            continue;
        
        for(int i=0;i<vec[now].size();i++){
            int next = vec[now][i].second;
            int nextcost = vec[now][i].first;
            
            if(cost + nextcost < dist[next]){
                dist[next] = cost + nextcost;
                pq.push({dist[next], next});
            }   // cost, index인데 반대로 넣음..
            
        }
        
        
    }
    
}



int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> v >> e;
    cin >> k;
    
    for(int i=0;i<e;i++){
        int u, v, w;
        cin >> u >> v >> w;
        // u -> v : 가중치 w
        vec[u].push_back({w,v});
    }
    
    for(int i=1;i<=v;i++){
        dist[i] = MAX;
    }
    
    dijkstra(k);
    
    for(int i=1;i<=v;i++){
        if(dist[i] == MAX)
            cout << "INF" << '\n';
        else
            cout << dist[i] << '\n';
    }
    
    
    
                           
    return 0;

}

// 전의 문제와 비슷하게 dijkstra 진행했는 데 안보고 했는데 맞았다!
// 중간에 pop을 빠뜨린 부분만 빼고..
// 다른 방법으로 그냥 priority_queue<pair<int, int>>pq로 하려면 그냥 cost에 -를 붙이는 방법도 존재한다.
