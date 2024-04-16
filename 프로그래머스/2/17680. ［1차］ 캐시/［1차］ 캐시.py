def solution(cacheSize, cities):
    answer = 0
    
    cities = [c.upper() for c in cities]
    cache = []
    
    if cacheSize == 0:
        return len(cities) * 5
    else:
        for city in cities:
            if not city in cache:
                if len(cache) < cacheSize:
                    cache.append(city)
                    answer += 5
                    # 실행시간이 5이므로 캐시사이즈보다 아직 캐시가 작을 경우 넣어준다.
                else:
                    cache.pop(0)
                    cache.append(city)
                    answer += 5
                    # 캐시 사이즈보다 캐시가 클 경우 하나 없애주고 새로 넣는다.
                    # 또 실행시간이 5이므로 더해주기
            else:   # cache에 city가 있을 경우
                cache.pop(cache.index(city))
                cache.append(city)
                answer += 1
                # 시티를 cache에서 빼주고, city를 새로 넣는다.
                # Hit이므로 실행시간은 1 늘려준다.
    
    
    
    # 도시가 캐시 안에 없을 경우 (cache miss)
    # 캐시 크기와 cacheSize를 비교하고 캐시 크기가 작을 경우 그냥 현재 도시를 캐시 안에 넣어준 후 실행시간에 5를 더해준다. 
    # 캐시 크기가 클 경우 캐시에서 가장 오래된 값(인덱스 : 0)을 제거하고 현재 도시를 넣어준다. 그리고 실행시간에 5를 더해준다.
    # 도시가 캐시 안에 있을 경우 (cache hit)
    # 해당 도시를 캐시에서 제거하고, 다시 마지막 인덱스로 넣어준 후 실행시간에 1을 더한다. 

    
    
    
    return answer