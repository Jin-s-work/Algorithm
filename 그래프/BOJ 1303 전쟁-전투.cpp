
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

char arr[101][101];
bool check[101][101];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int blue = 0;
int white = 0;


int BFS(int i, int j){
    
    queue<pair<int, int>>q;
    char c = arr[i][j];         // arr[i][j]를 c로 저장하여 주고
    int num = 1;                // num은 1부터 시작한다.
    
    q.push({i, j});
    check[i][j] = true;         // q에 i,j를 넣어주고, 방문하였으므로 true로 해주어야 한다.
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;       // 범위를 넘으면 나가기
            if(check[nx][ny] || arr[nx][ny] != c)
                continue;       // check가 이미 방문하여 true이거나 원래와 다를 경우
                                // num을 증가시키지 않고 끝내기에 나가기
            check[nx][ny] = true;   // 위의 조건들이 모두 아닐 경우 true로 해주고 증가시켜줌
            num++;
            q.push({nx, ny});       // 다음으로 진행하기 위해 push해준다.
        }
    }
    
    num *= num;     // n^2가 되므로 제곱해준다.
    
    return num;
    
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    for(int i=0;i<m;i++){
        cin >> arr[i];
    }
    // char로 받으므로 그냥 이렇게만 받아도 가능하다. 대신에 arr[101][101]로 한다.
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!check[i][j]){           // check[i][j]가 아직 가지 않았을 경우
                if(arr[i][j] == 'W')        // W일 경우 BFS를 해주고 더해줌
                    white += BFS(i, j);
                else                        // B일 경우 BFS를 해주고 더해줌
                    blue += BFS(i, j);
            }
        }
    }
    
    cout << white << " " << blue;
    
    return 0;
}


// 우리팀 : 하양, 상대 팀 : 파랑

// *** 알고보니 문제에서 가로 세로를 바꾸어 놓아 고려해 주어야 했다 ***
