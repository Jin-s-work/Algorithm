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
#define mod 1000000007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
//int h;


int dx[8] = {0,0,1,-1,1,1,-1,-1};
int dy[8] = {1,-1,0,0,1,-1,1,-1};
int k_now[2501][2];
int k_num = 0;
int p_now[2];
int visit[51][51];

int h_tmp[1000001] = {0,};
int h[2501] = {0,};
int h_num = 0;

int res = MAX;
int left;
int right;
string st[51];
int arr[51][51];

int check(){
    for(int i=0;i<k_num;i++){
        if(!visit[k_now[i][0]][k_now[i][1]])
            return 0;
    }
    return 1;
}
// k가 있는 곳을 visit한 것이 참일 경우 1을 리턴하고 아닐 경우 0을 리턴한다.

void DFS(int x, int y, int left, int right){
    if(!visit[x][y])
        visit[x][y] = 1;
    // 방문하지 않았을 경우 true로 해주고 나서
    // 움직임
    
    for(int i=0;i<8;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx >= 0 && ny >= 0 && nx < n && ny < n && !visit[nx][ny]){
            if(h[left] <= arr[nx][ny] && arr[nx][ny] <= h[right])
                DFS(nx, ny, left, right);
        }
        // left, right가 위에서 설정을 해주었는데 계속 오류가 떠서 그냥 함수에 넣어버림
    }
}
// 단순한 DFS

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n;
    
    
    for(int i=0;i<n;i++){
        cin >> st[i];
    }
    
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(st[i][j] == 'K'){
                k_now[k_num][0] = i;
                k_now[k_num][1] = j;
                
                k_num++;
            }
            if(st[i][j] == 'P'){
                p_now[0] = i;
                p_now[1] = j;
            }
        }
    }
    // k와 p의 위치를 저장해논다.
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            h_tmp[arr[i][j]] = 1;
        }
    }
    // arr에 있는 숫자가 존재하면 1로 체크해준다. ( 중복 방지를 위해 이렇게 한듯 )
    for(int i=0;i<1000000;i++){
        if(h_tmp[i]){           // 존재할 경우
            h[h_num] = i;       // 그 i를 h에 h_num에 관하여 넣어준다.
            h_num++;            // h_num은 처음부터 증가하므로, 순서대로 크게 해줌
        }
    }
    
    int left = 0;
    int right = 0;
    while(left <= right){
        if(right == h_num)
            break;
        // right가 중복을 포함하지 않은 숫자 만큼까지 오면 끝낸다..
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                visit[i][j] = 0;
            }
        }
        // 모두 false로 해놓고
        
        if(h[left] <= arr[p_now[0]][p_now[1]] && arr[p_now[0]][p_now[1]] <= h[right])
            DFS(p_now[0], p_now[1], left, right);
        // arr[p의 위치]가 h[left]와 h[right]를 포함한 사이에 존재 할때
        // DFS를 돌려줌
        
        if(check()){        // k가 있던 곳을 visit 했을 경우
            if(h[right] - h[left] < res)        // 둘의 차이가 원래 res보다 작으면
                res = h[right] - h[left];       // 갱신해준다. (최소를 구하는 것이므로)
            
            left++;         // left를 증가시켜줌 (작으므로)
        }           // 즉 정답 가능성이 있다면 left(최저지점)을 올려주고, 비교해서 갱신한다.
        else                // k가 있던 곳을 visit 하지 않은 경우
            right++;        // right을 증가시켜줌
    }               // 즉 정답 가능성이 없다면, right(최고 지점)을 올려준다.
    
    
    cout << res;
    
    
    return 0;

}


// BFS, DFS, 투 포인터 같이 하니까 쉽지 않다.....
// 계속 보니까 이해는 간다...
