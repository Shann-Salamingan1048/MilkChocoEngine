#include "Logger.hpp"
#include <print>


namespace MilkChoco
{
    void Logger::Info(const char *msg)
    {
        std::println("[INFO] {}", msg );
    }
    void Logger::Warn(const char *msg)
    {
        std::println("[Warn] {}", msg );
    }
    void Logger::Error(const char *msg)
    {
        std::println("[Error] {}", msg );
    }
}
