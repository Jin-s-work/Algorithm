SELECT MCDP_CD AS "진료과코드", COUNT(PT_NO) AS "5월예약건수"
FROM APPOINTMENT
WHERE YEAR(APNT_YMD) = 2022 and MONTH(APNT_YMD) = 5
GROUP BY MCDP_CD
ORDER BY COUNT(PT_NO), MCDP_CD

# SELECT MCDP_CD AS "진료과코드", COUNT(*) AS "5월예약건수"
# FROM APPOINTMENT
# WHERE YEAR(APNT_YMD) = 2022 and MONTH(APNT_YMD) = 5
# GROUP BY MCDP_CD
# ORDER BY COUNT(*), MCDP_CD
