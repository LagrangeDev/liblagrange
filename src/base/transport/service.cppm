//
// Created by yizhou on 13/3/2024.
//

module;

#include <boost/asio/awaitable.hpp>
#include <boost/asio/use_awaitable.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/experimental/channel.hpp>

export module service;

import serialize;

namespace rpc {

using namespace boost::asio;
using namespace boost::asio::experimental;

export template<typename Request, typename Response>
requires serializable_c<Request> && serializable_c<Response>
class service {
    io_context context{};
    ip::tcp::socket socket;
    std::string buffer;

public:
    service(std::string_view servant, std::string_view func): socket(context), buffer(1024, '\0') {
    }

    awaitable<Response> call(const Request& request) {
        buffer.resize(request.size(), '\0');
        request.encode(buffer.data());
        co_await socket.async_write_some(boost::asio::buffer(buffer), use_awaitable);
        co_await socket.async_read_some(boost::asio::buffer(buffer), use_awaitable);
        Response response;
        response.decode(buffer.data());
        co_return response;
    }

    awaitable<void> listen(channel<void(boost::system::error_code, Request)>& channel) {
        while (socket.is_open()) {
            co_await socket.async_read_some(boost::asio::buffer(buffer), use_awaitable);
            Request request;
            request.decode(buffer.data());
            co_await channel.try_send(request, use_awaitable);
        }
    }
};

}
