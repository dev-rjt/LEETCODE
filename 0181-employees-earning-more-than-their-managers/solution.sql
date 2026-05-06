# Write your MySQL query statement below
SELECT A.name as Employee FROM Employee A JOIN Employee B ON A.managerId = B.id AND A.salary > B.salary
