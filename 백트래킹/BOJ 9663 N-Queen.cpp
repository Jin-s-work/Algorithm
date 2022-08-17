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


bool col[31];
bool check_right[31];
bool check_left[31];
int num = 0;

void DFS(int level){    // col에 대해 확인해주므로 level은 행인 row라고 생각해주면 된다.
    
    if(level == n){     // level이 n이 되어 모두 배치할 수 있는 경우
        num++;          // 조건에 부합하므로 num을 더해준다.
        return;
    }
    
    // 오른쪽 아래 대각선을 나타내는 check_right에서는 x,y의 합이 같은 것보다는
    // x - y 값이 모두 같다는 특징을 주로 생각하면 된다.
    // 이러한 오른쪽 대각선을 생각할 때 음수가 나올 수 있으므로 16이 아닌 30칸 정도를 놔준다.
    
    // 왼쪽 위 대각선을 나타내는 우상향은 x,y의 합이 같은 것을 특징으로 둘 수 있다.
    // left에서는 따라서 합이 같으면 되는 성질
    
    for(int i=0;i<n;i++){
        if(col[i] || check_right[i + level] || check_left[level - i + n-1])
            continue;
        
        // col은 같은 열에 존재하는 지를 확인
        // right는 우측 상단 대각선에 left는 좌측 상단 대각선에 존재하는지 확인
        
        // right에는 i에 해당하는 숫자에서 level만큼을 더해주고
        // left에는 level - i + n - 1
        // 즉, right와 더해서 n-1이 나오게 해준다.
        
        // 위에가 하나라도 true면 안되고 그냥 넘어가고 다 false일 경우
        // 밑을 true로 하고 DFS를 들어가준다.
        
        col[i] = true;
        check_right[i + level] = true;
        check_left[level - i + n - 1] = true;
        DFS(level + 1);
        
        // DFS에서 성공을 하고 num을 증가시키면 하나 전으로 돌아가서 false를 만들고
        // i를 늘리고 다시 찾아나가는 것이 백트래킹의 중요 포인트이다.
        // 여기서 모든 for문에 대해 시도하고 없다면 또 한번 DFS를 나와서 n-2번째로 간다.
        
        col[i] = false;
        check_right[i + level] = false;
        check_left[level - i + n - 1] = false;
        
        
        // 퀸의 위치를 true로 표시해 준다고 생각하면 된다.
    }
    
}

// 서로 다른 퀸은 같은 행이나 같은 열에 위치할 수가 없다.
// 따라서 한 행, 한 열에 1개의 퀸만 존재할 수가 있다.
// 대각선에 또한 존재할 수 없다.


int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n;
    DFS(0);
    cout << num;
    
    
    return 0;
    
}


// 0 X X X
// X X X
// X   X
// X     X

// 이므로 다음 열을 탐색할 경우에 3번째인 곳에 퀸이 들어갈 수 있다.
// 이때 따라서 퀸을 넣어주고 다시 여기서 또 탐색 하는 것이다.
