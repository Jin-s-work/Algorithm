
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

bool sosu(int n){
    
    if(n == 0 || n == 1)
        return false;
    
    for(int i=2;i<=sqrt(n);i++){
        if(n % i == 0)
            return false;
    }
    return true;
}





int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    bool arr[1000001];

    for(int i=2;i*i<=1000000;i++){
        if(arr[i] == false){        // i가 소수일때 (false이면 소수)
            for(int j=i*i;j<=1000000;j+=i){
                arr[j] = true;      // j가 i*i부터 시작해서 i씩 더할 경우에
            }                       // arr[j]는 소수가 아니므로 true로 한다.
        }
        
        
    }
    
    // 이렇게 써서 큰 소수 구하는 것도 괜찮은 방법이라 저장해 논다.
    
    cin >> n;
    
    cout << sosu(n);
    
    
    
    return 0;
}


