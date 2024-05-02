#ifndef _ALOC_HPP_
#define _ALOC_HPP_

template <class T>
class Mallocate

{
    /**
     * @note Chinese Comment:
     * 此typedef用于指示`_Not_user_specialized`不应由用户进行特化。
     * 
     * @note The purpose of this typedef is to prevent accidental specialization
     * by the user.
     */
    typedef void _Not_user_specialized;
    typedef T value_type;
    typedef value_type *pointer;
    typedef const value_type *const_pointer;
    typedef value_type &reference;
    typedef const value_type &const_reference;
    typedef std::size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef std::true_type propagate_on_container_move_assignment;
    typedef std::true_type is_always_equal;

    /**
     * @brief This section defines a set of member functions for the Mallocator class.
     * 
     * The member functions include the default constructor, the copy constructor,
     * the move constructor, the copy assignment operator, the move assignment operator,
     * the destructor, the address function, the allocate function, the deallocate function,
     * the max_size function, the construct function, and the destroy function.
     * 
     * @note Chinese Comment:
     * 此部分定义了Mallocator类的一组成员函数。
     * 
     * 这些成员函数包括默认构造函数、复制构造函数、移动构造函数、复制赋值运算符、
     * 移动赋值运算符、析构函数、地址函数、分配函数、释放函数、最大大小函数、构造函数和销毁函数。
     */
    Mallocate() {};

    template <class U>
    Mallocator(const Mallocator<U> &other) noexcept;

    
};

#endif