
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
    
    sort(arr, arr+n, greater<int>());
    
    int Max = 0;
    int sum = 0;
    for(int i=0;i<n;i++){
        sum = arr[i] * (i+1);
        if(Max < sum)
            Max = sum;
    }
    // 내림차순을 해 주었으므로, 각각 수마다 (i+1)씩 곱해서 그게 최대일 경우 Max에 계속 넣어주면 됨
    
    cout << Max;
    
    return 0;
}

