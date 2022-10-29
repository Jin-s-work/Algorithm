SELECT DATETIME AS "시간"
FROM ANIMAL_INS
ORDER BY DATETIME DESC
LIMIT 1

# 이렇게 하는게 훨씬 나은듯..
# SELECT MAX(DATETIME)
# FROM ANIMAL_INS

# # 가장 최근에 올 경우 MAX이다. 날짜가 가까울수록 클 수 밖에..

# # -- 코드를 입력하세요
# # SELECT MAX(DATETIME)
# # FROM ANIMAL_INS
