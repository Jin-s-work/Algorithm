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
#define mod 10007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h;


int arr[601];
int ans = 999999999;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n;
    
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    sort(arr, arr+n);
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int left = 0;
            int right = n-1;
            
            while(1){
                while(left == i || left == j)
                    left++;     // left는 i, j랑 다르다.
                while(right == i || right == j)
                    right--;    // right도 i, j와 다르다.
                
                if(left >= right)
                    break;
                // left가 right보다 클 경우 나간다.
                
                int diff = arr[i] + arr[j] - arr[left] - arr[right];
                // i와 j가 위의 값, left,right가 밑의 값이므로 빼준다.
                
                ans = min(ans, abs(diff));
                
                if(diff > 0)        // 만약 차가 양수이면 left를 증가시켜준다.
                    left++;
                else                // 차가 음수일 경우 right를 줄인다.
                    right--;
                
            }
        }
    }
    
    cout << ans;
    
    return 0;

}

// O(n^3)으로 해서 굉장히 비효율적이긴 하디만, 풀이는 이게 제일 쉽긴 한듯..

