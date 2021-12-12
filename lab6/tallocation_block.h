//
// Created by polki on 12.12.2021.
//

#ifndef LAB6_TALLOCATION_BLOCK_H
#define LAB6_TALLOCATION_BLOCK_H
#include <cstdlib>

class TAllocationBlock {
public:
    TAllocationBlock(size_t size, size_t count);
    void* allocate();
    void deallocate(void* pointer);
    bool has_free_blocks();

    virtual ~TAllocationBlock();

private:
    size_t _size;
    size_t _count;

    char* _used_blocks;
    void** _free_blocks;

    size_t _free_count;
};
#endif //LAB6_TALLOCATION_BLOCK_H
