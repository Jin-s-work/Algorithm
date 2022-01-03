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
#include <set>

// control i
#define MAX 987654321
#define mod 1000000007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h, w;


int arr[200001];
int v[100001];
// 이 크기 때문에 틀린듯

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);


    
    cin >> n >> k;
    
    
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    // arr를 1부터 하나씩 넣는다.
    
    int sum = 0;
    int left = 1;
    int right = 1;
    // left와 right 모두 같이 1에서 시작
    
    while(left <= right && right <= n){
        // left가 계속 right보다 작고 right도 n보다 작아야 함
        if(v[arr[right]] < k){
            v[arr[right++]]++;
            sum = max(sum, right - left);
        }
        // v에 있는 arr[right]는 k보다 작아야 한다.
        // 이때 right를 증가시켜주면서 거기 있는 v[]값을 하나 증가시켜주고,
        // 그 길이와 sum의 최대와 비교해서 넣어줌
        else if(v[arr[right]] == k)
            v[arr[left++]]--;
        // v가 k와 같아지면 left를 늘려주고, 그 left를 늘려준 v[arr[left]]는 줄여줘야한다.
    }
    
    
    cout << sum;

    return 0;

}

