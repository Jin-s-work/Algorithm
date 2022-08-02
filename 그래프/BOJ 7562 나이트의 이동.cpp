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


bool check[301][301];
int arr[301][301];

int dx[8] = {1,2,1,2,-1,-1,-2,-2};
int dy[8] = {2,1,-2,-1,2,-2,1,-1};
queue<pair<int, int>>q;
int a, b, c, d;

void BFS(int a, int b){     // 크기를 안넣어줘도 전역 변수로 되어 있으면 그대로 받나 보다
    
    q.push({a, b});
    check[a][b] = true;
    // 처음의 좌표를 넣어주고 지나갔음을 표시
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        if(x == c && y == d){
            cout << arr[x][y] << '\n';
            
            while(!q.empty())
                q.pop();
            // 없어질때까지 pop해서 이제까지 들어온 것들을 없애버린다.
            
            break;
        }
     
        for(int i=0;i<8;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx >= n || ny < 0  || ny >= n)
                continue;
            // 넘으면 지나감
            
            if(!check[nx][ny]){
                check[nx][ny] = true;
                arr[nx][ny] = arr[x][y] + 1;
                q.push({nx, ny});
            }
            // 아직 안 지난 경우 true를 하고 이제까지 건너온 수에 1씩을 더해준뒤에 큐에 넣어준다.
        }
        
    }
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> t;
    
    while(t--){
        cin >> n;
        
        memset(arr, 0, sizeof(arr));
        cin >> a >> b;
        cin >> c >> d;
        BFS(a, b);      // n을 안넣어줘도 이미 받은 수라 사용할 수 있나보다
        
        memset(arr, 0, sizeof(arr));
        memset(check, false, sizeof(check));

    }
    
    
    
    return 0;

}

// 나이트의 이동이라도 다를 것 없이 똑같이 dx,dy를 구현하여 넣으면 똑같다.


