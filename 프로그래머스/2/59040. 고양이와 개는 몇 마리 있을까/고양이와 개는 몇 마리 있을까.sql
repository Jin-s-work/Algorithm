# SELECT ANIMAL_TYPE, COUNT(*) AS count
# FROM ANIMAL_INS
# GROUP BY ANIMAL_TYPE
# ORDER BY ANIMAL_TYPE

# # SELECT ANIMAL_TYPE, COUNT(ANIMAL_TYPE) AS COUNT
# # FROM ANIMAL_INS
# # GROUP BY ANIMAL_TYPE
# # ORDER BY ANIMAL_TYPE

# # # SELECT ANIMAL_TYPE, COUNT(ANIMAL_TYPE) AS COUNT
# # # FROM ANIMAL_INS
# # # GROUP BY ANIMAL_TYPE
# # # ORDER BY ANIMAL_TYPE
# # -- 고양이가 어차피 먼저 이므로 오름차순으로 해주면 된다.

SELECT ANIMAL_TYPE, COUNT(ANIMAL_TYPE) AS count
FROM ANIMAL_INS
GROUP BY ANIMAL_TYPE
ORDER BY ANIMAL_TYPE









