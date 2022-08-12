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
      

int arr[21];
bool check[21];
int ans = 0;

int DFS(int num, int sum){
    if(num == n){
        return 0;
    }
    // num은 인덱스이고
    // sum + arr[num]을 한 것이 m이 될 경우 ans를 증가시켜준다.
    
    if(sum + arr[num] == m)
        ans++;
    
    DFS(num + 1, sum);
    // 그냥 sum을 넣어주는 경우와
    DFS(num + 1, sum + arr[num]);
    // sum + arr[num]을 넣어주는 경우로 나뉘어서 가지가 나뉜다.
    
    return 0;
}

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n >> m;
    
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    DFS(0,0);
    cout << ans;
    
    return 0;
    
}
