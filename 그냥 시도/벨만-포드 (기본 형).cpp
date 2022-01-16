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
#define INF 10000000

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);


    cin >> n >> m;
    
    vector<pair<int, int>> edge[501];
    ll dist[501] = {INF};
    
    for(int i=0;i<m;i++){
        ll a, b, c;
        cin >> a >> b >> c;
        
        edge[a].push_back({b, c});
    }
    
    for(int i=2;i<=n;i++){
        dist[i] = INF;
    }
    
    bool cycle = false;
    
    for(int i=1;i<=n;i++){
        for(int start = 1;start<=n;start++){
            if(dist[start] == INF)
                continue;
            
            for(int j=0;j<edge[start].size();j++){
                int to = edge[start][j].first;
                int cost = edge[start][j].second;
                
                if(dist[to] > dist[start] + cost){
                    if(i == n)
                        cycle = true;
                    
                    dist[to] = dist[start] + cost;
                }
            }
        }
    }
    
    if(cycle)
        cout << "-1" << '\n';
    else{
        for(int i=2;i<=n;i++){
            if(dist[i] == INF)
                cout << "-1" << '\n';
            else
                cout << dist[i] << '\n';
        }
    }



    return 0;

}


// 벨만포드 알고리즘
// i가 모두 다 돌면 cycle이 true가 되면서 사이클이 생김을 알림

// 시간복잡도는 O(VE) 가중치가 음수를 가질 때 사용
