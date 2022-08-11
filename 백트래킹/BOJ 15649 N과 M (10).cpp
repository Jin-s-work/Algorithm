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
      

int arr[11];
bool check[11];

void DFS(int num, int cnt){
    if(num == m){
        for(int i=0;i<m;i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    for(int i=cnt;i<=n;i++){
        
        arr[num] = i;
        DFS(num+1, i+1);
        // i도 증가하게 넣어야 하므로, DFS에 하나를 더 넣어서 i+1로 넘겨 준다.
        // tmp도 할 필요 없이 i+1 자체를 넣어주어서 cnt를 1 증가시키면 무조건 커진다.
        
    }
    
}



int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n >> m;
    
    DFS(0, 1);
    // 뒤의 수는 1부터 이므로 1로 넣는다.
    
    
    return 0;
    
}
