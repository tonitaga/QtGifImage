cmake_minimum_required(VERSION 3.5...3.16)
project(QGifImage)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

include(cmake/include.cmake)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

add_library(${PROJECT_NAME} SHARED
    include/gifimage/qgifglobal.h
    include/gifimage/qgifimage.cpp
    include/gifimage/qgifimage.h
    include/gifimage/qgifimage_p.h
    include/third_party/giflib/dgif_lib.c
    include/third_party/giflib/egif_lib.c
    include/third_party/giflib/gif_err.c
    include/third_party/giflib/gif_font.c
    include/third_party/giflib/gif_hash.c
    include/third_party/giflib/gif_hash.h
    include/third_party/giflib/gif_lib.h
    include/third_party/giflib/gif_lib_private.h
    include/third_party/giflib/gifalloc.c
    include/third_party/giflib/quantize.c
)

set(LIB_LINK_LIBRARIES
        Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::Gui
)

target_link_libraries(${PROJECT_NAME} PRIVATE ${LIB_LINK_LIBRARIES})
