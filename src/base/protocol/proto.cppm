//
// Created by yizhou on 24-2-26.
//

module;

#include <bit>
#include <map>
#include <vector>
#include <string>

import serialize;

export module proto;

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
    buffer[0] = litte(tag << 3 | type);
}

auto read_head(const char *buffer) {
    return std::make_pair(0, 0);
}

namespace proto {
export template<typename T, size_t Tag>
struct required;

export template<size_t Tag>
struct required<bool, Tag> {
    bool value;

    required(bool origin): value(origin) {}

    operator bool() const { return value; }

    size_t size() {}

    char *encode(char *buffer) {}

    char *decode(char *buffer) {}
};

export template<size_t Tag>
struct required<uint8_t, Tag> {
    uint8_t value;

    required(const decltype(value) &origin): value(origin) {}

    operator decltype(value)() { return value; }

    size_t size() {

    }

    char *encode(char *buffer) {}

    char *decode(char *buffer) {}
};

export template<size_t Tag>
struct required<uint16_t, Tag> {
    uint16_t value;

    required(const decltype(value) &origin): value(origin) {}

    operator decltype(value)() { return value; }

    size_t size() {}

    char *encode(char *buffer) {}

    char *decode(char *buffer) {}
};

export template<size_t Tag>
struct required<uint32_t, Tag> {
    uint32_t value;

    required(const decltype(value) &origin): value(origin) {}

    operator decltype(value)() { return value; }

    size_t size() {}

    char *encode(char *buffer) {}

    char *decode(char *buffer) {}
};

export template<size_t Tag>
struct required<uint64_t, Tag> {
    uint64_t value;

    required(const decltype(value) &origin): value(origin) {}

    operator decltype(value)() { return value; }

    size_t size() {}

    char *encode(char *buffer) {}

    char *decode(char *buffer) {}
};

export template<size_t Tag>
struct required<int32_t, Tag> {
    int32_t value;

    required(const decltype(value) &origin): value(origin) {}

    operator decltype(value)() { return value; }

    size_t size() {}

    char *encode(char *buffer) {}

    char *decode(char *buffer) {}
};

export template<size_t Tag>
struct required<int64_t, Tag> {
    int64_t value;

    required(const decltype(value) &origin): value(origin) {}

    operator decltype(value)() { return value; }

    size_t size() {}

    char *encode(char *buffer) {}

    char *decode(char *buffer) {}
};

export template<size_t Tag>
struct required<std::string, Tag> {
    std::string value;

    required(const decltype(value) &origin): value(origin) {}

    operator decltype(value)() { return value; }

    size_t size() {}

    char *encode(char *buffer) {}

    char *decode(char *buffer) {}
};

export template<size_t Tag>
struct required<std::vector<char>, Tag> {
    std::vector<char> value;

    required(const decltype(value) &origin): value(origin) {}

    operator decltype(value)() { return value; }

    size_t size() {}

    char *encode(char *buffer) {}

    char *decode(char *buffer) {}
};

export template<size_t Tag>
struct required<std::map<std::string, std::string>, Tag> {
    std::map<std::string, std::string> value;

    required(const decltype(value) &origin): value(origin) {}

    operator decltype(value)() { return value; }

    size_t size() {}

    char *encode(char *buffer) {}

    char *decode(char *buffer) {}
};

export template<typename T, size_t Tag>
requires serializable_c<T>
struct required<T, Tag> {
    T value;

    required(const decltype(value) &origin): value(origin) {}

    operator decltype(value)() { return value; }

    size_t size() {
        return value.size();
    }

    char *encode(char *buffer) {
        return value.serialize(buffer);
    }

    char *decode(char *buffer) {
        return value.deserialize(buffer);
    }
};

export template<typename T, size_t Tag>
struct optional;

export template<size_t Tag>
struct optional<bool, Tag> {
    bool value;

    optional(const decltype(value) &origin): value(origin) {}

    operator bool() const { return value; }

    size_t size() {}

    char *encode(char *buffer) {}

    char *decode(char *buffer) {}
};

export template<size_t Tag>
struct optional<uint8_t, Tag> {
    uint8_t value;

    optional(const decltype(value) &origin): value(origin) {}

    operator decltype(value)() { return value; }

    size_t size() {}

    char *encode(char *buffer) {}

    char *decode(char *buffer) {}
};

export template<size_t Tag>
struct optional<uint16_t, Tag> {
    uint16_t value;

    optional(const decltype(value) &origin): value(origin) {}

    operator decltype(value)() { return value; }

    size_t size() {}

    char *encode(char *buffer) {}

    char *decode(char *buffer) {}
};

export template<size_t Tag>
struct optional<uint32_t, Tag> {
    uint32_t value;

    optional(const decltype(value) &origin): value(origin) {}

    operator decltype(value)() { return value; }

    size_t size() {}

    char *encode(char *buffer) {}

    char *decode(char *buffer) {}
};

export template<size_t Tag>
struct optional<uint64_t, Tag> {
    uint64_t value;

    optional(const decltype(value) &origin): value(origin) {}

    operator decltype(value)() { return value; }

    size_t size() {}

    char *encode(char *buffer) {}

    char *decode(char *buffer) {}
};

export template<size_t Tag>
struct optional<int32_t, Tag> {
    int32_t value;

    optional(const decltype(value) &origin): value(origin) {}

    operator decltype(value)() { return value; }

    size_t size() {}

    char *encode(char *buffer) {}

    char *decode(char *buffer) {}
};

export template<size_t Tag>
struct optional<int64_t, Tag> {
    int64_t value;

    optional(const decltype(value) &origin): value(origin) {}

    operator decltype(value)() { return value; }

    size_t size() {}

    char *encode(char *buffer) {}

    char *decode(char *buffer) {}
};

export template<size_t Tag>
struct optional<std::string, Tag> {
    std::string value;

    optional(const decltype(value) &origin): value(origin) {}

    operator decltype(value)() { return value; }

    size_t size() {}

    char *encode(char *buffer) {}

    char *decode(char *buffer) {}
};

export template<size_t Tag>
struct optional<std::vector<char>, Tag> {
    std::vector<char> value;

    optional(decltype(value) origin): value(std::move(origin)) {}

    operator decltype(value)() { return value; }

    size_t size() {}

    char *encode(char *buffer) {}

    char *decode(char *buffer) {}
};

export template<size_t Tag>
struct optional<std::map<std::string, std::string>, Tag> {
    std::map<std::string, std::string> value;

    optional(decltype(value) origin): value(std::move(origin)) {}

    operator decltype(value)() { return value; }

    size_t size() {}

    char *encode(char *buffer) {}

    char *decode(char *buffer) {}
};

export template<typename T, size_t Tag>
requires serializable_c<T>
struct optional<T, Tag> {
    T value;

    optional(const decltype(value) &origin): value(origin) {}

    operator decltype(value)() { return value; }

    size_t size() {
        return value.size();
    }

    char *encode(char *buffer) {
        return value.serialize(buffer);
    }

    char *decode(char *buffer) {
        return value.deserialize(buffer);
    }
};
}
