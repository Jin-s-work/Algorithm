# SELECT ANIMAL_ID, NAME, CASE WHEN SEX_UPON_INTAKE LIKE "%Neutered%" or SEX_UPON_INTAKE LIKE "%Spayed%" THEN 'O' ELSE 'X' END AS "중성화"
# FROM ANIMAL_INS
# ORDER BY ANIMAL_ID

# # SELECT ANIMAL_ID, NAME, 
# # CASE WHEN SEX_UPON_INTAKE LIKE '%Neutered%' OR SEX_UPON_INTAKE LIKE '%Spayed%'
# # THEN "O" 
# # ELSE "X" 
# # END AS "중성화"
# # FROM ANIMAL_INS
# # ORDER BY ANIMAL_ID

# # SELECT ANIMAL_ID, NAME,
# # CASE WHEN SEX_UPON_INTAKE LIKE "%Neutered%" or SEX_UPON_INTAKE LIKE "%Spayed%" 
# # THEN "O"
# # ELSE "X"
# # END AS "중성화"
# # FROM ANIMAL_INS

# # # case when 으로 하여 맞으면 then ~~ 아닐 경우 else ~~ 
# # # 표시하는 부분은 END AS로 한다.

SELECT ANIMAL_ID, NAME, 
(CASE WHEN SEX_UPON_INTAKE LIKE '%Neutered%' OR SEX_UPON_INTAKE LIKE '%Spayed%' THEN 'O' ELSE 'X' END) AS '중성화'
FROM ANIMAL_INS
ORDER BY ANIMAL_ID








