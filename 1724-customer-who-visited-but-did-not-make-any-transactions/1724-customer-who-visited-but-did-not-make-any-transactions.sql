# Write your MySQL query statement below
select customer_id, count(customer_id ) as count_no_trans
from visits
where not exists(select Transactions.* from Transactions where visits.visit_id = Transactions.visit_id) 
group by customer_id;