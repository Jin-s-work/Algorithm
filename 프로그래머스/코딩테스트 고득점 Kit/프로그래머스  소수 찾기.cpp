#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool sosu(int n){
    if(n < 2)
        return false;
    // 처음 할때 이것을 빠뜨렸는데 이게 잘못 된거 같음..
    for(int i=2;i*i<=n;i++){
        if(n % i == 0)
            return false;
    }   // 에라토스테네스의 체
    
    return true;
}

int solution(string numbers) {
    int answer = 0;
    
    vector<int>v;
    vector<char>ch;
    for(int i=0;i<numbers.size();i++){
        ch.push_back(numbers[i]);
    }   // 일단 문자열로 넣어야 숫자 만들수 있다. 그래서 char 형으로 넣어줌
    
    // 정렬을 해야 next_permutation 사용 가능
    sort(ch.begin(), ch.end());
    do{
        string st = "";
        for(int i=0;i<ch.size();i++){
            st.push_back(ch[i]);
            v.push_back(stoi(st));
        }
        // st에는 string으로 입력하고 v 벡터에는 그것을 int로 바꾸어 넣어준다.
        
    }while(next_permutation(ch.begin(), ch.end()));
    // 그러면 v에 모든 가능한 숫자들이 생김
    
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    // 중복제거하는 알고리즘.. 까먹고 있엇다..
    
    for(int i=0;i<v.size();i++){
        if(sosu(v[i]))
            answer++;
    }
    
    
    return answer;
}

// #include <string>
// #include <vector>
// #include <cmath>
// #include <algorithm>

// using namespace std;

// bool isPrime(int num){
//     if(num < 2)
//         return false;
    
//     for(int i=2;i*i<=num;i++){
//         if(num % i == 0)
//             return false;
//     }
//     return true;
// }

// int solution(string numbers) {
//     int answer = 0;
    
//     vector<char>ch;
//     vector<int>v;
    
//     for(int i=0;i<numbers.size();i++){
//         ch.push_back(numbers[i]);
//     }
    
//     sort(ch.begin(), ch.end());
    
//     do{
//         string st = "";
//         for(int i=0;i<ch.size();i++){
//             st.push_back(ch[i]);
//             v.push_back(stoi(st));
//             // string인 st에 ch[i]를 각각 넣어주고,
//             // 이러한 각각의 st를 int로 바꾸어서 v에 넣어준다. 각각씩
//         }
//     }while(next_permutation(ch.begin(), ch.end()));
//     // ch가 순열로 도는 동안
    
//     sort(v.begin(), v.end());
//     v.erase(unique(v.begin(), v.end()), v.end());
//     // v의 중복을 제거해준다. (여기서 정렬을 꼭 해야됨, 왜냐하면 붙어있어야 지워줌)
    
//     for(int i=0;i<v.size();i++){
//         if(isPrime(v[i]))
//             answer++;
//     }
    
    
    
//     return answer;
// }















