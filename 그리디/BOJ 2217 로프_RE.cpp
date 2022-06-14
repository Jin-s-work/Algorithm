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

ll arr[100001];


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n;
    
    
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    sort(arr, arr + n, greater<int>());
    // 내림차순으로 정렬을 한 후 각각 큰 값을 작은 인덱스로 각각 곱해줘야 균등한 최댓값 구하기 좋음
    
    ll sum = 0;
    ll Max = 0;
    for(int i=0;i<n;i++){
        sum = arr[i] * (i+1);
        // 버틸수 잇는 중량 * (k개의 로프) 가 최대 일때를 구함
        
        if(sum > Max)
            Max = sum;
    }
    
    cout << Max << '\n';
    
    
    
    
    return 0;

}

