SELECT B.ANIMAL_ID, B.NAME
FROM ANIMAL_INS A
RIGHT JOIN ANIMAL_OUTS B
ON A.ANIMAL_ID = B.ANIMAL_ID
WHERE A.DATETIME IS NULL AND B.DATETIME IS NOT NULL
ORDER BY A.ANIMAL_ID

# 왼쪽 원에는 없고, 오른쪽 원에는 있는 것을 찾아야 하므로 right join

# SELECT B.ANIMAL_ID, B.NAME
# FROM ANIMAL_INS A
# RIGHT JOIN ANIMAL_OUTS B
# ON A.ANIMAL_ID = B.ANIMAL_ID
# WHERE A.DATETIME IS NULL
# ORDER BY B.ANIMAL_ID


# # SELECT B.ANIMAL_ID, B.NAME
# # FROM ANIMAL_INS A
# #     RIGHT JOIN ANIMAL_OUTS B
# # ON A.ANIMAL_ID = B.ANIMAL_ID
# # WHERE A.ANIMAL_ID IS NULL

# # -- OUT은 있는데 IN은 없는 것이므로,
# # -- RIGHT JOIN을 하여 오른쪽을 기준으로 오른쪽이 있으면 넣고
# # -- 왼쪽이 없으면 NULL로 넣는다.
# # -- 여기서 B가 있으면 들어가므로 A가 NULL인 경우가 존재하는데 이를 찾아주면 된다.
