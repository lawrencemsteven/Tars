set(EXTERNAL
    "./src/Tars.h"
)

set(CORE
    "./src/Tars/Core.h"
)

set(ENTRY_POINT
    "./src/Tars/EntryPoint.h"
)

set(APPLICATION_FILES
    "./src/Tars/Application.h"
    "./src/Tars/Application.cpp"
)

set(TARS_FILES
    ${EXTERNAL}
    ${CORE}
    ${ENTRY_POINT}
    ${APPLICATION_FILES}
)