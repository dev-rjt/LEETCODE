# Write your MySQL query statement below

SELECT A.id FROM Weather A JOIN Weather B ON DATEDIFF(A.recorddate,B.recorddate) = 1 WHERE A.temperature> B.temperature
