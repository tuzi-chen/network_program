#include "asio/include/asio.hpp"



void creatEndPoint()
{
	/*
	To sum up, the endpoints serve two goals:
		1. The client application uses an endpoint to designate a particular server application it
			wants to communicate with.

		2. The server application uses an endpoint to specify a local IP address and a port
			number on which it wants to receive incoming messages from clients. If there is more
			than one IP address on the host, the server application will want to create a special
			endpoint representing all IP addresses at once.
			服务端多IP的情况
	*/

	/*
	** Creating an endpoint in the client to designate the server

	The following algorithm describes steps required to perform in the client application to create
	an endpoint designating a server application the client wants to communicate with. Initially,
	the IP address is represented as a string in the dot-decimal notation if this is an IPv4 address
	or in hexadecimal notation if this is an IPv6 address:
		1. Obtain the server application's IP address and port number. The IP address should be
		specifed as a string in the dot-decimal (IPv4) or hexadecimal (IPv6) notation.
		获取ip地址和端口号

		2. Represent the raw IP address as an object of the asio::ip::address class.
		代表ip地址的asio::ip::address对象

		3. Instantiate the object of the asio::ip::tcp::endpoint class from the address
		object created in step 2 and a port number.
		用1,2步骤的实例化asio::ip::tcp::endpoint对象

		4. The endpoint is ready to be used to designate the server application in Boost.Asio
		communication related methods.
	*/
	std::string raw_ip_addr = "127.0.0.1";
	unsigned short port_num = 3333;

	asio::error_code ec;

	asio::ip::address ip_address =
		asio::ip::address::from_string(raw_ip_addr, ec);

	if (ec.value() != 0)
	{
		// Provided IP address is invalid. Breaking execution.
		std::cout
			<< "Failed to parse the IP address. Error code = "
			<< ec.value() << ". Message: " << ec.message();
		return ec.value();
	}
	asio::ip::tcp::endpoint ep(ip_address, port_num);

	// Step 1. Here we assume that the server application has
//already obtained the protocol port number.
	unsigned short port_num_server = 3333;
	// Step 2. Create special object of asio::ip::address class
	// that specifies all IP-addresses available on the host. Note
	// that here we assume that server works over IPv6 protocol.
	asio::ip::address ip_address_server = asio::ip::address_v6::any();
	// Step 3.
	asio::ip::tcp::endpoint ep(ip_address_server, port_num_server);
	// Step 4. The endpoint is created and can be used to
	// specify the IP addresses and a port number on which
	// the server application wants to listen for incoming
	// connections.

}
