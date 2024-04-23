1、在图书管理数据库中，有如下三个关系：
图书信息关系：B(B#, BNAME, AUTHOR, TYPE)，其中B#为图书编号，BNAME为书名，AUTHOR为作者，TYPE为类别；
学⽣信息关系：S(S#, SNAME, CLASS)，其中S#为学号，SNAME为学⽣姓名，CLASS为班级号；
借阅信息关系：L(S#, B#, DATE)，其中S#为借阅⼈学号，B#为被借阅图书编号，DATE为借阅⽇期。
使⽤关系代数回答以下问题：
（1）查询借阅了“《⻄游记》”这本书的学⽣的班级
（2）查询“201”班学⽣借阅图书的书名
（3）查询“⼩明”借过，但“⼩李”没有借过的图书的编号
（4）查询借阅过“《红楼梦》”这本书的总学⽣数

(1)
$$
\rm \Pi_{CLASS}\left(\left(\sigma_{BNAME=\text{``《西游记》''}}(B)\right)\bowtie L \bowtie S\right)
$$
(2)
$$
\rm \Pi_{BNAME}(\left(\sigma_{CLASS=\text{``201''}}(S)\right)\bowtie L\bowtie B)
$$
(3)
$$
\rm \Pi_{B\#}\left(\sigma_{SNAME=\text{``小明''}}(S\bowtie L)-\sigma_{SNAME=\text{``小李''}}(S\bowtie L)\right)
$$
(4)
$$
\rm {\cal G}_{count-distinct(S\#)}\left((\sigma_{BNAME=\text{``《红楼梦》''}}(B))\bowtie L\right)
$$

---

2、在学⽣成绩数据库中，有如下三个关系：
学⽣信息关系：S(S#, SNAME, D#)，其中S#为学号，SNAME为学⽣姓名，D#为所在系名；
学⽣成绩关系：SC(S#, C#, Grade)，其中S#为学号，C#为课程号，Grade为成绩；
系信息关系：D(D#, Addr)，其中D#为系名，Addr为所在地址
使⽤关系代数回答以下问题：
（1）查询“物理系”的全体学⽣
（2）查询“化学系”的全体学⽣的学号和姓名
（3）查询选修了“1002”课程但没有选修“1005”课程的学⽣
（4）查询既选修了“1002”课程的学⽣中选修了“1003”课程的学⽣姓名

(1)
$$
\rm \Pi_{S\#,\ SNAME}\left(\sigma_{D\#=\text{``物理系''}}(S)\right)
$$
(2)
$$
\rm \Pi_{S\#,\ SNAME}\left(\sigma_{D\#=\text{``化学系''}}(S)\right)
$$
(3)
$$
\rm \Pi_{S\#}\left(\sigma_{C\#=1002}(SC)-(\sigma_{C\#=1005}(SC)\right)
$$
(4)
$$
\rm \Pi_{SNAME}\left(\left(\sigma_{C\#=1002}(SC)\cap\sigma_{C\#=1005}(SC)\right)\bowtie S\right)
$$

---

3、在第2题学生成绩数据库中，若S关系中没有空值，SC关系中Grade值可能为空值，则使⽤关
系代数回答以下问题：
（1）查询选过课的学⽣的学号和姓名
（2）查询没选过课的学生学号和姓名

(1)
$$
\rm \Pi_{S.S\#,\ SNAME}(S\bowtie SC)
$$
(2)
$$
\rm \Pi_{S.S\#,\ SNAME}(S)-\Pi_{S.S\#,\ SNAME}(S\bowtie SC)
$$