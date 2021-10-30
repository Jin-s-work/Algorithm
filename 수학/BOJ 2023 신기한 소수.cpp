
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


int arr[4] = {2, 3, 5, 7};
bool sosu(int n){
    
    if(n == 0 || n == 1)
        return false;
    
    for(int i=2;i<=sqrt(n);i++){
        if(n % i == 0)
            return false;
    }
    return true;
}
// 숫자가 0이거나 1일 경우 소수가 아니므로 false
// 에라토스테네스를 이용하여 루트n 이하까지 나누어 지면 false

void DFS(int start, int num){
    if(num == 0){
        cout << start << '\n';
        return;     // num이 다 끝나서 0이 되면, start를 출력해준다.
    }
    
    for(int i=1;i<10;i+=2){ // 1부터 홀수만을 뒷 자리 수에 넣어줌
        int tmp = 10 * start + i;   // tmp에 저장하여
        if(sosu(tmp))               // tmp가 소수이라면
            DFS(tmp, num-1);        // tmp를 start에 넣고, num은 1 줄여서 탐색한다.
    }                           // 즉 새로 만든 수인 tmp가 소수이면 다음을 진행하는 것
}
// DFS로 확인해준다.

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n;
    
    for(int i=0;i<4;i++){
        DFS(arr[i], n-1);
    }       // 각각의 되는 수인 2, 3, 5, 7로 시작해서 n-1을 num으로 탐색한다.
            // 왜냐하면 3자리 수일 경우 최대가 (1000-1)이다.
    
    
    
    

    
    return 0;
}


// 그냥 무식하게 푸려고 했는데 메모리 제한이 있다는 것을 알았다.
// 생각해보니 모든 자리수가 소수이기 위해서는 첫자리수는 무조건 소수여야 하므로
// 2, 3, 5, 7로만 시작 할 수 있다.

// 위에서 부터 내려오는 방법이 아니라, 처음 숫자에서 10을 곱하고 다음 숫자를 더하믄 방식으로
// 재귀를 이용해 구현 할 수 있었다.
// 하지만 여기서 뒤에는 홀수만 와야하는게 짝수를 더하면 2로 나누어 져서 홀수가 아니기 때문...
