# Write your MySQL query statement below
-- select id 
-- from weather w1
-- where exists (select * from weather w2 
-- where DATEDIFF(w1.recordDate, w2.recordDate) = 1 and w1.temperature > w2.temperature)
select w1.id from weather w1
join weather w2
on DATEDIFF(w1.recordDate, w2.recordDate) = 1 and w1.temperature > w2.temperature 