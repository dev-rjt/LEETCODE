# Write your MySQL query statement below
SELECT A.product_id,ROUND(IFNULL(SUM(B.units*A.price)/SUM(B.units),0),2) AS average_price FROM Prices AS A
LEFT JOIN UnitsSold AS B ON A.product_id = B.product_id AND B.purchase_date BETWEEN
A.start_date and A.end_date GROUP BY A.product_id




# keep in mind use if null
