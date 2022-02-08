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

// control i
#define MAX 987654321
#define mod 10007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h;

ll arr[5001];
ll res = 3000000001;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n;
    ll a, b, c;
    
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    // 먼저 처음 정렬을 해 주어야 이분 탐색 하기 유용
    
    for(int i=0;i<n-2;i++){
        // 두개는 이동하고, 처음 i의 인덱스는 고정시켜 놓고 사용한다.
        int left = i + 1;
        int right = n - 1;
        // left는 i보다 하나 큰 경우, right는 전체에서 제일 큰 수 ( 제일 오른쪽 )
        // 에 놓고 시작한다.
        
        while(left < right){
            ll num = arr[i] + arr[left] + arr[right];
            // 세 개의 합을 num으로 하고
            if(abs(num) < res){     // 0과 가까우면 되므로, abs로 한다.
                res = abs(num);     // |num|이 res보다 작은 경우 res를 갱신시킨다.
                a = arr[i];         // 제일 작은 절대값을 구하는게 목표이므로
                b = arr[left];
                c = arr[right];     // 그러고 답들도 갱신
            }
            
            if(num < 0)
                left++;      // num이 만약 음수일 경우 left를 옮겨서 더 크게 해준다.
            else
                right--;     // 만약 양수일 경우엔 더 줄일 수 있게 right를 줄인다.
        }
    }
    
    cout << a << " " << b << " " << c;
    
    
    return 0;

}


