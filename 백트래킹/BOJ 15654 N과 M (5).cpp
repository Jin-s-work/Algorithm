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
    
    for(int i=0;i<n;i++){
        if(check[arr[i]])
            continue;
        
        // 사실 여기서 인덱스에 대해 중복 체크를 해줘도 되는 거라서
        // arr[i]대신 i로만 해도 되고, 배열의 범위도 그냥 [11]로 해도 된다..
        // 밑에 정렬은 대신 해야 하는 듯
        
        check[arr[i]] = true;
        ans[num] = arr[i];
        DFS(num+1);
        
        check[arr[i]] = false;
        
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
