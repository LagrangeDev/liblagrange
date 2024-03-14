//
// Created by yizhou on 8/3/2024.
//
module;

#include <string>

import serialize;

export module json;

namespace json {

export template<typename T, typename Functor>
struct required;

export template<typename Functor>
struct required<int64_t, Functor> {
    std::string name = Functor();
    int64_t value;
    required(int64_t origin): value(origin) {}
    operator int64_t() { return value; }
};

export template<typename Functor>
struct required<std::string, Functor> {
    std::string name = Functor();
    std::string value;
    required(std::string_view origin): value(origin) {}
    operator std::string() { return value; }
};

export template<typename T, typename Functor>
requires serializable_c<T>
struct required<T, Functor> {
    std::string name = Functor();
    T value;
    required(const T& origin): value(origin) {}
    operator T() { return value; }
};

export template<typename T, typename Functor>
struct optional;

export template<typename Functor>
struct optional<int64_t, Functor> {
    std::string name = Functor();
    int64_t value;
    optional(int64_t origin): value(origin) {}
    operator int64_t() { return value; }
};

export template<typename Functor>
struct optional<std::string, Functor> {
    std::string name = Functor();
    std::string value;
    optional(std::string_view origin): value(origin) {}
    operator std::string() { return value; }
};

export template<typename T, typename Functor>
requires serializable_c<T>
struct optional<T, Functor> {
    std::string name = Functor();
    T value;
    optional(const T& origin): value(origin) {}
    operator T() { return value; }
};

}