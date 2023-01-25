set(APPLICATION_FILES
    "./src/Tars/Application.h"
    "./src/Tars/Application.cpp"
)

set(CORE
    "./src/Tars/Core.h"
)

set(ENTRY_POINT
    "./src/Tars/EntryPoint.h"
)

set(EXTERNAL
    "./src/Tars.h"
)

set(LOGGING
    "./src/Tars/log.h"
    "./src/Tars/log.cpp"
)

set(TARS_FILES
    ${APPLICATION_FILES}
    ${CORE}
    ${ENTRY_POINT}
    ${EXTERNAL}
    ${LOGGING}
)