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


int arr[1001][1001];
int dp[1001][1001];

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    int h,w;
    
    cin >> h >> w >> n;
    
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin >> arr[i][j];
        }
    }
    
    dp[1][1] = n-1;
    
    // 2 1 0 0      2 1 0 0
    // 1 0 0 0      1 1 0 0
    // 0 0 0 0      1 0 0 0
    
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            
            // dp[i][j]에 n번 존재하면, dp[i+1][j], dp[i][j+1]에 n/2번 존재한다.
            // 왜냐하면 둘중의 하나로 가므로 경우의 수가 줄어듬
            dp[i+1][j] += dp[i][j] / 2;
            dp[i][j+1] += dp[i][j] / 2;
            
            if(dp[i][j] % 2 == 1){      // 홀수 일 경우
                if(arr[i][j] == 0)      // 0일 경우 dp[i+1][j]를 더한다.
                    dp[i+1][j]++;       // 0일 경우 아래쪽으로 ( 0 더해줌 )
                else                    // 1일 경우 dp[i][j+1]을 더한다.
                    dp[i][j+1]++;       // 1일 경우 오른쪽으로 ( 1 더해줌 )
            }
            
            arr[i][j] = (arr[i][j] + dp[i][j]) % 2;
            // arr에 방향을 반영한다.
        }
    }
    
    int row = 1;
    int col = 1;
    
    // 마지막 n번째를 탐색한다.
    while(row <= h && col <= w){
        if(arr[row][col] == 1)
            col++;      // 1인 경우 오른쪽으로 이동해야 하므로, col을 증가시킴
        else
            row++;      // 0인 경우 아래로 이동해야 하므로, row를 증가시킴
    }
    
    cout << row << " " << col;

    return 0;

}

// dp랑 그래프랑 결합되서 그런가
// 수업에서 알고 풀어서 그런거 같다. 그냥 풀라 했으면 절대 못 풀었을 거 같다.








//
//
//
//
//cin >> n >> k;
//
//priority_queue<int>pq;
//vector<int>v;
//
//for(int i=0;i<n;i++){
//    int a;
//    cin >> a;
//    v.push_back(a);
//}

//
//
