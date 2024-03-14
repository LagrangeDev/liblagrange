//
// Created by yizhou on 24-2-24.
//

module;

#include <bit>
#include <map>
#include <string_view>
#include <vector>
#include <cstdint>

export module tars;

constexpr auto litte(std::integral auto value) {
    if constexpr (std::endian::native == std::endian::little) {
        return value;
    } else {
        return std::byteswap(value);
    }
}

constexpr auto big(std::integral auto value) {
    if constexpr (std::endian::native == std::endian::big) {
        return value;
    } else {
        return std::byteswap(value);
    }
}

auto write_head(char *buffer, std::integral auto tag, std::integral auto type) {
    if (tag <= 14) {
        buffer[0] = static_cast<char>(type + (tag >> 4));
    } else {
        buffer[0] = static_cast<char>(type);
        buffer[1] = static_cast<char>(tag);
    }
}

auto read_head(char* buffer) {

}

namespace tars {

export template<typename T, size_t Tag>
struct required;

export template<size_t Tag>
struct required<bool, Tag>{
    bool value;
    required(auto origin): value(origin) {}
    operator bool() { return value; }
};

export template<size_t Tag>
struct required<uint8_t, Tag>{
    uint8_t value;
    required(auto origin): value(origin) {}
};

export template<size_t Tag>
struct required<uint16_t, Tag>{
    uint16_t value;
    required(auto origin): value(origin) {}
};

export template<size_t Tag>
struct required<uint32_t, Tag>{
    uint32_t value;
    required(auto origin): value(origin) {}
};

export template<size_t Tag>
struct required<uint64_t, Tag>{
    uint64_t value;
    required(auto origin): value(origin) {}
};

export template<size_t Tag>
struct required<int8_t, Tag>{
    int8_t value;
    required(auto origin): value(origin) {}
};

export template<size_t Tag>
struct required<int16_t, Tag>{
    int16_t value;
    required(auto origin): value(origin) {}
};

export template<size_t Tag>
struct required<int32_t, Tag>{
    int32_t value;
    required(auto origin): value(origin) {}
};

export template<size_t Tag>
struct required<int64_t, Tag>{
    int64_t value;
    required(auto origin): value(origin) {}
};

export template<size_t Tag>
struct required<std::string, Tag>{
    std::string value;
    required(auto origin): value(origin) {}
};

export template<size_t Tag>
struct required<std::map<std::string, std::string>, Tag>{
    std::map<std::string, std::string> value;
    required(auto origin): value(origin) {}
};

export template<typename T, size_t Tag>
struct optional;

export template<size_t Tag>
struct optional<bool, Tag>{
    bool value;
    optional(auto origin): value(origin) {}
    operator bool() { return value; }
};

export template<size_t Tag>
struct optional<uint8_t, Tag>{
    uint8_t value;
    optional(auto origin): value(origin) {}
};

export template<size_t Tag>
struct optional<uint16_t, Tag>{
    uint16_t value;
    optional(auto origin): value(origin) {}
};

export template<size_t Tag>
struct optional<uint32_t, Tag>{
    uint32_t value;
    optional(auto origin): value(origin) {}
};

export template<size_t Tag>
struct optional<uint64_t, Tag>{
    uint64_t value;
    optional(auto origin): value(origin) {}
};

export template<size_t Tag>
struct optional<int8_t, Tag>{
    int8_t value;
    optional(auto origin): value(origin) {}
};

export template<size_t Tag>
struct optional<int16_t, Tag>{
    int16_t value;
    optional(auto origin): value(origin) {}
};

export template<size_t Tag>
struct optional<int32_t, Tag>{
    int32_t value;
    optional(auto origin): value(origin) {}
};

export template<size_t Tag>
struct optional<int64_t, Tag>{
    int64_t value;
    optional(auto origin): value(origin) {}
};

export template<size_t Tag>
struct optional<std::string, Tag>{
    std::string value;
    optional(auto origin): value(origin) {}
};

export template<size_t Tag>
struct optional<std::map<std::string, std::string>, Tag>{
    std::map<std::string, std::string> value;
    optional(auto origin): value(origin) {}
};

}
