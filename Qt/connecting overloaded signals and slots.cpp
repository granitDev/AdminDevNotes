// source: https://stackoverflow.com/questions/16794695/connecting-overloaded-signals-and-slots-in-qt-5

//  From Qt 5.7, there are helper functions provided to select the desired overload
connect(object, qOverload<signalType>(&QClass::signal),
        this, &ThisClass::yourSlot);
        
// For Qt 5.6 and earlier, you need cast to the right type
connect(object, static_cast<void (QClass::*)(signalType)>(&QObjectType::signal),
        this, &ThisClass::yourSlot);
        
// This also works for older Qt 5.4
// using a lambda
  connect(test, QOverload<int>::of(&QSpinBox::valueChanged), [=](int val) {
            qDebug() << "GOT VALUE " << val;
            QThread::msleep(delay);
            qDebug() << "WOKE UP "; });

// using a member method
  connect(m_pValSpinBox, QOverload<int>::of(&ValidatedSpinBox::valueChanged), this, &Dialog::incrementSpinVal);