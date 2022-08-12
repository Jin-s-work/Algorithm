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
    
    int tmp = 0;
    for(int i=cnt;i<n;i++){
        
        if(check[i] || tmp == arr[i])
            continue;
        
        
        check[i] = true;
        ans[num] = arr[i];
        tmp = arr[i];
//        cout << tmp << "***  " << "num : " << num << "  " << "i : " << i << '\n';
        
        // 비내림차순일 경우에는 그냥 변수를 하나 더 받아주어서 for 문에 추가해주면 된다.
        DFS(num+1, i);
        check[i] = false;
       
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
    
    DFS(0, 0);
    
    
    return 0;
    
}
