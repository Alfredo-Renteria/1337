/*
* Alfredo Renteria
* Leetcode SQL Level 1
* String Processing Functions
*/

/*
1667. Fix Names in a Table

Table: Users
+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| user_id        | int     |
| name           | varchar |
+----------------+---------+
user_id is the primary key for this table.
This table contains the ID and the name of the user. The name consists of only lowercase and uppercase characters.
 
Write an SQL query to fix the names so that only the first character is uppercase and the rest are lowercase.
Return the result table ordered by user_id.
The query result format is in the following example
*/
-- Method 1: LEFT() & RIGHT()
SELECT user_id, CONCAT(UPPER(LEFT(name, 1)), LOWER(RIGHT(name, LENGTH(name)-1))) AS name
FROM Users
ORDER BY user_id;

-- Method 2: SUBSTR()
SELECT user_id, CONCAT(UPPER(SUBSTR(name, 1, 1)), LOWER(SUBSTR(name, 2))) AS name
FROM Users
ORDER BY user_id;

/*
1484. Group Sold Products By The Date

Table Activities:
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| sell_date   | date    |
| product     | varchar |
+-------------+---------+
There is no primary key for this table, it may contain duplicates.
Each row of this table contains the product name and the date it was sold in a market.
 
Write an SQL query to find for each date the number of different products sold and their names.
The sold products names for each date should be sorted lexicographically.
Return the result table ordered by sell_date.
The query result format is in the following example.
*/

SELECT sell_date, COUNT(DISTINCT product) AS num_sold, GROUP_CONCAT(DISTINCT product) AS products
FROM Activities 
GROUP BY sell_date;

/*
1527. Patients With a Condition

Table: Patients
+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| patient_id   | int     |
| patient_name | varchar |
| conditions   | varchar |
+--------------+---------+
patient_id is the primary key for this table.
'conditions' contains 0 or more code separated by spaces. 
This table contains information of the patients in the hospital.
 

Write an SQL query to report the patient_id, patient_name and conditions of the patients who have Type I Diabetes. Type I Diabetes always starts with DIAB1 prefix.
Return the result table in any order.
The query result format is in the following example.
*/
-- Method 1: REGEXP
SELECT *
FROM Patients
WHERE conditions REGEXP '^DIAB1|.*\\sDIAB1';

-- Method 2: RLIKE
SELECT *
FROM Patients
WHERE conditions RLIKE '^DIAB1|.*\\sDIAB1';

-- Method 3: REGEXP_LIKE
SELECT *
FROM Patients
WHERE REGEXP_LIKE(conditions, '^DIAB1|.*\\sDIAB1');

-- Method 4: LIKE
SELECT *
FROM Patients
WHERE conditions LIKE 'DIAB1%' 
    OR conditions LIKE '% DIAB1%';