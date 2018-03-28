
/*this is in your header file*/
QMap<QString, QCheckBox*> mCheckBoxes;


/*this is in your source file*/
void YourClassHere::createCheckBoxes()
{
    /*listofNames is your list of names that's used to generate checkboxes, be it vector, or map or whatever
	this listofNames needs to either be on the heap, a static object, or in the header file*/

    for (int i=0; i != listofStrings.length(); ++i)
    {
        QString name = (listofStrings[i]);

        if(!mCheckBoxes.contains(name))
        {
            QCheckBox* box = new QCheckBox;

            ui->QFormLayout->addRow(box);
            box->setText(name); box->setCheckable(true);

            mCheckBoxes.insert(name, box);
        }
    }
}