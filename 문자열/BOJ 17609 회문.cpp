
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

string st;
int palin(int left, int right, bool check){
    while(left < right){                    // left가 right보다 작은 동안
        if(st[left] != st[right]){          // string이 왼쪽과 오른쪽이 다른 경우
            if(check){                      // true일 때만
                if(palin(left + 1, right, false) == 0 || palin(left, right-1, false) == 0)
                    return 1;               // left를 줄이고, false를 넣었을 때 0이거나
            }                               // right를 줄이고, false를 넣었을 때 0이면 1을 출력
                                            // 즉 여기서 하나씩 줄여서 되는 지를 확인 하는 것
                                            // false로 하므로, 같지 않는 경우가 생기면 2를 리턴
                                            // 그게 아니고, 0이 리턴 된다는 것은 유사 회문 이므로 1리턴
            return 2;
        }
        
        left++;
        right--;
        // 하고 나서 양쪽에서 줄여가며 한번 더 해본다.
    }
    
    return 0;
}




int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> t;
    
    while(t--){
        
        cin >> st;
        
        cout << palin(0, st.length()-1, true) << '\n';
        // 각각 맞는 수를 리턴한다.
        // 0 - st.length()-1 이고, check는 참이다.
    }
    
    
    return 0;

}


// continue에 복잡하게 생각 할 필요 없이 한 값을 해서 그 값을 출력 하면 되는 것..
// 스스로 풀기

// 스트링을 뒤집어서 했으나, 이것 보다 팔린드롬 자체는 투 포인터로 양 끝을 잡고 줄어들게 하는게 나은지도..?

// 투 포인터를 하는 방법을 사용하여 해보았다... 다 끝나면 이 부분도 꼭 해보아야 한다.
