#if !defined(_DUDP_SERVER_HPP_)
#define _DUDP_SERVER_HPP_

#include <array>
#include <memory>
#include <string>

#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/udp.hpp>

namespace dudp {

class
server
{
private:
    boost::asio::ip::udp::socket socket_;
    boost::asio::ip::udp::endpoint remote_endpoint_;
    std::array<char, 1024> recv_buffer_;

public:
    server(boost::asio::io_service &service, uint16_t port);

protected:
    void start_receive();
    void handle_receive(const boost::system::error_code &error, std::size_t bytes_transferred);
    void handle_send(std::shared_ptr<std::string> message, const boost::system::error_code &error, std::size_t bytes_transferred);
};

}

#endif // !defined(_DUDP_SERVER_HPP_)

// vim:set sw=4 ts=4 et:
