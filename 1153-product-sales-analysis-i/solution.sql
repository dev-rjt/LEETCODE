# Write your MySQL query statement below
SELECT Product.product_name,Sales.year,Sales.price FROM Product RIGHT JOIN Sales ON SALES.product_Id = Product.product_id
