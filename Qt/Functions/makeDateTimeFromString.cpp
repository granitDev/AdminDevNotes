// takes any string where the first part of the string is formatted yyyy-MM-dd_HH:mm:ss and returns date and time
QDateTime SystemLogs::getDateTime(QString &datetime)
{
    int val1, val2, val3;
    QString string;
    QDateTime dateTime;

    for (int iter = 0; iter < 4; ++iter) string += datetime[iter]; // year
    val1 = string.toInt(); string.clear();
    for (int iter = 5; iter < 7; ++iter) string += datetime[iter]; // month
    val2 = string.toInt(); string.clear();
    for (int iter = 8; iter < 10; ++iter) string += datetime[iter]; // day
    val3 = string.toInt(); string.clear();
    dateTime.setDate(QDate(val1,val2,val3));

    for (int iter = 11; iter < 13; ++iter) string += datetime[iter]; // hour
    val1 = string.toInt(); string.clear();
    for (int iter = 14; iter < 16; ++iter) string += datetime[iter]; // minute
    val2 = string.toInt(); string.clear();
    for (int iter = 17; iter < 19; ++iter) string += datetime[iter]; // second
    val3 = string.toInt(); string.clear();
    dateTime.setTime(QTime(val1,val2,val3));

    return dateTime;
}