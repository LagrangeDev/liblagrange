//
// Created by yizhou on 7/3/2024.
//
module;

#include <string>
#define DEFINE_SERIALIZABLE(...)   \
    size_t size() { return size_of(__VA_ARGS__); } \
    char* encode(char* buffer) { return serialize(buffer, __VA_ARGS__); } \
    char* decode(char* buffer) { return deserialize(buffer, __VA_ARGS__); }

import proto;
import json;
import serialize;

export module ntlogin;

namespace sso {

namespace key {
export struct exchange_decrypted_t {
    proto::required<std::vector<char>, 1> gcm_calc;
    proto::required<std::vector<char>, 2> sign;
    proto::required<uint32_t, 3> expiration;
    DEFINE_SERIALIZABLE(gcm_calc, sign, expiration)
};

export struct exchange_plain_t {
    proto::required<std::string, 1> uin;
    proto::required<std::vector<char>, 2> guid;
    DEFINE_SERIALIZABLE(uin, guid)
};

export struct exchange_t {
    proto::required<std::vector<char>, 1> pubkey;
    proto::required<int, 2> type;
    proto::required<std::vector<char>, 3> gcm_calc_1;
    proto::required<uint32_t, 4> timestamp;
    proto::required<std::vector<char>, 5> gcm_calc_2;
    DEFINE_SERIALIZABLE(pubkey, type, gcm_calc_1, timestamp, gcm_calc_2)
};

export struct exchange_response_t {
    proto::required<std::vector<char>, 1> gcm_encrypted;
    proto::required<std::vector<char>, 2> body;
    proto::required<std::vector<char>, 3> pubkey;
    DEFINE_SERIALIZABLE(gcm_encrypted, body, pubkey)
};
}

namespace ntlogin {

export struct encrypted_data_t {
    proto::optional<std::vector<char>, 1> sign;
    proto::optional<std::vector<char>, 3> gcm_calc;
    proto::optional<int, 4> type;
    DEFINE_SERIALIZABLE(sign, gcm_calc, type)
};

export struct captcha_url_t {
    proto::required<std::string, 3> url;
    DEFINE_SERIALIZABLE(url)
};

export struct captcha_submit_t {
    proto::required<std::string, 1> ticket;
    proto::required<std::string, 2> rand_str;
    proto::required<std::string, 3> aid;
    DEFINE_SERIALIZABLE(ticket, rand_str, aid)
};

export struct cookie_t {
    proto::optional<std::string, 1> cookie;
    DEFINE_SERIALIZABLE(cookie)
};

export struct credentials_t {
    proto::required<std::vector<char>, 3> temp_passwd;
    proto::required<std::vector<char>, 4> tgt;
    proto::required<std::vector<char>, 5> d2;
    proto::required<std::vector<char>, 6> d2key;
    DEFINE_SERIALIZABLE(temp_passwd, tgt, d2, d2key)
};

export struct error_t {
    proto::required<uint32_t, 1> code;
    proto::required<std::string, 2> tag;
    proto::required<std::string, 3> message;
    proto::optional<std::string, 4> new_device_verify_url;
    DEFINE_SERIALIZABLE(code, tag, message, new_device_verify_url)
};

export struct system_t {
    proto::optional<std::string, 1> os;
    proto::optional<std::string, 2> name;
    proto::required<int, 3> type = 7;
    proto::optional<std::vector<char>, 4> guid;
    DEFINE_SERIALIZABLE(os, name, type, guid)
};

export struct uid_t {
    proto::required<std::string, 2> uid;
    DEFINE_SERIALIZABLE(uid)
};

export struct uin_t {
    proto::optional<std::string, 1> uin;
    DEFINE_SERIALIZABLE(uin)
};

export struct unusual_t {
    proto::optional<std::vector<char>, 2> sig;
    DEFINE_SERIALIZABLE(sig)
};

export struct version_t {
    proto::optional<std::string, 1> kernel_version;
    proto::required<int, 2> app_id;
    proto::optional<std::string, 3> package_name;
    DEFINE_SERIALIZABLE(kernel_version, app_id, package_name)
};

export struct easylogin_t {
    proto::optional<std::vector<char>, 1> temp_passwd;
    proto::optional<captcha_submit_t, 2> captcha;
    DEFINE_SERIALIZABLE(temp_passwd, captcha)
};

export struct header_t {
    proto::optional<uin_t, 1> uin;
    proto::optional<system_t, 2> system;
    proto::optional<version_t, 3> version;
    proto::optional<error_t, 4> error;
    proto::optional<cookie_t, 5> cookie;
    DEFINE_SERIALIZABLE(uin, system, version, error, cookie)
};

export struct response_body_t {
    proto::optional<credentials_t, 1> credentials;
    proto::optional<captcha_url_t, 2> captcha;
    proto::optional<unusual_t, 3> unusual;
    proto::optional<uid_t, 4> uid;
    DEFINE_SERIALIZABLE(credentials, captcha, unusual, uid)
};

export struct easylogin_request_t {
    proto::optional<header_t, 1> header;
    proto::optional<easylogin_t, 2> body;
    DEFINE_SERIALIZABLE(header, body)
};

export struct response_t {
    proto::optional<header_t, 1> header;
    proto::optional<response_body_t, 2> body;
    DEFINE_SERIALIZABLE(header, body)
};

}

}