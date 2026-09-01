# Write your MySQL query statement below
select e.user_id , round(avg(if(s.action = 'confirmed' , 1 , 0)) , 2) as confirmation_rate
from Signups e
left join Confirmations s on e.user_id = s.user_id
group by e.user_id;

