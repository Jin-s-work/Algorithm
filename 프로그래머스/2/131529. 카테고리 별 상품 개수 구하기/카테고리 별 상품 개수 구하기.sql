# SELECT LEFT(PRODUCT_CODE, 2) AS CATEGORY, COUNT(*) AS PRODUCTS
# FROM PRODUCT
# GROUP BY LEFT(PRODUCT_CODE, 2)

# # SELECT LEFT(PRODUCT_CODE, 2) AS CATEGORY, COUNT(*) AS PRODUCTS
# # FROM PRODUCT
# # GROUP BY LEFT(PRODUCT_CODE, 2)

# # 아님아님
# # CASE WHEN PRODUCT_ID = 1 or PRODUCT_ID = 2 THEN "A1" ELSE CASE WHEN PRODUCT_ID = 3 or PRODUCT_ID = 4 or PRODUCT_ID = 5 THEN "C3" ELSE "K1" END AS CATEGORY,


SELECT LEFT(PRODUCT_CODE, 2) AS CATEGORY, COUNT(*) AS PRODUCTS
FROM PRODUCT
GROUP BY LEFT(PRODUCT_CODE, 2)
ORDER BY PRODUCT_CODE












