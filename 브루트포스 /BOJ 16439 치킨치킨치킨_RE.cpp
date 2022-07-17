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


int arr[31][31];
int choose[3];
int ans = 0;

void find(int now, int num){
    if(now != -1)
        choose[num] = now;      // now는 0-3, 이 인덱스에 치킨의 종류를 넣어주는 것
    // 이미 온적이 있어서 -1이 아닐 경우
    
    if(num == 2){
        int sum = 0;
        for(int i=0;i<n;i++){
            int score = 0;
            for(int j=0;j<3;j++){
                score = max(arr[i][choose[j]], score);
                // i번째 사람의 경우 중, 3가지 경우 중 제일 큰 점수를 찾는다.
            }
            sum += score;
        }
        
        ans = max(sum, ans);
        return;
        // 2가 되면 return으로 빠져나옴
    
    }
    
    for(int i=now;i<m;i++)
        find(i+1, num+1);
    
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
    // 7 8 9 8 7
    
    find(-1, -1);
    
    cout << ans;
    
    return 0;

}

