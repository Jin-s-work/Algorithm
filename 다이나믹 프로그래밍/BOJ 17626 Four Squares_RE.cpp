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


int arr[50001];

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n;
    
    arr[1] = 1;
    // 1은 무조건 1개
    
    for(int i=2;i<=n;i++){
        int Min = MAX;
        
        for(int j=1;j*j<=i;j++){
            Min = min(Min, arr[i - j*j]);
        }   // j는 1부터 j*j가 i보다 작은 시점까지로 하며
            // Min에다 arr[i에서 제곱수를 빼준 차]로 비교하여 최소를 구해주면 최소를 알 수 있다.
            // 찾으면서 그 수에 대해서 작은 수가 나오면 계속 갱신해주는 것이다.
        
        arr[i] = Min + 1;
        // arr[i]는 이 최소보다 1이 크다.
        // arr[i - j*j] 자체가 j*j에다가 한 번 더 해준 것이기 때문이다.
        
    }
    
    cout << arr[n];
    
    
    return 0;
    
}
