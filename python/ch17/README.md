https://pr4e.dr-chuck.com/tsugi/mod/sql-intro/index.php?PHPSESSID=c2f42b290a75aacfca3417af75916559


execute below
    python roster.py
    # and in SQL
    SELECT hex(User.name || Course.title || Member.role ) AS X FROM 
    User JOIN Member JOIN Course 
    ON User.id = Member.user_id AND Member.course_id = Course.id
    ORDER BY X
