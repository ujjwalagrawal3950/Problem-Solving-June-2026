1# Write your MySQL query statement below
2Select player_id , MIN(event_date) as first_login from Activity 
3Group by player_id