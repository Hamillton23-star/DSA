# Write your MySQL query statement below
SELECT  query_name,ROUND(AVG(rating*1.0 /position),2) as quality, 
ROUND( 100*COUNT(CASE WHEN rating<3 THEN  1 END)/COUNT(*), 2 ) as poor_query_percentage 
 FROM Queries  group by query_name ;