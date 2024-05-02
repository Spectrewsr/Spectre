# 搜集当前目录下所有的.cpp文件
file(GLOB SOURCES "*.cpp")

# 首先定义目标可执行文件main
add_executable(main ${SOURCES})

# 然后为main目标设置包含目录
target_include_directories(main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)

# 设置可执行文件的输出路径
set_target_properties(main PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
