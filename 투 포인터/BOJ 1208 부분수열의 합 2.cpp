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

// control i처
#define MAX 987654321
#define mod 10007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h;
            

int arr[41];
map<int, int> mp_sum;
// sum 부분이 map의 key 값이 된다.
ll cnt;

void right(int mid, int sum){
    if(mid == n){
        mp_sum[sum]++;
        return;
    }
    // 더해진 값인 sum에 대해서 mp_sum에 그 합에 대한 개수를 세어주면서 횟수를 나타내줌
    
    right(mid + 1, sum + arr[mid]);
    right(mid + 1, sum);
    // arr의 값을 더할 수도 있고, 안더할 수도 있으므로 나뉘어진다 (부분집합 이므로)
}
// right 부분수열의 합을 sum이라고 할 때
// right 수열을 탐색하면서 sum이 몇 번 나왔는지 mp_sum에 더해준다.
// 계속 그러면서 파고 들어감 더해준거 / 안더해준 것

// right 3  left 2   m 5    mp_sum[3]++  mp_sum[5 - 2]   즉 mp_sum[3]의 값을 더해준다.
// left에서 계속 2가 나와도 right와는 중복되서 한가지만 나오게 된다.
void left(int num, int sum){
    if(num == n/2){
        cnt += mp_sum[m - sum];
        return;
    }
    // right에서는 mp_sum에 sum에 대해 개수를 저장해주었는데, left에서는 반절을 탐색하므로
    // 합해서 m이 되어야 하므로, 여기서 나온 sum과 같이 더해서 m이 되는 경우이므로 m-sum
    // 합해서 m이 되려면 두개를 하나씩 더한 값이 나와야 한다.
    
    // 즉, left 수열의 부분수열의 합이 sum이 나왔을 때 map[m-sum]이 존재한다면
    // left 수열에 sum을 더하면 m이 되므로 그 수를 더해주면 됨...
    
    left(num + 1, sum + arr[num]);
    left(num + 1, sum);
}
// left에서는 num이 n/2 즉, 끝에 도달하였을 때
// cnt에 mp_sum의 m-sum 위치에 있는 수를 더해주고 리턴해준다.

// left의 부분수열의 합이 sum인 경우에 map[m - sum]이 존재한다면,
// right의 map 값과 left의 sum을 구하면 m이 된다.

// left, right 수열의 부분 합을 구할 때 공집합인 경우도 있으므로, left, right만 탐색할때도 가능하다.
// 0이면 0,0의 개수가 세어지므로 1로 된다.

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
   
    cin >> n >> m;
    
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    right(n/2, 0);
    // n/2부터 n까지
    left(0,0);
    // 0부터 n/2까지
    
    if(!m)
        cout << cnt - 1;
    else
        cout << cnt;
    // m이 0인 경우에는 left, right 의 부분수열 모두 공집합인 경우가 존재하기에 1을 빼주어야한다.
    
    // 시간 복잡도는 O(2^20)으로 충분하다.
    // 그냥 할 경우에는 2^40이므로 안되는데 이렇게 나누면 2^20으로 가능하다.
    
    
    return 0;
    
}

