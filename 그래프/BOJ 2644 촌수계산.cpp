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


bool check[101];
int arr[101][101];
int ans[101];
queue<int>q;
int num;

void BFS(int start){        // 시작하는 부분이 a
    check[start] = true;
    q.push(start);
    
    while(!q.empty()){
        num = q.front();
        q.pop();
        
        for(int i=1;i<=n;i++){
            if(arr[num][i] == 1 && !check[i]){
                check[i] = true;
                ans[i] = ans[num] + 1;
                q.push(i);
            }
        }
        // arr를 늘리는 것처럼 넘어갈 수록 1씩 더 해준다.
        // 더 갈 수 있는 경우
    }
    
    
}



int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    
    cin >> n;
    int a, b;
    cin >> a >> b;
    cin >> m;
    
    for(int i=0;i<m;i++){
        int x, y;
        cin >> x >> y;
        
        arr[x][y] = 1;
        arr[y][x] = 1;
    }
    
    BFS(a);
                       // last인 b에 관하여 ans가 있으르 경우
    if(ans[b] != 0)    // ans에서의 b가 0이 아닐 경우 되는 것이므로 ans[b]를 출력
        cout << ans[b] << '\n';
    else
        cout << -1 << '\n';
    
    
    
    
    
    return 0;

}


