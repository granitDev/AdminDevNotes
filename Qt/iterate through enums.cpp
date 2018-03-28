/* put this in the file header that has the enum you want to parse
This only works if the class inherits QObject*/

//this needs to be placed INSIDE the class curly braces
//Q_ENUMS is a macro
Q_ENUMS(nameofEnum)




/*in your source file*/
const QMetaObject &mo = SomeClass::staticMetaObject;
    int index = mo.indexOfEnumerator("nameofEnum");
    QMetaEnum metaEnumName = mo.enumerator(index);
    for(int i = 0; i < metaEnumName.keyCount(); ++i)
    {
        //anything you like
    }



