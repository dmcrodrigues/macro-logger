## Macro-Logger

A simplified logging system using macros for C/C++ and Objective-C.

## Notes

#### Levels

There are three different logging levels:

  * (0) NO_LOGS
  * (1) ERROR
  * (2) INFO
  * (3) DEBUG

The log level used can be specified on compilation time using the macro LOG_LEVEL=level. Otherwise is defined the level DEBUG.

#### C/C++
  * The logs are printed using fprintf function in conjunction with standard error stream (stderr)

#### Objective-C
  * The logs are printed using NSLog function

## Basic usage

To use macrologger just import

```C++

// C/C++
#include "macrologger.h"

// Objective-C
#import "macrologger.h"
```

### Available functions

```C++


LOG_DEBUG(message, arguments);

LOG_INFO(message, arguments);

LOG_ERROR(message, arguments);

```

### Examples

```C++

int n_seconds = 5;
LOG_DEBUG("Waiting %d seconds...", n_seconds);

...

LOG_INFO("Searching for something.");

```