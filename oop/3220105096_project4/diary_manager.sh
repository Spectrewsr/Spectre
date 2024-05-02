#!/bin/bash

# 定义可执行文件的目录路径
BIN_DIR="./bin"

# 执行相关程序的函数
run_pdadd() {
    echo "Running pdadd"
    
    "$BIN_DIR/pdadd"
}

run_pdlist() {
    echo "Running pdlist"
    
    "$BIN_DIR/pdlist"
}

run_pdremove() {
    echo "Running pdremove"
    
    "$BIN_DIR/pdremove"
}

run_pdshow() {
    echo "Running pdshow"
    
    "$BIN_DIR/pdshow"
}

# 循环直到用户决定退出
while true; do
    echo "Please choose an option:"
    echo "1. Add entry"
    echo "2. List entries"
    echo "3. Remove entry"
    echo "4. Show entry"
    echo "5. Exit"
    read -p "Enter your choice (1/2/3/4/5): " choice

    case $choice in
        1)
            run_pdadd
            ;;
        2)
            run_pdlist
            ;;
        3)
            run_pdremove
            ;;
        4)
            run_pdshow
            ;;
        5)
            echo "Exiting..."
            exit 0
            ;;
        *)
            echo "Invalid option, please try again."
            ;;
    esac
done
