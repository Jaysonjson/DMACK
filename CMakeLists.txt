cmake_minimum_required(VERSION 3.5)

project(DMACK VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

include_directories("libs/includes/")

set(PROJECT_SOURCES
        main.cpp
        startscreen.cpp
        startscreen.h
        startscreen.ui
        resource.qrc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(DMACK
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        createaddonscreen.h createaddonscreen.cpp createaddonscreen.ui
        createtardisscreen.h createtardisscreen.cpp createtardisscreen.ui
        mainmanagerscreen.h mainmanagerscreen.cpp mainmanagerscreen.ui
        tardismanagerscreen.h tardismanagerscreen.cpp tardismanagerscreen.ui
        vars.h vars.cpp
        clickablelabel.h clickablelabel.cpp
        addexteriorlayerscreen.h addexteriorlayerscreen.cpp addexteriorlayerscreen.ui
        thirdpartyscreen.h thirdpartyscreen.cpp thirdpartyscreen.ui
    )
endif()

target_link_libraries(DMACK PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(DMACK PRIVATE "${CMAKE_CURRENT_LIST_DIR}/libs/libDMAddonLib.a")

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.DMACK)
endif()
set_target_properties(DMACK PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS DMACK
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(DMACK)
endif()
