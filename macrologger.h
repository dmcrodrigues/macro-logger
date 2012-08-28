//
//  macrologger.h
//  TimeMonitor
//
//  Created by David Rodrigues on 27/08/12.
//
//

#include <time.h>
#include <string.h>

// === auxiliar function
static inline char *timenow();

// === auxiliar function
#define _FILE strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__

#define NO_LOG          0x00
#define ERROR_LEVEL     0x01
#define INFO_LEVEL      0x02
#define DEBUG_LEVEL     0x03

#ifndef LOG_LEVEL
#define LOG_LEVEL   DEBUG_LEVEL
#endif

#define LOG_TIME    

#ifdef __OBJC__
#define PRINTFUNCTION(fmt, ...)     NSLog(@fmt, __VA_ARGS__)
#else
#define PRINTFUNCTION(fmt, ...)     fprintf(stderr, fmt, __VA_ARGS__)
#endif

#if defined(__OBJC__) || !defined(LOG_TIME)
#define LOG_FMT             "| %8s | %15s:%d | %15s | "
#define LOG_ARGS(LOG_TAG)   LOG_TAG, _FILE, __LINE__, __FUNCTION__
#else
#define LOG_FMT             "%s | %8s | %15s:%d | %15s | "
#define LOG_ARGS(LOG_TAG)   timenow(), LOG_TAG, _FILE, __LINE__, __FUNCTION__
#endif

#define NEWLINE     "\n"

#define ERROR_TAG   "ERROR"
#define INFO_TAG    "INFO"
#define DEBUG_TAG   "DEBUG"

#if LOG_LEVEL >= DEBUG_LEVEL
#define LOG_DEBUG(message, args...)     PRINTFUNCTION(LOG_FMT message NEWLINE, LOG_ARGS(DEBUG_TAG), ## args)
#else
#define LOG_DEBUG(message, args...)
#endif

#if LOG_LEVEL >= INFO_LEVEL
#define LOG_INFO(message, args...)      PRINTFUNCTION(LOG_FMT message NEWLINE, LOG_ARGS(INFO_TAG), ## args)
#else
#define LOG_INFO(message, args...)
#endif

#if LOG_LEVEL >= ERROR_LEVEL
#define LOG_ERROR(message, args...)     PRINTFUNCTION(LOG_FMT message NEWLINE, LOG_ARGS(ERROR_TAG), ## args)
#else
#define LOG_ERROR(message, args...)
#endif

static inline char *timenow() {
    static char buffer[64];
    time_t rawtime;
    struct tm *timeinfo;
    
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    
    strftime(buffer, 64, "%Y-%m-%d %H:%M:%S", timeinfo);
    
    return buffer;
}