const db = require('../database');

const gradePoints={
getGradeByStudent:function(username, callback){
return db.query("select course_name, credit_points, grade, DATE_FORMAT(drade_date,'%d.%m.%y') AS grade_date from course inner join grade on course.idcourse=grade.idcourse where username=?", [username], callback);
}
//addGradeByStudent:function(username, callback)

}

module.exports=gradePoints;