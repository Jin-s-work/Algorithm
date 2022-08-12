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
      

int arr[10001];
bool check[10001];
int ans[10001];

void DFS(int num){
    if(num == m){
        for(int i=0;i<m;i++){
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    int tmp = 0;
    for(int i=0;i<n;i++){
        
        if(tmp == arr[i])
            continue;
        // 사전 순으로 증가하는 순서로 출력해야 하고, 같은 수를 여러 번 골라도 되므로
        // check만 없애주면 같은 수를 여러번 고를 수 있다.
        // 하지만 여기서 tmp를 없애준다면 9가 두개 이므로 이것들이 중복이 없게 둘다 모두 나오게 되어
        // 중복이 발생하므로 tmp는 살려놓고 check만 없애주어야 한다.
        
        ans[num] = arr[i];
        tmp = arr[i];
//        cout << tmp << "***  " << "num : " << num << "  " << "i : " << i << '\n';
        
        
        DFS(num+1);
       
    }

}


int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n >> m;
    
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    
    DFS(0);
    
    
    return 0;
    
}
