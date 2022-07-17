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


int arr[21][21];
int ans = MAX;
bool check[21];

int cal(){
    int sum1 = 0;
    int sum2 = 0;
    for(int i=0;i<n-1;i++){         // 이중 포문을 통해 전체 탐색
        for(int j=i+1;j<n;j++){
            if(check[i] && check[j])            // 한 팀이 true 나머지 팀이 false
                sum1 += arr[i][j] + arr[j][i];
            else if(!check[i] && !check[j])
                sum2 += arr[i][j] + arr[j][i];
        }
    }
    
    return abs(sum1 - sum2);        // 둘의 차를 구해줌
}

void comb(int num){
    if(num == n){
        ans = min(ans, cal());
        return;
    }
    // n이 될경우 최소인 ans를 파악하고 return
    
    check[num] = true;      // 현재 선수를 true로 하여 해보기
    comb(num + 1);
    check[num] = false;     // 그 다음에는 false로 하여 해보기
    comb(num + 1);
}



int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    
    comb(0);
    cout << ans;
    
    
    
    return 0;

}

// 재귀가 아직 완벽하게는 모르겠지만 오늘 안에 이해하기
