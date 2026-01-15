const db = require('../database');

const gradePoints={
getGradeByStudent:function(username, callback){
return db.query("select course_name, credit_points, grade from course inner join grade on course.idcourse=grade.idcourse where username=?", [username], callback);
}
//addGradeByStudent:function(username, callback)

}

module.exports=gradePoints;