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


int dist[126][126];
// 배열이 이중배열이므로 dist도 이중으로 해준다.
int arr[126][126];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

void dijkstra(){
    priority_queue<pair<int, pair<int, int>>>pq;
    
    pq.push({-1 * arr[0][0], {0,0}});
    dist[0][0] = arr[0][0];
    // 처음의 값이므로 그냥 dist를 넣어주기
    
    while(!pq.empty()){
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nextcost = arr[nx][ny];
            
            if(nx >= 0 && nx < n && ny >= 0 && ny < n){     // 범위안에 있을 경우
                int past = dist[nx][ny];                    // 전의 dist의 값을 넣어주고
                int now = dist[x][y] + nextcost;            // now에는 x,y에서 더한 값을 넣는다
                if(past > now){                         // 전의 값이 더 클 경우
                    dist[nx][ny] = now;                 // 작은 값으로 바꾸어 주고
                    pq.push({-1 * now, {nx, ny}});      // 오름차순을 하기 위해 음수로 바꾼뒤 넣어줌
                }
            }
        }
    }
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    // 14 8  = 22
    // 11 9 = 20
    int t = 1;
    while(1){
        
        cin >> n;
        if(n == 0)
            break;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> arr[i][j];
                dist[i][j] = MAX;
            }
        }
        
        dijkstra();
        cout << "Problem " << t++ << ": " << dist[n-1][n-1] << '\n';
        
        
    }
    
    // 이 문제는 사실 그냥 BFS 로 풀면 훨씬 간단하게 풀 수 있으나
    // 다익스트라를 쓰면 코드가 더 빠르기도 하고 다익스트라를 공부중이므로 다익스트라를 사용하였다.
    // 전 문제를 풀때는 그냥 내 방법을 쓰기로 하였으나 음수를 사용하여 오름차순을 사용하는 방법도 이해하고 넘거가야겠다.
    
    
    
    return 0;

}

