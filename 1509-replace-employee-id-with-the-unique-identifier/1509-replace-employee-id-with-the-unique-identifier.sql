# Write your MySQL query statement below
select EmployeeUNI.unique_id, employees.name from EmployeeUNI
right join employees on employees.id = EmployeeUNI.id 