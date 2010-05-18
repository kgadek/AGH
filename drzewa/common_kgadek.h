#ifndef __TESTERKA_COMMON_H
#define __TESTERKA_COMMON_H

#include "avl_kgadek.h"

namespace print_tree {
        extern int a, b, c;
        void _print(avlNode*, int);
        void print_rev(avlNode*, int);
        void print_norm(avlNode*, int);
};

#endif
