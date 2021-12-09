
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool isPrime(int num){
    if(num < 2)
        return false;
    
    for(int i=2;i*i<=num;i++){
        if(num % i == 0)
            return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    
    vector<char>ch;
    vector<int>v;
    
    for(int i=0;i<numbers.size();i++){
        ch.push_back(numbers[i]);
    }
    
    sort(ch.begin(), ch.end());
    
    do{
        string st = "";
        for(int i=0;i<ch.size();i++){
            st.push_back(ch[i]);
            v.push_back(stoi(st));
            // string인 st에 ch[i]를 각각 넣어주고,
            // 이러한 각각의 st를 int로 바꾸어서 v에 넣어준다. 각각씩
        }
    }while(next_permutation(ch.begin(), ch.end()));
    // ch가 순열로 도는 동안
    
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    // v의 중복을 제거해준다. (여기서 정렬을 꼭 해야됨, 왜냐하면 붙어있어야 지워줌)
    
    for(int i=0;i<v.size();i++){
        if(isPrime(v[i]))
            answer++;
    }
    
    
    
    return answer;
}


// 위에는 머 보고 풀긴 했지만 이해해서 혼자 다시 풀어봄







// 전에 주석을 달아놓은 풀이

#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

bool isPrime(int num){
    if(num < 2)
        return false;
    
    for(int i=2;i*i<=num;i++){
        if(num % i == 0)
            return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    
    vector<char>v;
    vector<int>N;
    int n = numbers.size();
    
    for(int i=0;i<n;i++){
        v.push_back(numbers[i]);  // numbers string에 있는 것을 vector에 저장
    }
    sort(v.begin(), v.end()); // vector를 정렬한다. string이어도 가능
    
    do{
        string tmp = ""; // 빈 string tmp설정
        for(int i=0;i<v.size();i++){
            tmp.push_back(v[i]);    // v의 값들을 넣어준다.
            N.push_back(stoi(tmp)); // N은 int이므로 tmp의 값들을 stoi를 통해 넣어준다.
        }
    } while(next_permutation(v.begin(), v.end()));
    // 순열로 모두 해보기 보통 이런 form을 사용한다.
    
    sort(N.begin(), N.end());   // 이러한 N을 정렬해준다. erase unique를 해주려면 꼭 해줘야 한다.
    N.erase(unique(N.begin(), N.end()),N.end()); // 처음 부터 unique해주고 그 인덱스 부터 end까지를 지워준다.
    
    for(int i=0;i<N.size();i++){    // 이제 소수인지 확인해준다.
        if(isPrime(N[i]))
            answer++;   // 소수가 맞으면 하나씩 증가해준다.
    }
    
    return answer;
}
