// if you don't need much interaction do this
// this will also give you standard out to the QtCreator debug terminal
// and if you make an int = to it, it will give you the exit code
// below are three examples of usage that all work
QPRocess::execute(file, args); // 1
qDebug() << QPRocess::execute(file, args); // 2
int code = QPRocess::execute(file, args); // 3

// run external python script
QPRocess::execute("python file/location/of/script.py");
// if some asshole puts spaces in the path
QPRocess::execute("python \"path/with damn/set of spaces/script.py\"");


//////////////////////////////////////////////////////////////////////
// This is more involved but gives a lot more control
// make sure "this" is provided to the QProcess() so that it has a parent
// which will make the memory clean up automatic
QProcess *process = new QProcess(this);
QStringList optoinalArgs; optional << "some args";
process->start("path/to/your/script.run", optionalArgs);
process->waitForFinished();

// read from standard in
connect(&process, &QProcess::readyReadStandardOutput, [&qprocess](){ qDebug() << process.readAll(); });