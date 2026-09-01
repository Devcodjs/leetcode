# Write your MySQL query statement below
select e.name as Customers from Customers e
left join Orders o on o.customerId = e.id
where o.customerId is null