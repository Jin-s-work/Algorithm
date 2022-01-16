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
#define mod 1000000007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h;



int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    ll a, b;
    cin >> a >> b;
    
    ll num = (b * 100) / a;
    
    if(num >= 99){
        cout << -1 << '\n';
        return 0;
    }
    // 99일때는 따로 해야 되는것이 1패라도 있으면 100%가 될 수 없다.
    
    int high = 1000000000;
    int low = 0;
    
    int ans = -1;
    
    
    while(low <= high){
        
        int mid = (low + high) / 2;
        ll tmp = ((b + mid) * 100) / (a + mid);
        // mid 만큼을 더 해주었을때를 임시로 저장해준다.
        
        if(num >= tmp){     // num이 tmp보다 클 경우
            ans = mid + 1;  // ans를 mid의 1 더한것으로 즉 가운데에서 오른쪽부분으로
            low = mid + 1;  // low를 가운데에서 오른쪽 부분으로 옮기기
        }
        else
            high = mid - 1; // num보다 작아질 경우 왼쪽부분으로 옮긴다.
        
    }
    
    cout << ans << '\n';
    
    
    
    return 0;

}


// 솔직히 바로 이분탐색으로 생각해서 하기가 쉽지 않다.
// 그냥 아무것도 모르는 상태에서는 할 수가 있으려나..
