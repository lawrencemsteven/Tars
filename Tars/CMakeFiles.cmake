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
    "./src/Tars/Renderer/Buffer.h"
    "./src/Tars/Renderer/Buffer.cpp"
    "./src/Tars/Renderer/Renderer.h"
    "./src/Tars/Renderer/Renderer.cpp"
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
    "./src/Graphics/OpenGL/OpenGLBuffer.h"
    "./src/Graphics/OpenGL/OpenGLBuffer.cpp"
)

set(TARS_IMGUI
    "./src/Tars/ImGui/ImGuiLayer.h"
    "./src/Tars/ImGui/ImGuiLayer.cpp"
    "./src/Tars/ImGui/ImGuiBuild.cpp"
)

set(TARS_LAYERS
    "./src/Tars/Layers/Layer.h"
    "./src/Tars/Layers/Layer.cpp"
    "./src/Tars/Layers/LayerStack.h"
    "./src/Tars/Layers/LayerStack.cpp"
)

set(TARS_LOGGING
    "./src/Tars/Logging/log.h"
    "./src/Tars/Logging/log.cpp"
)

set(TARS_INPUT
    "./src/Tars/Input/Input.h"
    "./src/Tars/Input/KeyCodes.h"
    "./src/Tars/Input/MouseButtonCodes.h"
)

set(TARS_MAIN
    "./src/Tars/Main/Application.h"
    "./src/Tars/Main/Application.cpp"
    "./src/Tars/Main/Core.h"
    "./src/Tars/Main/EntryPoint.h"
    "./src/Tars/Main/Window.h"
)

set(TARS_ITEMS
    "./src/Tars/Items/Item.h"
    "./src/Tars/Items/Item.cpp"
)

set(TARS_VOXEL_CHUNK
    "./src/Tars/Voxel/Chunk/Chunk.h"
    "./src/Tars/Voxel/Chunk/Chunk.cpp"
)

set(TARS_VOXEL_BLOCKS
    "./src/Tars/Voxel/Blocks/Block.h"
    "./src/Tars/Voxel/Blocks/Block.cpp"
)

set(TARS_FILES
    ${TARS_EXTERNAL}
    ${TARS_EVENTS}
    ${TARS_RENDERER}
    ${TARS_WINDOWING_GLFW}
    ${TARS_GRAPHICS_OPENGL}
    ${TARS_IMGUI}
    ${TARS_LAYERS}
    ${TARS_LOGGING}
    ${TARS_INPUT}
    ${TARS_MAIN}
    ${TARS_ITEMS}
    ${TARS_VOXEL_CHUNK}
    ${TARS_VOXEL_BLOCKS}
)