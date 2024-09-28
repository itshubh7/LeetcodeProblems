# Write your MySQL query statement below
select product_name, year, price from Product inner join Sales on Sales.product_id = Product.product_id