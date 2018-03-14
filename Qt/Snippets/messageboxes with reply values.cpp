// there are a host of QMessageBox::<value> you can chose from that
// all return their respective QMessageBox::<value> to the
// QMessageBox::StandardButton object for you to use
QMessageBox::StandardButton reply;
reply = QMessageBox::question(this, "Window Title", "Your message here",
                              QMessageBox::Yes|QMessageBox::No);
if (reply == QMessageBox::Yes)
{
    // do something, Muttly!
}