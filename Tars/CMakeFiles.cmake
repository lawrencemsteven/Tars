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
)

set(TARS_FILES
    ${TARS_EXTERNAL}
    ${TARS_EVENTS}
    ${TARS_MAIN}
)