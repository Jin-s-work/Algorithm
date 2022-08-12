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
      

int arr[10001];
bool check[10001];
int ans[10001];

void DFS(int num){
    if(num == m){
        for(int i=0;i<m;i++){
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    // 여기서 tmp를 계속 갱신해준다.
    // 맨 처음에 고르는 수는 직전에 골랐던 수와 관계 없이 아무거나 골라 주기 위하여
    int tmp = 0;
    // for문이 끝나면 새로고침 되어야 함
    for(int i=0;i<n;i++){
        
        // 직전에 고른 수가 아니고 이미 고른 수가 아닐 경우에
        if(check[i] || tmp == arr[i])
            continue;
        // tmp가 다음인 arr[i]와도 같을 경우 continue
        // 즉 숫자가 같건 다르건 arr[i]에서의 i의 중복을 피해주기 위함이다.
        
        // continue가 있어서 num이 증가되는 DFS에 안들어가고 continue해서 뛰어넘고 for문이 진행되는 것
        
        check[i] = true;
        ans[num] = arr[i];
        tmp = arr[i];
//        cout << tmp << "***  " << "num : " << num << "  " << "i : " << i << '\n';
        
        // 들어온 arr[i]를 tmp에 저장해주고, 넘어간다.
        // 이렇게 하여서 바로 직전에 내가 골랐던 수와 똑같은 수를 못고르게 한다.
        // 예를 들면 (1,9)를 이미 출력했을 때, (1, ?)에서 ?를 구할때 9를 못지나가게 하는 것이다.
        DFS(num+1);
        check[i] = false;
       
    }

}
// 처음에는 1 arr[i]에 넣고, DFS(1)로 넘어감 거기서는 i=0일때는 true이므로 넘어가고 i=1, num=1로 진행
// tmp에 7이 저장되고, ans에는 1, 7이 들어가고 DFS(2)가 되므로 이렇게 출력
// 그 다음에는 백트래킹이 되는 것이다. 리턴 되었으므로 여기서의 i=1이 false로 되어서 다시 for문을 돌리는데
// i=2가 된다. 여기서 ans[num] 즉, ans[1]이 9로 바뀌고, tmp도 따라서 9로 바뀐다. DFS(2)로 돌게 되고
// 따라서 1 9가 ans에 들어있는 것이다..
// for문이 돌면서 i=3이 되는데 tmp가 arr[3]과 같으므로 continue하게 된다.

// 전체의 1에 대한 DFS도 또한 끝났으므로 다시 0으로 돌아간다. ( 이게 사실 이제까지 이해가 안되었던 듯)
// 아까 num = 0 i = 0 에 대해 했는데 이게 끝났으므로 check[0] = false가 되고, tmp는 계속 9 인상태
// arr[1] 은 7이기에 tmp에 다시 7이 저장되고, num도 0이므로, ans[0] = 7이 저장된다.
// 여기서 또 num = 1로 들어간다. 이때 i=0부터 시작이다. 아까 check[0]을 false로 해주었으므로
// num = 1 i = 0 에 대해 진행되기로 하고 따라서 arr[1]에 1이 들어가고, tmp는 1이 된다.
// DFS(2)가 되었으니 출력을 해주고 나와서 다시 check[0] = false로 한다.
// 그 다음 num = 1, i = 1이 되는데, 아직 check[1] 이 true이므로 7일때는 넘어가고,
// num = 1 i = 2가 된다. 그럴 경우에 ans[1] = 9가 들어가게 되고 tmp가 들어가게 된다.
// 따라서 DFS(2)로 7 9를 출력한다. 다 조사를 하였으므로 나온다.
// 다시 num = 0 i = 2로 돌아오게 되고, tmp = 9로 바뀐다. 가능하므로 DFS(1)로 다시 들어가여
// num = 1 i = 0이 되고, 다시 tmp = 1로 바뀌는데 num이 1이므로 9 1이된다. 그 다음은 9 7이 되고 9 9가 되고.

// DFS의 원리를 이렇게 풀어보니 이해가 되었다... check[i]로 false를 표시해주어야 한다.
// 이렇게 하면서 제일 마지막 수들의 중복을 막아줄 수 있었고, DFS의 작동원리를 알게 되었다....
//



// 처음에 1 arr[i]에 넣고 DFS(1) 그 다음에 7 arr[i]에 넣고 DFS(2) 되었으므로 1 7 출력하고 끝
// tmp는 7로 저장되어있었으므로 7은 넘어가고 1이랑 9가 들어가고 tmp는 9로 변한다. 두번 하였으므로 1 9 출력
//


int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n >> m;
    
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    
    DFS(0);
    
    
    return 0;
    
}
