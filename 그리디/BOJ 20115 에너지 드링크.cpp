
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
int h, w;

int arr[100001];

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    sort(arr, arr + n, greater<int>());
    
    double sum = (double)arr[0];
    // 제일 큰 것만 그대로 넣고
    
    for(int i=1;i<n;i++){
        sum += arr[i] / 2.0;
    }
    // 밑에 부분은 다 반씩 해서 더해주면 된다..
    // 그냥 이렇게 하면 된다.. 나 처럼 각각 해주면 횟수가 더 많아져 잃는 게 더 많다...
    
    // 어차피 다 한번씩만 나누어 지니까 cout.precision도 안해도 되나...
    // 그렇네 머여
    cout.precision(6);
    // 그게 아니라 10^(-5) 이라서 6으로 해주니까 맞네..
    cout << sum;
    
    return 0;
}

// 3 2 10 9 6
// 2 3 6 9 10


