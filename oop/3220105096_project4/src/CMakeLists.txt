# 搜集当前目录下所有的.cpp文件，如果你不需要自动搜集，可以注释掉这一行
# file(GLOB SOURCES "*.cpp")

# 定义四个目标可执行文件
add_executable(pdadd pdadd.cpp Diary.cpp)
add_executable(pdlist pdlist.cpp Diary.cpp)
add_executable(pdshow pdshow.cpp Diary.cpp)
add_executable(pdremove pdremove.cpp Diary.cpp)

# 为所有目标设置相同的包含目录
target_include_directories(pdadd PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
target_include_directories(pdlist PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
target_include_directories(pdshow PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
target_include_directories(pdremove PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)

# 设置四个可执行文件的输出路径
set_target_properties(pdadd PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set_target_properties(pdlist PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set_target_properties(pdshow PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set_target_properties(pdremove PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
