# Write your MySQL query statement below
SELECT A.project_id, ROUND(IFNULL(SUM(B.experience_years)/COUNT(*),0),2) AS average_years 
FROM Project AS A
LEFT JOIN Employee AS B ON A.employee_id = B.employee_id GROUP BY A.project_id
