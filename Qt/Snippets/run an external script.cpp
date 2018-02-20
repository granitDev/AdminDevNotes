QProcess *trackingProcess = new QProcess(this);
trackingProcess->start("program C:\\Director\\script.torun");

// if can be executed by double clicking  it
trackingProcess->start("C:\\Director\\script.torun");