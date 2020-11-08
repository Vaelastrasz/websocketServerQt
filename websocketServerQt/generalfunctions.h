#ifndef GENERALFUNCTIONS_H
#define GENERALFUNCTIONS_H

#include <QString>
#include "logger.h"

class GeneralFunctions
{
public:
    GeneralFunctions(){}
    static QString logLevelToString(LogLevel value);
};

#endif // GENERALFUNCTIONS_H
