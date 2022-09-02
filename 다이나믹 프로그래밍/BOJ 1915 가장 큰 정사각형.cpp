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

// control i
#define MAX 987654321
#define mod 1000000000
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h;

int arr[1100][1100];
char st[1100][1100];


int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n >> m;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> st[i][j];
            arr[i][j] = st[i][j] - '0';
        }
    }
    
    int Max = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(arr[i][j] == 1){
                arr[i][j] = min(arr[i-1][j-1], min(arr[i][j-1], arr[i-1][j])) + 1;
            
                    if(Max < arr[i][j])
                        Max = arr[i][j];
                }
            }
        }
    
    // 처음에는 그냥 왼쪽, 왼쪽 위, 위가 모두 1일 때 비교해 주었는데
    // 각각의 값들 중 그냥 min으로 하여금 하나라도 0이 있으면 0에다가 1을 더해주는 방향으로 넣어주어도 된다.
    // 오히려 1인지로만 보면 절대 안되는게 값들을 넘겨서 이어올 때 1이 아니라 2 2
    //                                                       2    인 경우가 있을 때도 있으므로
    
    cout << Max * Max;
    
    
    return 0;
    
}
