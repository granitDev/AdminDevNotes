connect(&qprocess, &QProcess::readyReadStandardOutput, [=](){ qDebug() << process.readAll(); });

QStringList args;
    args << "/C" << "C:\\directory\\script.bat";
    process.start("cmd", args);