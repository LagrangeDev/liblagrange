//
// Created by yizhou on 9/3/2024.
//

module;

#include <concepts>

export module serialize;

export template<typename Serializable>
concept serializable_c = requires(Serializable field)
{
    { field.size() } -> std::convertible_to<std::size_t>;
    { field.encode(reinterpret_cast<char*>(0)) } -> std::convertible_to<char*>;
    { field.decode(reinterpret_cast<char*>(0)) } -> std::convertible_to<char*>;
};

export template<typename T, typename... Args>
requires serializable_c<T>
size_t size_of(T& field, Args&... args) {
    return field.size() + size_of(args...);
}

export template<typename T, typename... Args>
requires serializable_c<T>
char* serialize(char* buffer, const T& field, const Args&... args) {
    return serialize(field.encode(buffer), args...);
}

export template<typename T, typename... Args>
requires serializable_c<T>
char* deserialize(const char* buffer, T& field, Args&... args) {
    return deserialize(field.decode(buffer), args...);
}