-- 1) 参加了项目名为“SQL Project”的员工名字；
select ENAME
from EMPLOYEE
join WORKS_ON on EMPLOYEE.ESSN = WORKS_ON.ESSN
join PROJECT on WORKS_ON.PNO = PROJECT.PNO
where PNAME = 'SQL Project';

-- 2) 在“Research Department”工作且工资低于3000元的员工名字和地址；
select ENAME, ADDRESS
from EMPLOYEE
join DEPARTMENT on EMPLOYEE.DNO = DEPARTMENT.DNO
where DNAME = 'Research Department' and SALARY < 3000;

-- 3) 没有参加项目编号为P1的项目的员工姓名；
select ENAME
from EMPLOYEE
where ESSN not in (
    select ESSN
    from WORKS_ON
    where PNO = 'P1'
);

-- 4) 由张红领导的工作人员的姓名和所在部门的名字；
select ENAME, DNAME
from EMPLOYEE
join DEPARTMENT on EMPLOYEE.DNO = DEPARTMENT.DNO
where SUPERSSN in (
    select ESSN
    from EMPLOYEE
    where ENAME = '张红'
);

-- 5) 至少参加了项目编号为P1和P2的项目的员工号；
(select distinct ESSN
from WORKS_ON
where PNO = 'P1')
intersect
(select distinct ESSN
from WORKS_ON
where PNO = 'P2');

-- 6) 参加了全部项目的员工号码和姓名；
select ESSN, ENAME
from EMPLOYEE
where ESSN in (
    select ESSN
    from WORKS_ON
    group by ESSN
    having count(*) = (
        select count(*)
        from PROJECT
    )
);

-- 7) 员工平均工资低于3000元的部门名称；
select DNAME
from DEPARTMENT
where DNO in (
    select DNO
    from EMPLOYEE
    group by DNO
    having avg(SALARY) < 3000
);

-- 8) 至少参与了3个项目且工作总时间不超过8小时的员工名字；
select ENAME
from EMPLOYEE
join WORKS_ON on EMPLOYEE.ESSN = WORKS_ON.ESSN
group by ENAME
having count(*) >= 3 and sum(HOURS) <= 8;

-- 9) 每个部门的员工小时平均工资；
select DNAME, avg(SALARY_PER_HOUR) as AVG_SALARY_PER_HOUR
from DEPARTMENT
join (
    select WORKS_ON.ESSN, DNO, SALARY/sum(HOURS) as SALARY_PER_HOUR
    from WORKS_ON
    join EMPLOYEE on WORKS_ON.ESSN = EMPLOYEE.ESSN
    group by WORKS_ON.ESSN
) as EMPLOYEE_SALARY_PER_HOUR
on DEPARTMENT.DNO = EMPLOYEE_SALARY_PER_HOUR.DNO
group by DNAME;