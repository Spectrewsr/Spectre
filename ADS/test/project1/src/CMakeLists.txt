file(GLOB SOURCES "*.cpp")

add_executable(main ${SOURCES})

target_include_directories(demo  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)

set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)