#include <boost/asio/placeholders.hpp>
#include <boost/bind.hpp>

#include <dudp/server.hpp>

using namespace std;

using boost::asio::buffer;
using boost::asio::io_service;
using boost::asio::ip::udp;
using boost::asio::placeholders::bytes_transferred;
using boost::asio::placeholders::error;

using namespace dudp;

server::server(io_service &service, uint16_t port)
    : socket_(service, udp::endpoint(udp::v6(), port))
{
    start_receive();
}

void
server::start_receive()
{
    socket_.async_receive_from(buffer(recv_buffer_), remote_endpoint_, boost::bind(&server::handle_receive, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

void
server::handle_receive(const boost::system::error_code &error, std::size_t bytes_transferred)
{
    if (error && error != boost::asio::error::message_size) {
        // TODO warn
        return;
    }

    shared_ptr<string> message = make_shared<string>(&recv_buffer_[0], bytes_transferred);

    if (*message == "die") {
        return;
    }

    socket_.async_send_to(buffer(*message), remote_endpoint_, boost::bind(&server::handle_send, this, message, error, bytes_transferred));

    start_receive();
}

void
server::handle_send(shared_ptr<std::string> message, const boost::system::error_code &error, std::size_t bytes_transferred)
{
}

// vim:set sw=4 ts=4 et:
