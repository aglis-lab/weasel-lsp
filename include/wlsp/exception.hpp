#pragma once

#define THROW(ExceptionType, message) \
    throw ExceptionType(std::string(message) + " in " + __FILE__ + ':' + std::to_string(__LINE__) + ':' + __func__)

#define NOT_IMPLEMENTED THROW(std::runtime_error, "method is not implemented!")
