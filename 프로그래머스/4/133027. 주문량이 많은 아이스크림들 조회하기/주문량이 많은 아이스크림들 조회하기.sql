
SELECT B.FLAVOR
FROM FIRST_HALF A 
JOIN JULY B
ON A.FLAVOR = B.FLAVOR
GROUP BY FLAVOR
ORDER BY SUM(B.TOTAL_ORDER) + SUM(A.TOTAL_ORDER) DESC
LIMIT 3


# SELECT B.FLAVOR
# FROM FIRST_HALF A
# JOIN JULY B
# ON A.FLAVOR = B.FLAVOR
# GROUP BY FLAVOR
# ORDER BY SUM(B.TOTAL_ORDER) + SUM(A.TOTAL_ORDER) DESC
# LIMIT 3