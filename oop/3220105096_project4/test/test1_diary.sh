#!/bin/bash

# 定义可执行文件的路径
BIN_DIR="../bin"
DIARY_FILE="mydiary.txt"

# 清理现场，确保日记文件是空的
> "$DIARY_FILE"

# 添加条目
echo "Adding entries..."

echo "day1" "111 ffff" | "$BIN_DIR/pdadd"

echo "day3" "333 ttttt" | "$BIN_DIR/pdadd"

echo "day5" "555 eeeeeeeeeee" | "$BIN_DIR/pdadd"

# 列出条目
echo "day1" "day3" | "$BIN_DIR/pdlist" "Listing entries..." 

# 展示条目
echo "day3" | "$BIN_DIR/pdshow" "Showing an entry..." 

# 移除条目
echo "day3" | "$BIN_DIR/pdremove" "Removing an entry..."

# 验证步骤

echo "Test completed."
