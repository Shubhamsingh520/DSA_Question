CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
    SELECT salary
    FROM (
        SELECT salary, DENSE_RANK() OVER (ORDER BY Salary DESC) As ranking
        FROM Employee
    )   As ranked_salaries
    WHERE ranking = N
    LIMIT 1


  );
END