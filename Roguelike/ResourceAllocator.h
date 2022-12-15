#ifndef RESOURCE_ALLOCATOR_H
#define RESOURCE_ALLOCATOR_H

/// <summary>
/// A template class that is used for the management of resources, like textures.
/// </summary>
/// <typeparam name="Derived">A child class of ResourceAllocator.</typeparam>
/// <typeparam name="T">The variable type the child class wishes to manage.</typeparam>

template<typename Derived, typename T>
class ResourceAllocator
{
public:
    /// <summary>
    /// Default constructor.
    /// </summary>
    ResourceAllocator() { "Resource allocator created"; };

    /// <summary>
    /// Default deconstructor.
    /// </summary>
    ~ResourceAllocator() { "Resource allocator deleted"; };

    /// <summary>
    /// Searches for a new resource in the project's files, loads it and returns it.
    /// </summary>
    /// <param name="name">String that is the path to what is to be acquired.</param>
    /// <returns>The new resource.</returns>
    virtual T Acquire(const std::string& name) = 0;

    /// <summary>
    /// deletes resources not being used, saving memory.
    /// </summary>
    /// <returns>The template variable after being tidied.</returns>
    virtual T Collectgarbage() = 0;

};
#endif // !RESOURCE_ALLOCATOR_H
