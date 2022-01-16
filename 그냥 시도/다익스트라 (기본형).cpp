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


vector<pair<int, int>> vec[20001];
int dist[20001];


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int v, e, start;
    cin >> v >> e;
    cin >> start;
    
    for(int i=0;i<e;i++){
        
        int a, b, c;
        cin >> a >> b >> c;
        
        vec[a].push_back({b, c});
    }
    
    for(int i=1;i<=v;i++){
        dist[i] = MAX;
    }
    // 다익스트라를 할때는 일단 다 크게 잡아 논다.
    
    priority_queue<pair<int, int>>pq;
    pq.push({0, start});
    // 이거 부터 시작
    
    dist[start] = 0;
    
    while(!pq.empty()){
        int cost = -pq.top().first;
        int now = pq.top().second;
        
        pq.pop();
        
        for(int i=0;i<vec[now].size();i++){
            int next = vec[now][i].first;
            int ncost = vec[now][i].second;
            
            if(dist[next] > cost + ncost){
                dist[next] = cost + ncost;
                // 더 작으면 갱신해야 한다.
                pq.push({-dist[next], next});
                // 바뀐 cost를 음수로 -dist[next]
                // 위치는 next이므로 그렇게 넣는다.
            }
        }
    }
    
    for(int i=1;i<=v;i++){
        if(dist[i] == MAX)
            cout << "INF" << '\n';
        else
            cout << dist[i] << '\n';
    }
    
    



    return 0;

}




