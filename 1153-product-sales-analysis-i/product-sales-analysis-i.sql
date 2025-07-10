# Write your MySQL query statement below
  SELECT p.product_name,e1.year,e1.price FROM Sales e1 INNER JOIN Product p ON e1.product_id=p.product_id ;