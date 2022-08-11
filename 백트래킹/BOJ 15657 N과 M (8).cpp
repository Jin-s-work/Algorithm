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

void DFS(int num, int cnt){
    if(num == m){
        for(int i=0;i<m;i++){
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    for(int i=cnt;i<n;i++){
        
        ans[num] = arr[i];
        DFS(num+1, i);
       
        // 비 내림차순은 증가하는 수열이 i+1이라면 얘는 그냥 i를 넣어주면 된다.
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
    
    DFS(0,0);
    
    
    return 0;
    
}
