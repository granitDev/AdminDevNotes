// your QProcess needs to be a member variable

void Class::function()
{
    connect(&qprocess, &QProcess::readyReadStandardOutput, this, &Class::scriptOutput);
    connect(&qprocess, static_cast<void(QProcess::*)(int, QProcess::ExitStatus)>(&QProcess::finished),
            [=](){ do something });

    QStringList args;
    args << "/C" << "C:\\directory\\script.bat";
    qprocess.start("cmd", args);
}

void ControllerDVR::scriptOutput()
{
    QString output = qprocess.readAll();
    qDebug() << output;
    // the finished signal will never be emitted if this does not execute
    if(output == "Press any key to continue . . . ")
    {
        qprocess.write("\n"); // theoretically this can be anything, but we all hit "enter" dont' we?
        qDebug() << "Any key has been pressed..."; // optional, for irony's sake
    }
}