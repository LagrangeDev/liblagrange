//
// Created by Don Yihtseu on 24-12-20.
//

export module serialize.binary;

import standard.core;
import standard.algorithm;
import standard.concepts;
import standard.meta;
import standard.string;
import standard.iterator;
import standard.container;
import standard.utility;

namespace binary {

export using uint8 = std::uint8_t;
export using int8 = std::int8_t;
export using uint16 = std::uint16_t;
export using int16 = std::int16_t;
export using uint32 = std::uint32_t;
export using int32 = std::int32_t;
export using uint64 = std::uint64_t;
export using int64 = std::int64_t;
export using bytes = std::vector<char>;

export template <typename Prefix>
requires std::integral<Prefix> || std::is_void<Prefix>
struct string {
  std::string_view value;
  string(std::string_view origin) : value(origin) {}
  operator std::string_view() const { return value; }
};

export template <typename T>
struct field {
    T value;
};

} // namespace binary
