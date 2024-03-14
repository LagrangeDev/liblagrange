//
// Created by yizhou on 2024/2/16.
//

module;

#include <memory>

export module client;

import config;

namespace liblagrange {

class client_t: public std::enable_shared_from_this<client_t> {
    config_t config {};
};

}