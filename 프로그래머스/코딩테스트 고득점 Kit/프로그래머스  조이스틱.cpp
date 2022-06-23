


#include <string>
#include <vector>
#include <algorithm>

using namespace std;



int solution(string name) {
    int answer = 0;
    
    int n = name.length();
    int num = n - 1;
    // 그냥 한방향으로만 갈때
    
    for(int i=0;i<n;i++){
        if(name[i] - 'A' < 14)          // 앞부분에 있어 그냥 더해주기
            answer += name[i] - 'A';
        else                            // 뒷부분에 있어 뒤에서부터 접근
            answer += 'Z' - name[i] + 1;
        
        int next = i + 1;
        // 다음으로 A가 아닌 부분 찾기
        
        while(next < n && name[next] == 'A')
            next++;
        // 아직 next 인덱스가 범위 안에 있고 A일 경우 그냥 넘어감
        // while이므로 다음 next를 찾아준다.
        
        num = min(num, n + i - next + min(i, n - next));
        // 그냥 간 경우와 (총 크기 + (지금 위치 - 다음 A아닌 위치) + (다음 번에는 그냥 가는것이 빠른지 아니면 뒤로 가는 것이 빠른지 선택))
        
    }
    
    answer += num;
    // 그 결과 나온 제일 작은 min을 더해준다.

    
    return answer;
}




// #include <string>
// #include <vector>

// using namespace std;

// int solution(string name) {
//     int answer = 0;
//     int idx = 0;
    
//     string st = "";
//     for(int i=0;i<name.size();i++){
//         st += "A";
//     }
    
//     while(st != name){
//         // 같아지면 끝내기
//         int next = 0;
//         int left = 0;
//         int right = 0;
        
//         for(int i=0;i<name.size();i++){
//             if(idx + i < name.size())
//                 right = idx + i;
//             else        // idx + i 가 name 길이 보다 크면
//                 right = idx + i - name.size();
//                         // right를 idx + i - name.size()로 해준다.
            
//             if(idx - i >= 0)        // idx - i가 양수이면
//                 left = idx - i;     // left에 넣어주고
//             else                  // 음수이면, name.size()를 더해서 양수로 left에 넣어줌
//                 left = idx - i + name.size();
            
//             if(st[right] != name[right])
//                 next = right;
//             // st의 right와 name의 right가 다를 경우 next에 right를 넣어줌
//             else if(st[left] != name[left])
//                 next = left;
//             // right가 같은 데 left가 다르면 next에 left를 넣어줌
//             else
//                 continue;
//             // 둘다 같으면 continue
            
//             // 즉 오른쪽의 이동이 빠르면, next를 오른쪽에 저장하고
//             // 왼쪽의 이동이 빠르면 next를 왼쪽에 저장한다.
            
//             answer += i;
//             // i만큼 즉 이동한 만큼을 더해주고
//             answer += min(name[next] - 'A', 'Z' - name[next] + 1);
//             st[next] = name[next];
//             break;
//             // answerd에 i를 더해주고, 이동하는 것 중 최소를 더해준다.
//             // 그리고, name[next]를 st[next]에 넣어주고, break
//         }
//         idx = next;
//         // next를 idx에 넣어줌
//     }
    
    
    
//     return answer;
// }












