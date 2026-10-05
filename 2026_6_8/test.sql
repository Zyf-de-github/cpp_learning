select 
    product_category,
    sum(amount) as total_amount,
    count(order_id) as order_count,
    round(avg(amount),2) as avg_amount
from orders
where order_date >= '2024-01-01' and order_date <= '2024-02-15'
group by product_category
having total_amount>=400 and order_count>=2
order by total_amount desc;


create table students(
    student_id int primary key auto_increment,
    student_name varchar(50) not null,
    student_age int check(student_age>=15 and student_age<=30),
    student_email varchar(100) unique,
    enroll_date date default current_date
);


alter table students rename to student;
alter table students add student_phone varchar(20);
alter table students add student_age int check(student_age>=18 and student_age<=35);
alter table students drop collumn enroll_date,student_age;

drop table students;
truncate table students;
delete from students;

create table test_table(id int primary key auto_increment);
insert into test_table values(),(),();
truncate table test_table;

insert into students(student_name,student_age,student_email,enroll_date) 
values
    ('张三',20,'zhangsan@test.com',default),
    ('李四',25,'lisi@test.com','2024-01-15'),
    ('王五',18,null,'2024-02-01');

update students set student_age=20 where student_name='王五';
update students set student_email='lisi_new@test.com' where student_name='李四';
update students set enroll_date ='2025-01-01' where student_age<21;

delete from students where student_age>24;
delete from students where student_email is null;
delete from students;

create user 'zhangsan'@'localhost' identified by 'pass123';
grant select,insert on test_db.* to 'zhangsan'@'localhost';
grant update on test_db.students to 'zhangsan'@'localhost';

revoke update on test_db.students from 'zhangsan'@'localhost';
revoke insert on test_db.* from 'zhangsan'@'localhost';
drop user 'zhangsan'@'localhost';



