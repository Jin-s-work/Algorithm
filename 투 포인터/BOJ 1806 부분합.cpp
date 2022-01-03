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

int arr[3000001];
deque<int> dq;
int ans = 0;
int num = 0;
int kind[3001];
int c, d;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    int s;
    
    cin >> n >> s;
    
    int arr[100001];
    
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    int sum = arr[0];
    int a = 0;
    int b = 0;
    // 슬라이딩 윈도우를 쓰므로 포인터가 두개
    
    int Min = MAX;
    
    while(a <= b && b < n){
        if(sum > s){
            Min = min(Min, b - a + 1);
            sum -= arr[a++];
        }
        // sum이 m보다 작을 경우
        // b - a + 1 과 Min을 비교하여 제일 작은 것으로 하고
        // sum 에서 a를 하나 증가시킨 인덱스의 값을 sum에서 빼준다.
        
        // 왜냐하면 아직 작으므로 넘어가야하니까 a를 옮기기 전을 빼주고 옮겨주는 것
        
        else if(sum == s){
            Min = min(Min, b - a + 1);
            sum += arr[++b];
        }
        // m과 같을 경우에는 마찬가지로 min을 비교해주고, sum에서 b를 옮겨주고 그 값을 바로 더해본다.
        
        else if(sum < s)
            sum += arr[++b];
        // 작을 경우 그냥 min은 안하고 sum에서 더해준다.
    }
    
    
    if(Min == MAX)
        cout << 0 << '\n';
    else
        cout << Min << '\n';
    
    // 안바뀌었으면 즉 그러한 합을 만드는게 불가능하면 0을 출력한다.
    
    

    return 0;

}

