First of all, you should probably not put any slots in QThreads. QThreads aren't really meant to be derived from other than by reimplementing the run method and private methods (not signals!).

A QThread is conceptually a thread controller, not a thread itself. In most cases you should deal with QObjects. Start a thread, then move the object instance to that thread. That's the only way you'll get slots working correctly in the thread. Moving the thread instance (it is QObject-derived!) to the thread is a hack and bad style. Don't do that in spite of uninformed forum posts telling otherwise.

As to the rest of your question: a signal-slot call does not have to locate anything nor validate much. The "location" and "validation" is done when the connection is established. The main steps done at the time of the call are:

   1. Locking a signal-slot mutex from a pool.

   2. Iterating through the connection list.

   3. Performing the calls using either direct or queued calls.

## Common Cost

Any signal-slot call always starts as a direct call in the signal's implementation generated by moc. An array of pointers-to-arguments of the signal is constructed on the stack. The arguments are not copied.

The signal then calls QMetaObject::activate, where the connection list mutex is acquired, and the list of connected slots is iterated, placing the call for each slot.

## Direct Connections

Not much is done there, the slot is called by either directly calling QObject::qt_static_metacall obtained at the time the connection was established, or QObject::qt_metacall if the QMetaObject::connect was used to setup the connection. The latter allows dynamic creation of signals and slots.

## Queued Connections

The arguments have to marshalled and copied, since the call has to be stored in an event queue and the signal must return. This is done by allocating an array of pointers to copies, and copy-consting each argument on the heap. The code to do that is really no-frills plain old C.

The queuing of the call is done within queued_activate. This is where the copy-construction is done.

The overhead of a queued call is always at least one heap allocation of QMetaCallEvent. If the call has any arguments, then a pointers-to-arguments array is allocated, and an extra allocation is done for each argument. For a call with n arguments, the cost given as a C expression is (n ? 2+n : 1) allocations. A return value for blocking calls is counter as an argument. Arguably, this aspect of Qt could be optimized down to one allocation for everything, but in real life it'd only matter if you're calling trivial methods.