#include <boost/asio/io_service.hpp>
#include <boost/test/unit_test.hpp>

#include <dudp/server.hpp>

using namespace std;

using boost::asio::io_service;

using namespace dudp;

BOOST_AUTO_TEST_SUITE(dudp_server_test_suite)

BOOST_AUTO_TEST_CASE(dudp_server_new_test_case)
{
    io_service io_service;

    server srv(io_service, 1234);

    io_service.run();
}

BOOST_AUTO_TEST_SUITE_END()

// vim:set sw=4 ts=4 et:
