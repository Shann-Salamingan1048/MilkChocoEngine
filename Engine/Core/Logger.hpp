#pragma once


namespace MilkChoco
{
    class Logger
    {
    public:
        static void Info(const char* msg);
        static void Warn(const char* msg);
        static void Error(const char* msg);
    };
}