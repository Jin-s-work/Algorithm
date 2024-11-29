
from itertools import combinations
def solution(number, k):
    answer = ''
    
    st = []
    for num in number:
        while st and st[-1] < num and k > 0:
            st.pop()
            k -= 1
        st.append(num)
    
    if k > 0:
        st = st[:-k]
        
    return "".join(st)
    
    
    
    
    
