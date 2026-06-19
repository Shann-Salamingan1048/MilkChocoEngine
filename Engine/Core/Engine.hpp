#pragma once
#include <utility>

namespace MilkChoco
{
    class Engine
    {
    public:
        template <typename T, typename... Args>
        static int Start(Args&&... args)
        {
            T app(std::forward<Args>(args)...);
            app.Run();
            return 0;
        }
    };
}