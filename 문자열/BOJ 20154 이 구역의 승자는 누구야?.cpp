
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


int arr[26] = {3, 2, 1, 2, 3, 3, 3, 3, 1, 1, 3, 1, 3, 3, 1, 2, 2, 2, 1, 2, 1, 1, 2, 2, 2, 1};

void even(){
    
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    string st;
    cin >> st;
    
    string tmp;
    for(int i=0;i<st.length();i++){
        tmp += to_string(arr[st[i] - 'A']);
    }
    // tmp에는 모든 수를 변환한 수를 string으로 해서 더해놔준다.
    
    while(tmp.length() > 1){
        int size = tmp.length();
        if(size == 1)
            break;
        
        string ans = "";
                
        if(size % 2 == 0){
            for(int i=0;i<size;i+=2){
                int num = ((tmp[i] - '0') + (tmp[i+1] - '0')) % 10;
                ans += to_string(num);
            }
            // 짝수일 경우 다 해서 반으로 준 ans에 더한 후, tmp에 넣어줌
            tmp = ans;
        }
        else{
            for(int i=0;i<size-1;i+=2){
                int num = ((tmp[i] - '0') + (tmp[i+1] - '0')) % 10;
                ans += to_string(num);
            }
            ans.push_back(tmp[size-1]);
            tmp = ans;
        }   // 홀수일 경우 마지막에는 ans에 마지막으로 넣어준 후, tmp에 넣음
    }
    
    int cnt = tmp[0] - '0';     // cnt는 아직 string이기에 수로 바꾸어줌
    if(cnt % 2 != 0){
        cout << "I'm a winner!";
    }
    else
        cout << "You're the winner?";
    
    
    return 0;

}


