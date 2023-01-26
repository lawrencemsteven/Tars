set(TARS_EVENTS
    "./src/Tars/Events/ApplicationEvent.h"
    "./src/Tars/Events/Event.h"
    "./src/Tars/Events/KeyEvent.h"
    "./src/Tars/Events/MouseEvent.h"
)

set(TARS_EXTERNAL
    "./src/Tars.h"
    "./src/TarsPCH.h"
)

set(TARS_GRAPHICS_OPENGL
    "./src/Graphics/OpenGL/ImGuiOpenGLRenderer.h"
    "./src/Graphics/OpenGL/ImGuiOpenGLRenderer.cpp"
)

set(TARS_IMGUI
    "./src/Tars/ImGui/ImGuiLayer.h"
    "./src/Tars/ImGui/ImGuiLayer.cpp"
)

set(TARS_MAIN
    "./src/Tars/Application.h"
    "./src/Tars/Application.cpp"
    "./src/Tars/Core.h"
    "./src/Tars/EntryPoint.h"
    "./src/Tars/log.h"
    "./src/Tars/log.cpp"
    "./src/Tars/Window.h"
    "./src/Tars/WindowUsingGLFW.h"
    "./src/Tars/WindowUsingGLFW.cpp"
    "./src/Tars/Layer.h"
    "./src/Tars/Layer.cpp"
    "./src/Tars/LayerStack.h"
    "./src/Tars/LayerStack.cpp"
)

set(TARS_FILES
    ${TARS_EXTERNAL}
    ${TARS_EVENTS}
    ${TARS_GRAPHICS_OPENGL}
    ${TARS_IMGUI}
    ${TARS_MAIN}
)