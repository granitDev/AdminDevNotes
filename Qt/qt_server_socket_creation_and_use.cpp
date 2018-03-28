class yourClass
{
	//This sets up a server, and a connection to call the function that is suppose to act once there is a connection
    visServer = new QTcpServer;
        connect(visServer, SIGNAL(newConnection()), this, SLOT(visConnection()));
        if(!visServer->listen(QHostAddress::Any, 5040)) qDebug() << "VisServer could NOT start";
        else qDebug() << "VisServer started!";
}

void ControllerDVR::visConnection()
{
    qDebug() << "New Connection...";

	//creates a socket and sends a message over it
    QTcpSocket *pySocket = visServer->nextPendingConnection();
    pySocket->write("Hello PyScript!");
    pySocket->flush();

	//listens for data and prints it to debug consol
    QByteArray data;
    while (true)
    {
        QByteArray tmp = pySocket->readAll();
        data += tmp;

        if(tmp.isEmpty() && !pySocket->waitForReadyRead()) break;
    }
    qDebug() << "Response: " << data.constData();
    pySocket->close();
}