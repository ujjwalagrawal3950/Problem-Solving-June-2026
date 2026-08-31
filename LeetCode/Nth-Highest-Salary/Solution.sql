1CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
2BEGIN
3  RETURN (
4      Select Max(salary)
5      from (
6        Select 
7            salary, Dense_Rank() Over
8                    (order by salary desc) as rnk 
9        from Employee
10      ) as temp
11      Where rnk = N
12  );
13END