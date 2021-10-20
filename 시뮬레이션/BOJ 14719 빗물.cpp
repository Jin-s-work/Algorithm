
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


int arr[501];

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int h, w;
    cin >> h >> w;
    int ans = 0;
    
    for(int i=0;i<w;i++){
        cin >> arr[i];
    }
    
    for(int i=1;i<w-1;i++){
        // 마지막에 답 구할때, arr[0]은 필요 없고, arr[0]부터 arr[i-1]까지만 필요하므로
        // 수면은 양쪽 끝은 빼준다.
        int left = 0;
        int right = 0;
        
        for(int j=0;j<i;j++)
            left = max(arr[j], left);
        // i까지 중에 left의 최대를 찾는다.
        // 왼쪽에서 가운데로 가면서
        
        // w-1부터 >i까지 인것은 w-i에서 부터 시작하기 때문이다.
        for(int j=w-1;j>i;j--){
            right = max(arr[j], right);
        }
        // w-1부터 i까지 오른쪽에서 가운데로 오면서 최대를 찾는다.
        
        ans += max(0, min(left, right) - arr[i]);
        // 왼쪽과 오른쪽의 최대 중 제일 작은 값에서 arr을 빼서 음수가 되지 않을 경우에 더해줌
        // 수면이 밑이면 그냥 0이므로 넘어간다.
        
    }
    
    cout << ans;
    
    
    return 0;
}

// 총 1-w-1번 ans를 구하면서
// i를 기준으로 왼쪽 오른쪽을 나누어서
// i에 따라 왼쪽 최대값, 오른쪽 최대값을 구해서 그 중 작은 최대값을 i값에서 빼주어서 양수면 더해주는 알고리즘


//   |
//|  |
//|  |
//| ||
//||||
