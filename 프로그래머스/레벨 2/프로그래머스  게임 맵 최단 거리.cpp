
#include<vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int arr[101][101];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};


int solution(vector<vector<int> > maps)
{
    int answer = -1;
    
    memset(arr, -1, sizeof(arr));
    // arr를 모두 -1로 해주어 놓고 시작
    
    queue<pair<int, int>>q;
    q.push({0,0});
    
    arr[0][0] = 1;
    // 처음 시작은 1로 해준다.
    
    int n = maps.size();
    int m = maps[0].size();
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        if(x == n-1 && y == m-1)
            return arr[x][y];
        // 마지막 칸에 도달하면 이제까지 쌓아온 값인 arr[x][y]를 출력해준다.
        
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if(maps[nx][ny] == 0)
                continue;
            if(arr[nx][ny] == -1){
                arr[nx][ny] = arr[x][y] + 1;
                q.push({nx, ny});
                // 즉 아무것도 안지나간 -1일 경우 전에의 x,y의 값에서 1을 더해다가 줌
                // 그러고 q를 push해서 새로운 좌표로 나아감
            }
        }
        
        
    }
    
    
    return answer;
}

// 머 아마 같은 풀이일 텐데 다시 적어서 풀어봄













#include<vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int arr[101][101];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};


int solution(vector<vector<int> > maps)
{
    int answer = -1;
    
    memset(arr, -1, sizeof(arr));
    int n = maps.size();
    int m = maps[0].size();
    arr[0][0] = 1;
    
    queue<pair<int, int>>q;
    q.push({0,0});

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        if(x == n-1 && y == m-1)
            return arr[x][y];
        
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if(maps[nx][ny] == 0)
                continue;
            if(arr[nx][ny] == -1){
                arr[nx][ny] = arr[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    
    
    
    return answer;
}
