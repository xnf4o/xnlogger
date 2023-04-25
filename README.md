# XNLogger

XNLogger is a simple logging library for C++ that provides colorful output to the console and writes logs to a file. It supports three log levels: INFO, WARNING, and ERR.

## Features

- Colorful console output for eye-catching logs
- Logs are written to a file for easy storage and analysis
- Supports three log levels: INFO, WARNING, and ERR
- Easy to use with variadic functions for logging messages with formatting

## Usage

1. Include the XNLogger library in your C++ project.
2. Initialize the logger by calling `logger::init()` function (not shown in the code snippet).
3. Start logging messages using the `logger::info()`, `logger::warning()`, and `logger::error()` functions.
4. Provide a log message with optional formatting using the same syntax as `printf()`.
5. Logs will be displayed in the console with colorful output and written to a file for future reference.

## Example

```cpp
#include "xnlog.hpp"

int main() {
    // Log an info message
    logger::info("This is an info message.");

    // Log a warning message with formatting
    int errorCode = 404;
    logger::warning("Warning: Failed to load file. Error code: %d", errorCode);

    // Log an error message
    const char* errorMessage = "File not found";
    logger::error("Error: %s", errorMessage);

    return 0;
}
```

## Output

```cpp
[2023-04-25 15:30:45] [INFO] This is an info message.
[2023-04-25 15:30:45] [WARNING] Warning: Failed to load file. Error code: 404.
[2023-04-25 15:30:45] [ERROR] Error: File not found.
```
Logs are displayed in the console with colorful output to easily identify the log level. They are also written to a file "log.txt" in append mode for future reference.
