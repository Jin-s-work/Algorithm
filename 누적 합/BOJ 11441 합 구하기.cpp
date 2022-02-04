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


int arr[100001];



int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n;
    
    int num;
    int sum = 0;
    for(int i=1;i<=n;i++){
        cin >> num;
        sum += num;
        arr[i] = sum;
    }
    
    cin >> m;
    
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        
        cout << arr[b] - arr[a-1] << '\n';
        
    }
    
    // 간단한 누적합 문제, b까지 구해진 합에서 a-1까지 구해진 합을 빼면
    // a-b 사이의 값을 알 수 있다.
    
    
    return 0;

}


