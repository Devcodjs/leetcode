# Write your MySQL query statement below
select s.student_id , s.student_name , e.subject_name , count(t.student_id) as attended_exams
from Students s
cross join Subjects e
left join Examinations t on t.student_id = s.student_id and t.subject_name = e.subject_name
group by s.student_id , s.student_name, e.subject_name
order by s.student_id , e.subject_name;