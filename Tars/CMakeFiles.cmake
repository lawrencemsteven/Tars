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

set(TARS_RENDERER
    "./src/Tars/Renderer/GraphicsContext.h"
    "./src/Tars/Renderer/Shader.h"
    "./src/Tars/Renderer/Shader.cpp"
)

set(TARS_WINDOWING_GLFW
    "./src/Windowing/GLFW/WindowUsingGLFW.h"
    "./src/Windowing/GLFW/WindowUsingGLFW.cpp"
    "./src/Windowing/GLFW/GLFWInput.h"
    "./src/Windowing/GLFW/GLFWInput.cpp"
)

set(TARS_GRAPHICS_OPENGL
    "./src/Graphics/OpenGL/OpenGLContext.h"
    "./src/Graphics/OpenGL/OpenGLContext.cpp"
)

set(TARS_IMGUI
    "./src/Tars/ImGui/ImGuiLayer.h"
    "./src/Tars/ImGui/ImGuiLayer.cpp"
    "./src/Tars/ImGui/ImGuiBuild.cpp"
)

set(TARS_MAIN
    "./src/Tars/Application.h"
    "./src/Tars/Application.cpp"
    "./src/Tars/Core.h"
    "./src/Tars/EntryPoint.h"
    "./src/Tars/log.h"
    "./src/Tars/log.cpp"
    "./src/Tars/Window.h"
    "./src/Tars/Layer.h"
    "./src/Tars/Layer.cpp"
    "./src/Tars/LayerStack.h"
    "./src/Tars/LayerStack.cpp"
    "./src/Tars/Input.h"
    "./src/Tars/KeyCodes.h"
    "./src/Tars/MouseButtonCodes.h"
)

set(TARS_FILES
    ${TARS_EXTERNAL}
    ${TARS_EVENTS}
    ${TARS_RENDERER}
    ${TARS_WINDOWING_GLFW}
    ${TARS_GRAPHICS_OPENGL}
    ${TARS_IMGUI}
    ${TARS_MAIN}
)