# Write your MySQL query statement below
select p.product_id ,coalesce(round(sum(p.price * e.units ) / sum(e.units) , 2) , 0) as average_price
from Prices p
left join UnitsSold e on p.product_id = e.product_id and e.purchase_date between p.start_date and p.end_date
group by p.product_id
