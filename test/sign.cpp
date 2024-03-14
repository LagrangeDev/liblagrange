//
// Created by yizhou on 13/3/2024.
//
#define BOOST_TEST_MODULE SIGN_TEST
#include <boost/asio/io_context.hpp>
#include <boost/asio/awaitable.hpp>
#include <boost/asio/co_spawn.hpp>
#include <boost/asio/detached.hpp>
#include <boost/asio/use_awaitable.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/test/unit_test.hpp>

import sign;

using namespace boost::asio;
using namespace boost::beast;

BOOST_AUTO_TEST_CASE(sign_test) {
    struct signer_t {
        std::string url = "https://sign.libfekit.so/api/sign";
        awaitable<sign_t> sign(std::string_view cmd, int seq, std::string_view body) {
            ip::tcp::resolver resolver(co_await this_coro::executor);
            tcp_stream stream (co_await this_coro::executor);
            flat_buffer buffer;

            auto results = co_await resolver.async_resolve(url, "http", use_awaitable);
            co_await stream.async_connect(results, use_awaitable);

            auto target = std::format("{}/cmd={}&seq={}&src={}", url, cmd, seq, body);
            http::request<http::string_body> request { http::verb::get, target, 11};
            co_await http::async_write(stream, request, use_awaitable);

            http::response<http::string_body> response;
            co_await http::async_read(stream, buffer, response, use_awaitable);
            std::cout << response.body() << std::endl;
            stream.close();
            co_return sign_t{};
        }
        awaitable<std::chrono::milliseconds> test() {
            ip::tcp::resolver resolver(co_await this_coro::executor);
            tcp_stream stream (co_await this_coro::executor);
            flat_buffer buffer;

            auto start = std::chrono::steady_clock::now();

            auto results = co_await resolver.async_resolve(url, "http", use_awaitable);
            co_await stream.async_connect(results, use_awaitable);

            auto target = std::format("{}/ping", url);
            http::request<http::string_body> request { http::verb::get, target, 11};
            co_await http::async_write(stream, request, use_awaitable);

            http::response<http::string_body> response;
            co_await http::async_read(stream, buffer, response, use_awaitable);
            stream.close();

            auto end = std::chrono::steady_clock::now();
            BOOST_CHECK(response.body() == "{\"code\":0}");
            co_return std::chrono::duration_cast<std::chrono::milliseconds>(start - end);
        }
    } signer;
    BOOST_CHECK(sign_provider_c<signer_t>);

    io_context context{};
    co_spawn(context, signer.test(), detached);
    co_spawn(context, signer.sign("sdtfgh", 0, "dtfyguhi"), detached);
    context.run();
}