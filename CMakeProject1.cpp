// CMakeProject1.cpp: 定义应用程序的入口点。
//

#include "CMakeProject1.h"

using namespace std;

int main()
{
	asio::io_context io;

	asio::steady_timer t(io, asio::chrono::seconds(1));

	t.wait();

	std::cout << "Hello, world!" << std::endl;
	cout << "Hello CMake。" << endl;
	system("pause");
	return 0;
}
