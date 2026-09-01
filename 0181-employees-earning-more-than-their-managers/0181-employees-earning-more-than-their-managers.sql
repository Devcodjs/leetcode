# Write your MySQL query statement below
select e.name as Employee 
from Employee e
join Employee s on e.managerId = s.id and e.salary >= s.salary 
