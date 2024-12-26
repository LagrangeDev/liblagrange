//
// Created by Don Yihtseu on 24-12-20.
//

export module serialize.json;

import standard.encoding;
import standard.algorithm;
import standard.core;
import standard.concepts;
import standard.meta;
import standard.string;
import standard.iterator;
import standard.container;
import standard.utility;
import standard.ranges;

namespace json {

export using number = std::uint64_t;
export using string = std::string_view;

export template<std::size_t N>
struct comp_str {
    std::array<char, N - 1> value;

    constexpr comp_str(const auto... args) : value{args...} {}

    constexpr comp_str(const char (&str)[N]) {
        std::copy_n(str, N - 1, value.data());
    }

    constexpr operator std::string_view() const { return {value.data(), N - 1}; }

    constexpr auto size() const { return N - 1; }
};

export template<comp_str, typename T>
struct field {
    T value;
};

}