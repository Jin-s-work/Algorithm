
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
#include <set>

// control i
#define MAX 987654321
#define mod 1000000007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h, w;



int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    int arr[50001];
    arr[1] = 1;
    // 1은 1로 한개
    
    for(int i=2;i<=n;i++){
        int Min = MAX;
        for(int j=1;j*j<=i;j++){
            Min = min(Min, arr[i - j*j]);
            // j는 1부터 루트 i까지로 하며
            // Min 에다가 Min과 arr[i에서 제곱수를 빼어준 수]를 비교하여 최소를 구한다.
        }
        arr[i] = Min + 1;
        // arr[i]는 이 최소 수보다 1 크다.
        // 왜냐하면 arr[i - j*j] 자체가 j*j에다가 한 번 더 해준 것이기 때문
    }

    cout << arr[n];
    
    return 0;
}

// 푼 기억은 있는데, 쉬운데 발상이 쉽지 않았던 거 같다..

// 완전 탐색 문제가 아니라 dp 문제 인듯..?
// 왜냐하면 구하는 자연수에서 제곱수들을 빼보면서 줄여나가야 하는데
// 제곱수들에 이 정보를 저장해주어야 쉽기 때문에 이와 같이 한다.
