SELECT A.ID, A.EMAIL, A.FIRST_NAME, A.LAST_NAME
FROM DEVELOPERS A
WHERE EXISTS(
SELECT 1 FROM SKILLCODES S
WHERE (S.CODE & A.SKILL_CODE != 0)
    AND ((S.NAME = 'Python') OR (S.NAME = 'C#'))
)
ORDER BY A.ID ASC;




# SELECT D.ID, D.EMAIL, D.FIRSTNAME, D.LASTNAME
# FROM DEVELOPERS D
# WHERE EXISTS (SELECT 1
# FROM SKILLCODES S
# WHERE (S.CODE & D.SKILL_CODE != 0)
# AND ((S.NAME = 'Python') OR (S.NAME = 'C#')))
# ORDER BY D.ID ASC;