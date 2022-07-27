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



int arr[1001][1001];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int ans = 0;
int group = 1;
pair<int, int> check[1001][1001];

void BFS(int a, int b){
    queue<pair<int, int>> q1, q2;
    q1.push({a, b});
    q2.push({a, b});
    // 현재의 칸을 큐1, 큐2에 넣어준다.
    
    int num = 1;
    check[a][b] = {group++, 1};
    // group을 처음에는 1로 넣고 점점 증가하면서 넣어준다. {1,1}, {2,1},,,,
    
    while(!q1.empty()){
        int x = q1.front().first;
        int y = q1.front().second;
        q1.pop();
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny] == 1 && check[nx][ny].second == 0){        // arr는 아직 1인데 두번째가 아직 0인 경우
                num++;                             // 즉 움직일 수 있는 경우
                check[nx][ny].second = 1;
                q1.push({nx, ny});
                q2.push({nx, ny});
            }   // 개수를 증가시켜 주고 second를 1로 바꾸어 준다. 그리고 각각의 큐에 값을 넣어준다.
        }
    }
    
    while(!q2.empty()){
        int x2 = q2.front().first;
        int y2 = q2.front().second;
        q2.pop();
        check[x2][y2] = {group, num};
    }   // q2에 관하여 x2,y2에 관해 check에 넣어줌
}       // 여기서의 num은 위에서 1의 개수들을 세서 넣어주었으므로 그 그룹에 대한 숫자를 나타내준다.



int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> m;
    
    vector<pair<int, int>>v;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
            if(arr[i][j] == 0)
                v.push_back({i, j});
        }
    }
    // 0인 값을 벡터에 넣어준다.
    
    // 1인 칸들의 그룹화를 진행
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] == 1 && !check[i][j].second)
                BFS(i, j);
        }
    }
    // 값이 1이고, second 값이 0일 경우에 BFS를 진행하여 그룹 수를 세준다.
    
    
    // 0인 좌표를 탐색한다.
    for(int i=0;i<v.size();i++){
        int x = v[i].first;
        int y = v[i].second;
        int num = 1;
        map<int, int> mp;
        
        // 벡터에 있는 값들은 0들의 좌표들인데 여기서 주변의 1을 탐색하여 그 1의 그룹값이 얼마인지를 파악한다.
        for(int j=0;j<4;j++){
            int nx = x + dx[j];     // 이거 j로 해야하는 데 i로 해서 30분 본듯...
            int ny = y + dy[j];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny] == 1){
                mp[check[nx][ny].first] = check[nx][ny].second;
            }   // mp에 그룹에 개수의 인덱스에 num 값을 넣어준다.
        }
        
        for(auto o : mp){
            num += o.second;
        }
        ans = max(ans, num);
    }
    
    cout << ans;
    
    
    return 0;

}


// 문제로 보면 내가 절대 못풀 듯... 많이 봐야겟고 많이 풀어봐야겠다.
