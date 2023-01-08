/*
* Alfredo Renteria
* Leetcode SQL Level 1
* Select & Order
*/

/*
1873. Calculate Special Bonus

Table: Employees
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| employee_id | int     |
| name        | varchar |
| salary      | int     |
+-------------+---------+
employee_id is the primary key for this table.
Each row of this table indicates the employee ID, employee name, and salary.
 
Write an SQL query to calculate the bonus of each employee. The bonus of an employee is 100% of their salary if the ID of the employee is an odd number and the employee name does not start with the character 'M'. The bonus of an employee is 0 otherwise.
Return the result table ordered by employee_id.
The query result format is in the following example.
*/
-- Method 1
SELECT 
    employee_id,
    CASE
        WHEN employee_id % 2 <> 0 AND name NOT LIKE 'M%' THEN salary
        ELSE 0
    END
    AS bonus
FROM Employees
ORDER BY employee_id;

-- Method 2
SELECT
    employee_id,
    IF(employee_id % 2 != 0 AND name NOT LIKE 'M%', salary, 0) AS bonus
FROM Employees 
ORDER BY employee_id

/*
627. Swap Salary

Table: Salary
+-------------+----------+
| Column Name | Type     |
+-------------+----------+
| id          | int      |
| name        | varchar  |
| sex         | ENUM     |
| salary      | int      |
+-------------+----------+
id is the primary key for this table.
The sex column is ENUM value of type ('m', 'f').
The table contains information about an employee.
 
Write an SQL query to swap all 'f' and 'm' values (i.e., change all 'f' values to 'm' and vice versa) with a single update statement and no intermediate temporary tables.
Note that you must write a single update statement, do not write any select statement for this problem.
The query result format is in the following example.
*/
-- Method 1
UPDATE Salary
SET sex = 
    IF(sex = 'm', 'f', 'm'); 

--Method 2
UPDATE Salary
SET sex = 
    CASE sex
        WHEN 'm' THEN 'f'
        ELSE 'm'
    END;

/*
196. Delete Duplicate Emails

Table: Person
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| email       | varchar |
+-------------+---------+
id is the primary key column for this table.
Each row of this table contains an email. The emails will not contain uppercase letters.
 

Write an SQL query to delete all the duplicate emails, keeping only one unique email with the smallest id. Note that you are supposed to write a DELETE statement and not a SELECT one.
After running your script, the answer shown is the Person table. The driver will first compile and run your piece of code and then show the Person table. The final order of the Person table does not matter.
The query result format is in the following example.
*/
-- Method 1
DELETE p1 FROM Person p1, Person p2
WHERE p1.Email = p2.Email 
    AND p1.Id > p2.Id;

-- Method 2
DELETE FROM person
WHERE id NOT IN (SELECT id
                FROM (SELECT Min(id) AS id
                     FROM   person
                     GROUP  BY email) AS p); 