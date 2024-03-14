//
// Created by yizhou on 2024/2/16.
//

module;

#include <string>
#include <concepts>
#include <boost/asio/awaitable.hpp>

export module sign;

namespace net = boost::asio;

export struct sign_t {
    std::string sign;
    std::string token;
    std::string extra;
};

export template<typename SignProvider>
concept sign_provider_c = requires(SignProvider provider)
{
    { provider.sign("", 0, "") } -> std::same_as<net::awaitable<sign_t>>;
    { provider.test() } -> std::same_as<net::awaitable<std::chrono::milliseconds>>;
};