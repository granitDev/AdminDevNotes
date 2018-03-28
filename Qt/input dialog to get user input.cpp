bool ok;
QString strName = QInputDialog::getText(this,
                                         tr("Window Title Here"),
                                         tr("Text Box Title here"),
                                         QLineEdit::Normal,
                                         tr("Text box default text here"),
                                         &ok);