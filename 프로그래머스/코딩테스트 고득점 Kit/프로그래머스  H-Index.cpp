#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end(), greater<int>());
    
    // [6, 5, 3, 1, 0]
    //  1  2  3  4  5
    for(int i=0;i<citations.size();i++){
        if(citations[i] >= i+1)
            answer++;
    }
    // h의 최대는 citations가 i+1보다 작거나 같은 시점이다.
    // i = 0 값이 6이상인 것이 1회이상
    // i = 1 값이 5이상인 것이 2회이상
    // i = 2 값이 3이상인 것이 3회이상  ***
    // i = 3 값이 1이상인 것이 4회이상
    
    // 음.. 솔직히 나와도 제대로는 못풀듯
    
    return answer;
}

// #include <string>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int solution(vector<int> citations) {
//     int answer = 0;
    
//     sort(citations.begin(), citations.end(), greater<int>());
    
//     for(int i=0;i<citations.size();i++){
//         int num = citations[i];
        
//         if(num >= (i+1))
//             answer++;
//         // 왜냐하면 내림차순으로 정렬을 하였을때, 본인의 행렬보다 i+1 만큼 지났을때
//         // 그때 0,1,2,3,,,,i 만큼의 큰 수들이 있으므로 그 경우에 answer의 경우를 늘리면서
//         // 찾아줌.. 설명하긴 되게 애매하다.
        
//         // 즉 6,5,4,3,1,0 일 경우 4를 지날때 그 값만큼 보다 많은 개수가 있을 경우
//         // 세어주는게 맞으므로 한개의 for문으로도 충분하다.
        
        
//     }
    
//     // 간단하게 할 수 있는데 너무 복잡하게 생각해버렸다.
    
//     return answer;
// }

















