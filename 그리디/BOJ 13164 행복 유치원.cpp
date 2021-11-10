
#include <iostream>  // stdio.h 와 같은 것
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <cstring>
#include <map>
#include <set>

// control i
#define MAX 987654321
#define mod 1000000007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,k;
int l,r,t;
int h, w;

int arr[300001];

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    
    int a, b;
    int ans = 0;
    cin >> a;
    // 제일 처음은 바깥에서 입력 받음
    
    for(int i=0;i<n-1;i++){
        cin >> b;
        arr[i] = b - a;
        a = b;
        // 처음에 b를 입력 받아서 차에 관한 arr를 만들고
        // a는 다음인 b로 갱신된다.
    }
    
    sort(arr, arr + n - 1);
    // arr의 배열 개수가 n-1개 이므로 이만큼 더해주어야 함
    
    for(int i=0;i<n-k;i++){
        ans += arr[i];
        // 작은 순으로 나열한 차이들을 n-k-1 만큼 더해서 얻는다..?
    }
    // n명의 학생을 k개의 조로 나누면 n-k개의 키 차이가 나기에 작은순으로 n-k개를 선택하면 된다.
    
    cout << ans;
    
    return 0;
}

// 처음에는 제대로 풀이가 생각안나서 전에 푼 방법대로 해보았다.
// 솔직히 구상할만한 풀이였다.. 더욱 열심히 해보자
