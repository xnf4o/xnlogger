/*
 * Yo-ho-ho! Ahoy there, matey! Arrr, this be the mighty xnlogger, brought to ye
 * by the swashbuckling crew at https://github.com/xnf4o/xnlogger/.
 *
 * Ye be granted free booty, aye, to use, copy, modify, merge, publish, distribute,
 * sublicense, and/or sell copies of this here Software, and to permit any scallywags
 * to use the Software, subject to the followin' conditions:
 *
 * The above copyright notice and this permission notice shall be includin' in all
 * copies or substantial portions of the Software, so all be knowin' who be the rightful
 * owners of this fine piece of code.
 *
 * THE SOFTWARE BE PROVIDED "AS IS", WITHOUT ANY WARRANTIES OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIMS, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE, OR ANY DEALINGS IN THE BOOTY GATHERED FROM THIS SOFTWARE.
 * Yarrrr!
 */
#define XNLOG_HPP
#ifdef XNLOG_HPP

#pragma once

#include <iostream>
#include <ctime>
#include <Windows.h>
#include <iomanip>
#include <fstream>

namespace logger {

    enum LogLevel {
        INFO,
        WARNING,
        ERR
    };

    inline void output(LogLevel level, const char* format, va_list args) {
        std::time_t t = std::time(nullptr);
        std::tm tm;

        localtime_s(&tm, &t);

        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        SetConsoleTextAttribute(hConsole, 13);
        std::cout << "[" << std::put_time(&tm, "%Y-%m-%d %H:%M:%S") << "] ";

        switch (level) {
        case LogLevel::INFO:
            SetConsoleTextAttribute(hConsole, 11);
            std::cout << "[INFO] ";
            break;
        case LogLevel::WARNING:
            SetConsoleTextAttribute(hConsole, 14);
            std::cout << "[WARNING] ";
            break;
        case LogLevel::ERR:
            SetConsoleTextAttribute(hConsole, 12);
            std::cout << "[ERROR] ";
            break;
        }

        SetConsoleTextAttribute(hConsole, 15);
        std::vprintf(format, args);
        std::cout << ".";


        va_list args_copy;
        va_copy(args_copy, args);

        std::ofstream logFile("E:\\log.txt", std::ios_base::app);
        if (logFile) {
            logFile << "[" << std::put_time(&tm, "%Y-%m-%d %H:%M:%S") << "] ";

            switch (level) {
            case LogLevel::INFO:
                logFile << "[INFO] ";
                break;
            case LogLevel::WARNING:
                logFile << "[WARNING] ";
                break;
            case LogLevel::ERR:
                logFile << "[ERROR] ";
                break;
            }

            char buf[1024];
            std::vsnprintf(buf, 1024, format, args_copy);
            logFile << buf << "." << std::endl;
            logFile.close();
        }

        va_end(args_copy);
        std::cout << std::endl;
    }


    inline void info(const char* format, ...) {
        va_list args;
        va_start(args, format);
        output(LogLevel::INFO, format, args);
        va_end(args);
    }

    inline void warning(const char* format, ...) {
        va_list args;
        va_start(args, format);
        output(LogLevel::WARNING, format, args);
        va_end(args);
    }

    inline void error(const char* format, ...) {
        va_list args;
        va_start(args, format);
        output(LogLevel::ERR, format, args);
        va_end(args);
    }

}

#endif // XNLOG_HPP
