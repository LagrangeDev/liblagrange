//
// Created by yizhou on 2024/2/16.
//

module;

#include <string>

export module config;

export enum class BotProtocol {
    WINDOWS = 0, LINUX = 1, MACOSX = 2
};

export struct config_t {
    BotProtocol protocol;
    bool auto_connect = false;
    bool use_ipv6 = false;
    bool optimum_server = false;
    std::string signer_url;
};

export struct app_info_t {
    std::string os, vender, kernel, base_version, current_version;
    std::int32_t build_version, misc_bitmap, pt_os_version;
    std::string pt_version, packet_name, wt_login_sdk, package_sign;
    std::int32_t appid, sub_appid, app_qrcode_id;
    std::uint16_t client_version;
    std::uint32_t main_sig_map;
    std::uint16_t sub_sig_map, nt_login_type;
};

export struct device_info_t {
    std::string guid, mac_addr, device_name, system_kernel, kernel_version;
};

export struct keystore_t {
    std::uint32_t uin;
    std::string uid, passwd;

    struct wtlogin_session_t {
        std::string d2key, d2, tgt;
        std::string qrsign, qrstr, qrurl;
        std::string exchange_key, key_sign, unusual_sign, unusual_cookies,
            captcha_url, device_verify_url;
        std::string temp_passwd, no_pic_sig;
        std::uint16_t sequence;
    } wtlogin_session;

    struct key_collection_t {
        std::string random_key, tgtgt_key;
    } key_collection;
};