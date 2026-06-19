add_executable(Sandbox)

target_sources(Sandbox PRIVATE
        main.cpp
        SampleGame.cpp
)

target_link_libraries(Sandbox
        PUBLIC EngineCore
        PUBLIC EnginePlatform
        PUBLIC EngineRendering
)