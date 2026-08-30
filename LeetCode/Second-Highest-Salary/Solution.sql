1# Write your MySQL query statement below
2Select Max(salary) as SecondHighestSalary
3from Employee
4    Where salary < (Select Max(salary) from Employee)