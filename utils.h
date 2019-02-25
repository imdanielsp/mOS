#ifndef _KERNEL_UTILS_H
#define _KERNEL_UTILS_H

#define __NL__

#define NON_COPYABLE(Type) \
    Type(const Type&) = delete; __NL__ \
    Type(const Type&&) = delete; __NL__ \
    Type& operator=(const Type&) = delete;

#endif