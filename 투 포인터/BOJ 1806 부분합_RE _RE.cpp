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


vector<int>v;

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    
    int left = 0;
    int right = 0;
    int Min = MAX;
    int sum = 0;
    
    while(left <= right){
        if(sum >= m){        /// 이상이 될때는 옮겨준다.
            Min = min(Min, right - left);

            sum = sum - v[left++];
            // 초과일 경우에는 원래와 같이 왼쪽 값을 빼주고 왼쪽 인덱스는 증가시켜주며 옆으로 이동한다.
        }
        else if(right == n)
            break;
        else{
            sum = sum + v[right++];
            // 더 작을 경우에 원래와는 다르게 오른쪽 인덱스를 늘려주고 움직인 오른쪽 값을 더해준다.
            // 처음에 sum을 v[0]으로 저장하였기에 이런 방식으로 움직이는 것이긴 하다.
            
            // 근데 원래대로 그냥 이렇게 해도 될 것 같아서 이렇게 그냥 해보기
        }
//        else{       // 같은 경우에도 더 커질 수 있으므로 이렇게
//            Min = min(Min, right - left + 1);
//            sum = sum + v[++right];
//        }
        // 궁금한 것은 이상이 될 경우에 가장 짧은 것인데 같기만 해도 이미 최소 이므로 멈춰도 되지 않을까? 라는 생각
        // 따라서 지우고 제출할 생각이다.
        
        // 전에 풀었던 문제와는 다르게 이상이므로 조건을 조금만 다르게 해주면 될것이다..
        // 실버 4와는 크게 머가 다른지 모르겠다.
    }
    
    if(Min == MAX)
        cout << 0 << '\n';
    else
        cout << Min << '\n';

    
    
    return 0;
    
}
