/*
* Alfredo Renteria
* Leetcode SQL Level 1
* Union & Select
*/

/*
608. TreeNode

Table: Tree
+-------------+------+
| Column Name | Type |
+-------------+------+
| id          | int  |
| p_id        | int  |
+-------------+------+
id is the primary key column for this table.
Each row of this table contains information about the id of a node and the id of its parent node in a tree.
The given structure is always a valid tree.

Each node in the tree can be one of three types:
"Leaf": if the node is a leaf node.
"Root": if the node is the root of the tree.
"Inner": If the node is neither a leaf node nor a root node.
Write an SQL query to report the type of each node in the tree.
Return the result table in any order.
*/
-- Method 1: UNION
SELECT id, 'Root' AS Type
FROM tree
WHERE p_id IS NULL
UNION
SELECT id, 'Leaf' AS Type
FROM tree
WHERE id NOT IN (SELECT DISTINCT p_id
                FROM tree
                WHERE p_id IS NOT NULL)
AND p_id IS NOT NULL
UNION
SELECT id, 'Inner' AS Type
FROM tree
WHERE id IN (SELECT DISTINCT p_id
            FROM tree
            WHERE p_id IS NOT NULL)
AND p_id IS NOT NULL
ORDER BY id;

-- Method 2: CASE
SELECT 
    id, 
    CASE
        WHEN tree.id = (SELECT atree.id FROM tree atree WHERE atree.p_id IS NULL) THEN 'Root'
        WHEN tree.id IN (SELECT atree.p_id FROM tree atree) THEN 'Inner'
        ELSE 'Leaf'
    END AS type
FROM tree
ORDER BY id;

/*
176. Second Highest Salary

Table: Employee
+-------------+------+
| Column Name | Type |
+-------------+------+
| id          | int  |
| salary      | int  |
+-------------+------+
id is the primary key column for this table.
Each row of this table contains information about the salary of an employee.
 
Write an SQL query to report the second highest salary from the Employee table. If there is no second highest salary, the query should report null.
*/
-- Method 1: MAX()
SELECT MAX(Salary) AS SecondHighestSalary
FROM Employee
WHERE Salary < (SELECT MAX(Salary) FROM Employee)