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


int arr[1000001];

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n;
    
    for(int i=2;i<=n;i++){
        
        arr[i] = arr[i-1] + 1;
        // 하나씩 증가시키는 것에서는 그냥 i-1을 i로 하고 1을 더해준다.
        
        if(i % 2 == 0){
            arr[i] = min(arr[i], arr[i/2] + 1);
        }
        // arr[i]는 arr[i/2]에 연산을 한번 더 하면 되는데 이를 원래의 arr[i]와 비교한다.
        
        if(i % 3 == 0){
            arr[i] = min(arr[i], arr[i/3] + 1);
        }
        // 3의 배수일 떄 위와 같이
    }
    // arr[i]의 경우에 arr[i-1], arr[i/2], arr[i/3]의 경우에서 올 수가 있는데
    // 이 셋을 다 min으로 비교하면서 최소의 경우의 수를 구해준다.
    
    // 이런 연산이 dp의 기본적인 구조라고 생각한다. 간단하다고 넘어가지 말고 더 생각해보자
    
    cout << arr[n];
    
    
    return 0;
    
}
