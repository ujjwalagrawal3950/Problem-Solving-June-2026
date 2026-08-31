1# Write your MySQL query statement below
2Select c.name as Customers From Customers c
3Left Join Orders o
4    On c.id = o.customerId
5    Where o.id IS NULL