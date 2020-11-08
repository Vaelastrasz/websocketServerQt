#include "generalfunctions.h"

QString GeneralFunctions::logLevelToString(LogLevel value) {
    switch (value) {
    case llDebug:
        return "DEBUG";
    case llInformation:
        return "INFO";
    case llError:
        return "ERROR";
    case llSuccess:
        return "SUCCESS";
    default:
        return "UNKNOWN";
    }
}
