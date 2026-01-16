#ifndef GRADES_H
#define GRADES_H

#include <qjsonobject.h>

class Grades
{
public:
    QString course_name;
    int gredit_points;
    int grade;
    QString date;
    static Grades mapJson(const QJsonObject &json);
private:

};

#endif // GRADES_H
