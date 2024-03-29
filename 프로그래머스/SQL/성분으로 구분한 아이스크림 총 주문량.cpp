SELECT INGREDIENT_TYPE, SUM(A.TOTAL_ORDER) AS TOTAL_ORDER
# 밑에서 group by 로 이미 ingredient에 대해 그룹시켜 줬기에
# 그냥 sum으로 total_order를 하면 된다.
FROM FIRST_HALF A
JOIN ICECREAM_INFO B
ON A.FLAVOR = B.FLAVOR
GROUP BY B.INGREDIENT_TYPE
ORDER BY A.TOTAL_ORDER

# SELECT B.INGREDIENT_TYPE, SUM(A.TOTAL_ORDER) AS TOTAL_ORDER
# FROM FIRST_HALF A
# JOIN ICECREAM_INFO B
# ON A.FLAVOR = B.FLAVOR
# GROUP BY B.INGREDIENT_TYPE
# ORDER BY A.TOTAL_ORDER
