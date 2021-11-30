

#include <string>
#include <vector>

using namespace std;

// int two(int num){       // 10진법을 2진법으로 바꾼다.
//     int cnt = 0;
//     for(int i=1;num>0;i*=10){   // i를 10배씩 곱해간다.
//         int binary = num % 2;
//         cnt += binary*i;    // 2로 나눈 나머지를 더하면서
//         num /= 2;       // 나누었다고 치므로 2로 나눈다.
//     }
//     return cnt;
// }

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n);
    
    for(int i=0;i<n;i++){
    int wall = arr1[i] | arr2[i];
    answer[i].assign(" ", n);
        // 기존의 데이터를 삭제하여 " " ~ n 데이터를 할당
    
    for(int j = n-1;j>=0;j--){
        if(wall % 2 != 0)
            answer[i][j] = '#';
        else
            answer[i][j] = ' ';
        
        wall /= 2;     // k를 2씩 나누어 가며 진행한다.
    }
    
    }
    return answer;
}













