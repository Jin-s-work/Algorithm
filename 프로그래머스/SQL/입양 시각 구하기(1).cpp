SELECT HOUR(DATETIME) AS HOUR, COUNT(HOUR(DATETIME)) AS COUNT
FROM ANIMAL_OUTS
WHERE HOUR(DATETIME) >= 9 and HOUR(DATETIME) < 20
GROUP BY HOUR(DATETIME)
ORDER BY HOUR(DATETIME)

# SELECT HOUR(DATETIME) AS "HOUR", COUNT(HOUR(DATETIME)) AS COUNT
# FROM ANIMAL_OUTS
# WHERE HOUR(DATETIME) >= 9 and HOUR(DATETIME) < 20
# GROUP BY HOUR(DATETIME)
# ORDER BY HOUR(DATETIME)

# # SELECT HOUR(DATETIME), COUNT(*) AS COUNT
# # FROM ANIMAL_OUTS
# # WHERE HOUR(DATETIME) >= 9 and HOUR(DATETIME) < 20
# # GROUP BY HOUR(DATETIME)
# # ORDER BY HOUR(DATETIME)

# # -- GROUP BY 는 약간 출력형식을 정해주는 거 같기도..?
# # -- order by는 정렬하는 느낌
# # -- 그냥 HOUR를 사용하여 시간만 뺄수가 있다..
