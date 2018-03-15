// make sure "this" is provided to the QProcess() so that it has a parent
// which will make the memory clean up automatic
QProcess *process = new QProcess(this);
process->start("path/to/your/script.run");
process->waitForFinished();