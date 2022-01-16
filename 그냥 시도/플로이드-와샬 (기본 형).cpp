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


    cin >> n >> m;
    
    int dist[101][101];
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = MAX;
        }
    }
    // 먼저 표 만들어 주기
    
    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        
        dist[a][b] = min(dist[a][b], c);
        // a에서 b로 가는 비용과 c를 비교해서 더 작은 것을 넣어준다.
        
    }
    
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dist[i][j] == MAX)
                cout << 0 << " ";
            else
                cout << dist[i][j] << " ";
        }
        cout << '\n';
    }



    return 0;

}


// 플로이드 와샬
// 하지만 시간복잡도가 O(n^3)이라서 많이 안쓰는듯

