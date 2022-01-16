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


vector<pair<int, int>> vec[1001];
// vec 들을 또 []로 개수를 설정

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> m >> k;
    
    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        vec[a].push_back({b, c});
    }
    
    // 다익스트라 부분인데, 정점을 k번째로 하는 것을 찾으므로 여러번 방문 해도 된다. (visit 필요 x)
    
    priority_queue<int> des[1001];
    // 그냥 우선순위 큐를 하면 내림차순 ( 한 개를 저장 )
    // 각 정점마다 최단 경로를 저장하기 위한 큐이다.
    // 즉, 여기에 k개의 원소가 있지 않으면 계속 원소를 넣어주고
    // k개의 원소가 차있으면 top과 cost를 비교하여 top이 더크면 pop하고, cost를 새롭게 더 넣어줌
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    // 이것은 오름차순인데 pair를 사용할 때는 이런 형태로 해야한다.

    pq.push({0,1});
    // 처음엔 0과 1를 넣어주고 시작한다.
    des[1].push(0);
    
    while(!pq.empty()){
        int cost = pq.top().first; // 각각의 cost들을 하는데 제일 작은 것을 해야 하므로 음수로
        int now = pq.top().second;  // 지금의 위치는 제일 위에있던 값으로 해야한다.
        pq.pop();
        
        for(int i=0;i<vec[now].size();i++){
            int next = vec[now][i].first;
            int nextcost = vec[now][i].second;
            
            if(des[next].size() < k){       // 아직 size가 k보닥 작아 즉 k개 만큼 차지 않았다면
                des[next].push(cost + nextcost);        // 계속 cost와 next를 넣어준다.
                pq.push({cost + nextcost, next});       // 정점과 우선순위 큐에
            }
            else{
                if(des[next].top() > cost + nextcost){   // 다 찼을 경우
                    des[next].pop();                    // 다음의 cost가 더 작을 경우
                    des[next].push(cost + nextcost);    // pop하고 새로 넣어준다.
                    pq.push({cost + nextcost, next});   // 정점과 우선순위 큐에 각각
                }
            }
        }
    }
    // 계속 갱신하며 pq가 빌 때까지 하면서 최소 값들을 각각 넣어준다.
    
    for(int i=1;i<=n;i++){
        if(des[i].size() < k)          // 안바뀌었으면
            cout << "-1" << '\n';
        else
            cout << des[i].top() << '\n';
    }
    // 사이즈가 작으면 -1을 하고 아닐 경우 제일 위에 있는 (k의 경우) 를 넣어줌
    
    
    

    return 0;

}

