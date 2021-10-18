
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


int arr[21][21][6];
int copymap[21][21];
queue<int>q;
int Max;


void clean(int num){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j][num] = 0;
        }
    }
}       // 배열을 모두 0으로 만들어서 다시 초기화

void turn(int num){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            copymap[j][n-i-1] = arr[i][j][num];
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j][num] = copymap[i][j];
        }
    }
    // copy라는 배열을 만들어서 돌려줌
    // 그리고 이 copy를 다시 arr에 넣어서 바꾸어준다.
}
// 배열 -> copy 로 돌려준 후에 이것을 다시 copy -> 배열로 해서 원래 배열을 돌린 채로 저장해줌

void move(int num){
    int a, b;
    int now;
    
    for(int i=0;i<n;i++){
        for(int j=n-1;j>=0;j--){
            if(arr[i][j][num] != 0)     // 0이 아닐 때 그 배열의 값을 큐에 넣어준다.
                q.push(arr[i][j][num]);
        }
        now = n-1;      // 처음 now는 n-1로 저장
        
        while(!q.empty()){
            a = q.front();      // 처음 큐에는 a를 저자앟고 pop
            q.pop();
            if(!q.empty()){     // 그래도 남아있으면
                b = q.front();  // b에 저장
                if(a == b){     // 둘이 같으면 즉 합칠 수 있으면
                    arr[i][now][num+1] = a + b;     // 배열의 [i][now]를 a+b로 저장하고
                    // num은 하나 더 커져서 저장한다. 한번하였기 때문에
                    now--;
                    // 그러고 now를 줄여주고
                    q.pop();    // pop한다.
                }
                else{               // 둘이 합칠 수 없는 경우에는
                    arr[i][now][num+1] = a;     // 그냥 [i][now]는 num+1만 변하고 a로 같다.
                    now--;                  // now는 줄어든다.
                }
            }
            else                            // q가 다 비면
                arr[i][now][num+1] = a;     // [i][now]에 그냥 a를 넣어준다.
        }
    }
}
// 같은 숫자 끼리는 오른쪽부터 더해야 하므로 queue를 이용하여 구현한다.
// queue에서 하나 뽑고 다음 front와 같으면 pop을 해서 그 다음 값은 미리 뺀다.

void DFS(int num){
    if(num == 5){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                Max = max(Max, arr[i][j][5]);
            }
        }           // 다 해보아서 num이 5가 되면 멈추고 배열중 최대값을 찾아서 넣어준다.
        return;     // 그러고 return
    }
    
    int dir = 4;        // 방향을 네 방향으로 해서
    while(dir--){       // 4번 진행한다.
        move(num);      // arr[num]의 숫자를 오른쪽으로 움직인 결과를 arr[num+1]에 저장해준다.
        DFS(num + 1);   // DFS
        clean(num + 1); // num+1의 경우를 clear
        turn(num);      // arr[num]을 회전한다.
    }
    // 이와 같은 과정을 4번 반복하여 상하좌우 한다.
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j][0];
        }
    }
    
    DFS(0);
    
    cout << Max;
    
    
    return 0;
}



//3 5 8
//2 4 7
//
//8(1,3)
//
//(3, 3 - 1 - 1)
