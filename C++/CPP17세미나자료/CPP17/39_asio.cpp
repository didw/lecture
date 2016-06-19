#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>
using namespace std;
using namespace boost;
using namespace boost::asio;
using namespace boost::asio::ip;

string make_daytime_string()
{
	time_t now = time(0);
	return ctime(&now);
}

int main()
{
	try
	{
		io_service io_service;

		tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 13));

		for (;;)
		{
			tcp::socket socket(io_service);
			acceptor.accept(socket);

			string message = make_daytime_string();// read

			boost::system::error_code ignored_error;
			boost::asio::write(socket, boost::asio::buffer(message), ignored_error);
		}
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}