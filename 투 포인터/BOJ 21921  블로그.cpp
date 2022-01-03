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


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);


    cin >> n >> m;
    
    int arr[250001];
    
    ll sum = 0;
    for(int i=0;i<m;i++){
        cin >> arr[i];
        sum += arr[i];
    }
    // 처음엔 m개만 받고 그 다음에 m부터 n까지 따로 받는다.
    
    ll tmp = sum;
    // 그 전까지 m개의 합을 tmp에 저장해논다.
    int num = 1;
    // num은 횟수
    for(int i=m;i<n;i++){
        cin >> arr[i];
        sum += arr[i] - arr[i-m];
        // m - n 사이의 구간을 더하는 과정에서
        // arr[m]을 처음 더할 경우 그 차에 관하여 arr[0]은 빼준뒤에 sum을 구성해 나가야 한다.
        // 그 다음 arr[m+1]을 더할 경우에는 arr[1]을 빼는 형식으로
        
        // sum 이 tmp보다 커질 경우에는
        if(sum >= tmp){
            if(sum == tmp)
                num++;
            // 같을 때는 num을 증가시켜구조
            else{
                tmp = sum;
                num = 1;
            }
            // 그냥 sum > tmp일 경우에는 num을 1로 바꾸어줌
            // 즉 그 기간이 몇개 있는지 찾는 것이다.
        }
    }
    
    
    if(!tmp)
        cout << "SAD";
    else{
        cout << tmp << '\n' << num;
    }
    
    
    

    return 0;

}
