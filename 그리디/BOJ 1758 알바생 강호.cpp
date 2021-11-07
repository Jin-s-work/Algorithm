
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
    // 밑의 예시를 보면 내림차순이 조은듯..?
    
    ll sum = 0;
    // long long을 안해서 틀린 걸 지도..
    // 그렇네
    for(int i=0;i<n;i++){
        if(arr[i] - i > 0)
            sum += (arr[i] - i);
        
    }
    
    cout << sum;
    
    
    return 0;
}

// 3 2 1로 예를 들면
// 3 1 -1     4

// 1 2 3으로 예를 들면
// 1 1 1     3

// 1 3 5로 예를 들면
// 1 2 3    6

// 5 3 1로 예를 들면
// 5 2 -1  7


