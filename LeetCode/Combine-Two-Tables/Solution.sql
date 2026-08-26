1# Write your MySQL query statement below
2Select p.firstName, p.lastName, a.city, a.state from Person p
3Left Join Address a
4On p.personId = a.personId