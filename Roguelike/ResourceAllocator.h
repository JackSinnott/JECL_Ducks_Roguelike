#ifndef RESOURCE_ALLOCATOR_H
#define RESOURCE_ALLOCATOR_H

template<typename Derived, typename T>
class ResourceAllocator
{
public:
    ResourceAllocator() { "Resource allocator created"; };
    ~ResourceAllocator() { "Resource allocator deleted"; };

    virtual T Acquire(const std::string& name) = 0;

    virtual T Collectgarbage() = 0;

};
#endif // !RESOURCE_ALLOCATOR_H
