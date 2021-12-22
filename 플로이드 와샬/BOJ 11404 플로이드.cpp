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
#include <set>

// control i
#define MAX 987654321
#define mod 1000000007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h, w;


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
    }       // 같은 경우는 0이고 다른 경우는 바뀔 수 있으므로 MAX로 해줌
    
    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;

        dist[a][b] = min(dist[a][b], c);
        // dist[a][b] 자체가 값이므로, c와 그 중에 작은 값을 넣어준다.
        
        // 0부터 진행되므로 1씩 작게해서 해준다.
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    // dist로 이어지는 걸 비교하면서 갱신한다.
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dist[i][j] == MAX)
                cout << 0 << " ";
            else
                cout << dist[i][j] << " ";
        }   // MAX일 경우 0으로 하고 아닐 경우 그 값을 그냥 넣어준다.
            // MAX면 안바뀐 것임
        cout << '\n';
    }


    return 0;

}

//
//7
//1GTW
//2PDF
//3REF
//3RDF
//2REF
//1PTF
//3RES
