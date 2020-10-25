#ifndef SIMPLESWITCH_H
#define SIMPLESWITCH_H

#include "../build-MainWindowProcess-Desktop_Qt_5_15_1_MSVC2015_64bit-Release/rep_simpleswitch_source.h"

//This is the object to share
//We do not need nothing but constructor and distructor because we manipulate the property defined in the simpleswitch.rep
class SimpleSwitch : public SimpleSwitchSimpleSource
{
    Q_OBJECT

public:
    SimpleSwitch(QObject *parent = nullptr);
    ~SimpleSwitch();
};

#endif // SIMPLESWITCH_H
