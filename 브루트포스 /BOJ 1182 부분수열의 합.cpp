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



int arr[21];
int ans = 0;

int DFS(int num, int sum){
    if(num == n)
        return 0;
    // n번 돌았을 경우 빠져 나오기
    
    // ** num을 인덱스라고 생각 하면 된다. **
    
    if(sum + arr[num] == m)
        ans++;
    // 만약 이제까지 더해진 sum 에 arr의 num이 더해져서 m이 되면 ans를 늘려준다.
    // 여기서 나갈 수는 없는 것이 뒤에서 이를 이용해서 또 같은 수가 나올 수 있기 때문에
    // 개수만 증가시켜준다.
    
    DFS(num + 1, sum);
    // 안쓰고 그냥 넘어가거나
    DFS(num + 1, sum + arr[num]);
    // 합으로 해서 맞아서 더한 경우에는 이 상태로 넘어가기
    
    return 0;
}
// 이제는 DFS의 재귀적인 부분에 이해가 좀 더 잘 된 것 같다.
// 두 가지 경우에 대해서 계속 파고들며 DFS를 해 나가면 된다.


int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n >> m;
    
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    ans = 0;
    DFS(0,0);
    
    cout << ans;
    
    
    
    return 0;
    
}

