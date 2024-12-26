//
// Created by Don Yihtseu on 24-12-20.
//

export module serialize.protobuf;

import standard.encoding;
import standard.core;
import standard.concepts;
import standard.meta;
import standard.string;
import standard.iterator;
import standard.container;
import standard.utility;
import standard.ranges;

namespace proto {

export using int32 = std::int32_t;
export using int64 = std::int64_t;
export using uint32 = std::uint32_t;
export using uint64 = std::uint64_t;
export using sint32 = std::int32_t;
export using sint64 = std::int64_t;
export using fixed32 = std::uint32_t;
export using fixed64 = std::uint64_t;
export using sfixed32 = std::int32_t;
export using sfixed64 = std::int64_t;
export using string = std::string_view;
export using bytes = std::span<char>;

export template<typename T>
using repeat = std::span<T>;

export template<typename K, typename V>
using dictionary = std::unordered_map<K, V>;

export template<int Num, typename T>
struct field {
    T value;
};

}