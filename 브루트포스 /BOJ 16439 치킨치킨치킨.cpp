
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

int arr[31][31];
int choose[3];
int ans = 0;

void find(int now, int num){
    if(num != -1)
        choose[num] = now;      // 즉 여기서 0-3에 치킨의 종류 (인덱스)를 넣어주는 것
    // 0이 처음인 -1이 아닐 경우, 그 choose[]에 now를 넣어준다.
    
    if(num == 2){
        int sum = 0;
        for(int i=0;i<n;i++){
            int score = 0;
            for(int j=0;j<3;j++){
                score = max(arr[i][choose[j]], score);
                // 고른 3가지중에서 가장 선호하는 치킨의 값
            }
            sum += score;       // 그 합을 sum에 더해줌
        }
        ans = max(sum, ans);
        // 그 합 중 큰 것 고르고 return으로 빠져나옴
        return;
    }
    // 즉 마지막인 2가 되면 ans를 최대로 해서 return 해준다.
    
    for(int i=now;i<m;i++)
        find(i+1, num+1);
    
    // 0-n 까지 치킨의 종류중에서 3가지를 골라서 시키고,
    // 그 3가지를 0-3으로 하여 사람 모두 그 중에서 가장 선호하는 치킨의 값의 합을 구하면 된다.
    
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n >> m;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }
    
    find(-1, -1);
    
    cout << ans;
    
    
    return 0;

}

// 브루트포스 문제였는데, 조합을 이용하여 3가지를 지정하여 합을 구하고 이를 계속 반복해서 풀면 된다.
// 생각은 하였는데, 구현을 바로 못하였다.. 더 해바야겟다.
