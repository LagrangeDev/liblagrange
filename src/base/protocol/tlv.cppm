//
// Created by yizhou on 8/3/2024.
//
module;

#include <bit>
#include <ranges>
#include <string>
#include <string_view>
#include <stdexcept>

export module tlv;

import serialize;

namespace tlv {

constexpr auto little(std::integral auto value) {
    if constexpr (std::endian::native == std::endian::little) {
        return std::byteswap(value);
    } else {
        return value;
    }
}

constexpr auto big(std::integral auto value) {
    if constexpr (std::endian::native == std::endian::big) {
        return std::byteswap(value);
    } else {
        return value;
    }
}

auto read_head(const char* buffer) {
    auto tag = big(*reinterpret_cast<const uint8_t*>(buffer));
    auto size = big(*reinterpret_cast<const uint16_t*>(buffer + 1));
    return std::make_pair(tag, size);
}

auto write_head(char* buffer, uint8_t tag, uint16_t size) {
    *reinterpret_cast<uint8_t*>(buffer) = little(tag);
    *reinterpret_cast<uint16_t*>(buffer + 1) = little(size);
}

export template<typename T, uint8_t Tag, int prefix = 0, int limit = 0>
struct required;

export template<uint8_t Tag>
struct required<uint8_t, Tag> {
    uint8_t value;
    required(uint8_t origin): value(origin) {}
    operator uint8_t() const { return value; }

    [[nodiscard]] size_t size() const { return sizeof(value); }
    char* encode(char* buffer) const {
        write_head(buffer, Tag, sizeof(value));
        *reinterpret_cast<uint8_t*>(buffer + 3) = little(value);
        return buffer + 4;
    }
    char* decode(char* buffer) {
        auto [tag, size] = read_head(buffer);
        if (tag != Tag || size != sizeof(value)) {
            throw std::runtime_error("Parse Error");
        }
        value = big(*reinterpret_cast<uint8_t*>(buffer + 3));
        return buffer + 4;
    }
};

export template<uint8_t Tag>
struct required<uint16_t, Tag> {
    uint16_t value;
    required(uint16_t origin): value(origin) {}
    operator uint16_t() const { return value; }

    [[nodiscard]] size_t size() const { return sizeof(value); }
    char* encode(char* buffer) const {
        write_head(buffer, Tag, sizeof(value));
        *reinterpret_cast<uint16_t*>(buffer + 3) = little(value);
        return buffer + 3 + size();
    }
    char* decode(char* buffer) {
        auto [tag, size] = read_head(buffer);
        if (tag != Tag || size != sizeof(value)) {
            throw std::runtime_error("Parse Error");
        }
        value = big(*reinterpret_cast<uint8_t*>(buffer + 3));
        return buffer + 3 + sizeof(value);
    }
};

export template<uint8_t Tag>
struct required<uint32_t, Tag> {
    uint32_t value;
    required(uint32_t origin): value(origin) {}
    operator uint32_t() const { return value; }

    [[nodiscard]] size_t size() const { return sizeof(value); }
    char* encode(char* buffer) const {
        write_head(buffer, Tag, sizeof(value));
        *reinterpret_cast<uint16_t*>(buffer + 3) = little(value);
        return buffer + 3 + size();
    }
    char* decode(char* buffer) {
        auto [tag, size] = read_head(buffer);
        if (tag != Tag || size != sizeof(value)) {
            throw std::runtime_error("Parse Error");
        }
        value = big(*reinterpret_cast<uint8_t*>(buffer + 3));
        return buffer + 3 + sizeof(value);
    }
};

export template<uint8_t Tag>
struct required<uint64_t, Tag> {
    uint64_t value;
    required(uint64_t origin): value(origin) {}
    operator uint64_t() const { return value; }

    [[nodiscard]] size_t size() const { return sizeof(value); }
    char* encode(char* buffer) const {
        write_head(buffer, Tag, sizeof(value));
        *reinterpret_cast<uint16_t*>(buffer + 3) = little(value);
        return buffer + 3 + size();
    }
    char* decode(char* buffer) {
        auto [tag, size] = read_head(buffer);
        if (tag != Tag || size != sizeof(value)) {
            throw std::runtime_error("Parse Error");
        }
        value = big(*reinterpret_cast<uint8_t*>(buffer + 3));
        return buffer + 3 + sizeof(value);
    }
};

export template<uint8_t Tag>
struct required<std::string, Tag> {
    std::string value;
    required(std::string_view origin): value(origin) {}
    operator std::string_view() { return value; }

    [[nodiscard]] size_t size() const { return 3 + value.size(); }
    char* encode(char* buffer) const {
        write_head(buffer, Tag, value.size());
        std::ranges::copy(value.begin(), value.end(), buffer + 3);
        return buffer + size();
    }
    char* decode(char* buffer) {
        auto [tag, size] = read_head(buffer);
        if (tag != Tag) {
            throw std::runtime_error("Parse Error");
        }
        std::ranges::copy(buffer + 3, buffer + 3 + size, value.begin());
        return buffer + size + 3;
    }
};

export template<uint8_t Tag, int Prefix, int Limit>
struct required<std::span<char>, Tag, Prefix, Limit> {
    std::span<char> value;
    required(std::span<char> origin): value(origin) {}
    operator std::span<char>() { return value; }

    size_t size() {}
    char* encode(char* buffer) {}
    char* decode(char* buffer) {}
};

}