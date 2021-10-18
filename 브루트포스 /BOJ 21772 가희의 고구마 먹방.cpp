
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

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int ans = 0;
int arr[101][101];

void DFS(int x, int y, int sum, int num){
    if(num == t){
        if(sum > ans)
            ans = sum;
        // return을 따로 안하고 괄호에 끼어버려서 틀림..... 메모리 초과가 그래서 뜸
        return;
                   // 시간 초과 되었을 때 최대를 찾는다.
    }
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny] != -1){
            bool check = false;         // 다음 움직이는 게 범위 안에 있고, 장애물이 아니면 가능
            int plus = 0;
            if(arr[nx][ny] == 1){
                arr[nx][ny] = 0;        // 만약 고구마를 찾으면 0으로 바꾸고 true로 표시한다.
                check = true;
                plus = 1;
            }
            DFS(nx, ny, sum + plus, num+1);
            // 고구마를 먹었으면 check가 true이므로 sum을 1증가, 안 먹었으면 sum 증가 안함
            
            if(check)
                arr[nx][ny] = 1;
            // 고구마가 있던 자리면 다시 되돌려 놓는다.
        }
    }
    
    
    
}
// 가희 G, 고구마 S, 빈 칸 . , 장애물 #

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> t;
    
    char st;
    int a = 0, b = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> st;
            if(st == 'G'){
                a = i;
                b = j;              // a와 b에 저장하여
            }                       // 가희의 위치를 저장해서 시작점으로
            else if(st == '#')      // 장애물 -1
                arr[i][j] = -1;
            else if(st == 'S')      // 고구마 1
                arr[i][j] = 1;
        }
    }
    
    DFS(a, b, 0, 0);        // 가희의 위치와 합과 횟수 넣어줌
    
    cout << ans;
    
    return 0;
}



