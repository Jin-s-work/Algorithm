
SELECT SUM(A.SCORE) AS SCORE, B.EMP_NO, B.EMP_NAME, B.POSITION, B.EMAIL
FROM HR_GRADE A
JOIN HR_EMPLOYEES B
ON A.EMP_NO = B.EMP_NO
GROUP BY A.EMP_NO
ORDER BY 1 DESC
LIMIT 1