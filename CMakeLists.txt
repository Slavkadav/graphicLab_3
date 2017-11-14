cmake_minimum_required(VERSION 3.8)
project(Graphic_lab_2)
set(CMAKE_PREFIX_PATH "C:\\Qt\\5.9.2\\mingw53_32")
set(CMAKE_CXX_STANDARD 11)


set(SOURCE_FILES main.cpp AffineTranslate/AffineTransform.cpp AffineTranslate/AffineTransform.h 3DModel/Model.cpp 3DModel/Model.h Canvas/Canvas.cpp Canvas/Canvas.h AffineTranslate/Vector/Vector.cpp AffineTranslate/Vector/Vector.h AffineTranslate/Matrix/Matrix.cpp AffineTranslate/Matrix/Matrix.h)
add_executable(Graphic_lab_2 ${SOURCE_FILES})

# включаем поиск библиотек с использованием find_package()
# через REQUIRED указываем, что библиотеки обязательны
find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets 3DCore 3DExtras 3DRender 3DInput)
# указываем, какие библиотеки необходимо подключить
target_link_libraries(${PROJECT_NAME}
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::3DCore
        Qt5::3DExtras
        Qt5::3DRender
        Qt5::3DInput
        )
set(RESOURCE_FILES Porsche_911_GT2.obj)

FILE(COPY Porsche_911_GT2.obj Rock1.obj DESTINATION "${CMAKE_BINARY_DIR}")