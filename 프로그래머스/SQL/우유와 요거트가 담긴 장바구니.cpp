SELECT DISTINCT A.CART_ID  # 같은 경우를 위해 중복을 제거해준다.
FROM CART_PRODUCTS A, CART_PRODUCTS B
WHERE A.CART_ID = B.CART_ID and (A.NAME = "Yogurt" and B.NAME = "Milk")
ORDER BY A.CART_ID

# SELECT DISTINCT A.CART_ID
# FROM CART_PRODUCTS A, CART_PRODUCTS B
# WHERE  A.CART_ID = B.CART_ID AND (A.NAME = "Milk" and B.NAME = "Yogurt")
# ORDER BY A.CART_ID

# # A, B가 둘다 나올 수 있으므로 맨 위에서도 DISTINCT를 통해 중복을 제거한다.
# # A와 B가 같고 여기서 각각 들어가있을 때
# # SELF JOIN을 사용하는 것..  한 개의 테이블을 이용해 두개로 생각해서 각각 찾아주기
