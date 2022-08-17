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
#define mod 10007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h;


int arr[11][11];
bool white[11];
bool black[11];
int bishop[2];

// 모든 칸에 대해서 조사를 한다면 시간 초과가 나서
// 체스판을 검은색과 흰색으로 한칸씩 구별하면 서로 영향을 못주는 비숍의 성질을 이용하여
// 두개를 각각 조사하면 시간 복잡도를 줄일 수 있다.

// 비숍을 놓을 수 있는 칸의 수가 2 * n/2 * n/2
// -> 시간 복잡도 : O(2 ^ (n/2 * n/2)

// x가 col, y가 row라고 생각하면 된다.
void DFS(int num, int x, int y, int color){
    if(x >= n){
        y++;
        
        
        if(x % 2 == 0)
            x = 1;
        else
            x = 0;
        // 다음 행으로 넘어갈 떄
        // col이 홀수이면 0으로 바꾸어주고, 짝수이면 1로 바꾼다.
    }
    
    if(y >= n){
        if(num > bishop[color])
            bishop[color] = num;
        // color는 0 또는 1인데 더 큰 num이 나타날 경우 갱신한다.
        
        return;
    }
    
    // 1. 체스판에 비숍을 놓을 수 있나
    // 2. / 방향에 비숍이 놓여져 있는가
    // 3. \ 방향에 비숍이 놓여져 있는가
    
    // \의 경우 col - row의 값이 같고,
    // /의 경우 col + row의 값이 같다
    
    if(arr[y][x] && !white[x + y + 1] && !black[x - y + n]){
        white[x + y + 1] = true;
        black[x - y + n] = true;
        DFS(num + 1, x + 2, y, color);
        white[x + y + 1] = false;
        black[x - y + n] = false;
    }
    // 즉 x+y+1에 대해 white를 true로 해주면 x+y+1에 해당하는 / 가 모두 true가 된다고 생각하면 된다.
    // x - y + n 에 대해서도 마찬가지
    
    
    DFS(num, x + 2, y, color);
    // 검은색, 흰색 만 고려하기 위하여 col+2를 하면서 DFS를 들어간다.
}



int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    
    DFS(0,0,0,0);
    DFS(0,1,0,1);
    
    cout << bishop[0] + bishop[1];
    
    
    
    return 0;
    
}


// X X X X
// X X X O
// X X O X
// X O X X

// 와 같이 대각선에 따라서 같은 값을 유지하는 경우를 찾아서 이에 대해 true로 해줌
