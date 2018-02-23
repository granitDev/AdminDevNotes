// there are a host of QMessageBox::<value> you can chose from that
// all return their respective QMessageBox::<value> to the
// QMessageBox::StandardButton object for you to use
QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Warning", "This will turn off 24Volts!\nAre you sure you want to do this?",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        sendIntMessage(SET_24V_STATUS,0);
    }