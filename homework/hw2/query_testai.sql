-- 1：参加了项目名为“SQL Project”的员工名字；
-- 2：在“Research Department”工作且工资低于3000元的员工名字和地址；
-- 3：没有参加项目编号为P1的项目的员工姓名；
-- 4：由张红领导的工作人员的姓名和所在部门的名字；
-- 5：至少参加了项目编号为P1和P2的项目的员工号；
-- 6：参加了全部项目的员工号码和姓名；
-- 7：员工平均工资低于3000元的部门名称；
-- 8：至少参与了3个项目且工作总时间不超过8小时的员工名字；
-- 9：每个部门的员工小时平均工资；

-- 1
select ENAME
from EMPLOYEE
join WORKS_ON on EMPLOYEE.ESSN = WORKS_ON.ESSN
join PROJECT on WORKS_ON.PNO = PROJECT.PNO
where PNAME = 'SQL Project';

