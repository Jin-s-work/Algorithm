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


int v, e, start;
vector<pair<int, int>> vec[20001];
// vec 들을 또 []로 개수를 설정
int dist[20001];


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
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
    // 일단 처음은 거리들을 모두 제일 크게 잡아놈
    
    priority_queue<pair<int, int>> pq;
    // 우선순위 큐도 벡터와 마찬가지로 pair로 넣어줌
    pq.push({0,start});
    // 처음엔 0과 start를 넣어주고 시작한다.
    dist[start] = 0;
    // 시작부분은 0으로 시작
    
    while(!pq.empty()){     // 우선순위 큐 즉 남아있는 위치들이 없어질 때까지 함
        int cost = -pq.top().first; // 각각의 cost들을 하는데 제일 작은 것을 해야 하므로 음수로
        int now = pq.top().second;  // 지금의 위치는 제일 위에있던 값으로 해야한다.
        pq.pop();
        
        for(int i=0;i<vec[now].size();i++){
            int next = vec[now][i].first;
            int nextcost = vec[now][i].second;
            
            if(dist[next] > cost + nextcost){       // 새로 구해본 cost가 더 작으면 갱신
                dist[next] = cost + nextcost;
                pq.push({-dist[next], next});
            }   // 처음에 cost를 음수로 받앗기에 다시 음수를 넣어서 돌려준다.
        }       // 그리고 그 위치인 next로 second로 저장
    }
    
    for(int i=1;i<=v;i++){
        if(dist[i] == MAX)          // 안바뀌었으면
            cout << "INF" << '\n';
        else
            cout << dist[i] << '\n';
    }
    
    
    

    return 0;

}

