
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


vector<pair<int, int>> vec[20001];
int dist[20001];


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int v, e, start;
    cin >> v >> e >> start;
    
    for(int i=0;i<e;i++){
        int a, b, c;
        cin >> a >> b >> c;
        vec[a].push_back({b, c});
    }
    
    for(int i=1;i<=v;i++){
        dist[i] = MAX;
    }
    
    priority_queue<pair<int, int>>pq;
    pq.push({0, start});
    
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
                pq.push({-dist[next], next});
            }
        }
    }
    
    
    
    return 0;
}


