//convert date time to a string with custom format

QDateTime dateTime; //already set to some value of date and time
QString string =  getTimeNumber(dateTime.toString("yyyy-MM-dd_HH:mm:ss"));

//where the custom format can be formatted nearly anyway you like