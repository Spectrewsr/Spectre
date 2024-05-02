file(GLOB SOURCES "*.cpp")

add_executable(main ${SOURCES})

target_include_directories(main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)

set_target_properties(main PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)