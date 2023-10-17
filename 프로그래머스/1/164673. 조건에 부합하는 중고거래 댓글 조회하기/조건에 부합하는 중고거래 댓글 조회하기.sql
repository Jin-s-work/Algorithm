-- 코드를 입력하세요


# SELECT A.TITLE, A.BOARD_ID, B.REPLY_ID, B.WRITER_ID, B.CONTENTS, DATE_FORMAT(B.CREATED_DATE, '%Y-%M-%d')
# FROM USED_GOODS_BOARD A, USED_GOODS_REPLY B
# WHERE A.BOARD_ID = B.BOARD_ID AND A.CREATED_DATE LIKE '%2022-10%'
# ORDER BY B.CREATED_DATE, A.TITLE


SELECT b.title, b.board_id, r.reply_id, r.writer_id, r.contents,
       DATE_FORMAT(r.created_date, '%Y-%m-%d')
FROM used_goods_board b, used_goods_reply r
WHERE b.board_id = r.board_id AND b.created_date LIKE '%2022-10%'
ORDER BY r.created_date, b.title;