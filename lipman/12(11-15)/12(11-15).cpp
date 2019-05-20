#include <memory>
#include <iostream>

void process(std::shared_ptr<int> ptr)
{
	std::cout << "inside the process function:" << ptr.use_count() << "\n";
}

void N11()
{
	std::shared_ptr<int> p(new int(42));
	/*
	 * std:: shared_ptr<int>(стр. get ()) создает временный shared_ptr и копирует его. ќднако это не копи€ p. 
	 * ¬ результате, в конце этой основной функции p освободит пам€ть, котора€ была освобождена внутри process (). 
	 * ¬от почему будет создано "double freed or corruption". (повторное освобождение пам€ти)
	 */
	process(std::shared_ptr<int>(p.get()));
}

void N12()
{
	auto p = new int();
	auto sp = std::make_shared<int>();

	/*
	 *  ќк. произойдет копиррование указател€
	 */
	 //process(sp);

	 /*
	  *  ошибка. невозможно преобразовани€ и обычного указател€ в умный
	  */
	  //process(new int());

	  /*
	   *  ошибка. невозможно преобразовани€ и обычного указател€ в умный
	   */
	   //process(p);

	   /*
		*  ок, но воможно двойное освобождение пам€ти
		*/
		//process(std::shared_ptr<int>(p));
}

void N13()
{
	auto sp = std::make_shared<int>();
	auto p = sp.get();
	delete p;

	// двойное освобождение пам€ти
}

void N14()
{
	/*
	 *  struct connection {
	    std::string ip;
	    int port;
	    connection(std::string ip_, int port_):ip(ip_), port(port_){ }
		};

		struct destination {
		    std::string ip;
		    int port;
		    destination(std::string ip_, int port_):ip(ip_), port(port_){ }
		};

		connection connect(destination* pDest)
		{
		    std::shared_ptr<connection> pConn(new connection(pDest->ip, pDest->port));
		    std::cout << "creating connection(" << pConn.use_count() << ")" << std::endl;
		    return *pConn;
		}

		void disconnect(connection pConn)
		{
		    std::cout << "connection close(" << pConn.ip << ":" << pConn.port << ")" << std::endl;
		}

		void end_connection(connection *pConn)
		{
		    disconnect(*pConn);
		}

		void f(destination &d)
		{
		    connection conn = connect(&d);
		    std::shared_ptr<connection> p(&conn, end_connection);
		    std::cout << "connecting now(" << p.use_count() << ")" << std::endl;
		}

		int main()
		{
		    destination dest("202.118.176.67", 3316);
		    f(dest);
		}
	 */
}

void N15()
{
	//struct connection {
	//	std::string ip;
	//	int port;
	//	connection(std::string ip_, int port_) :ip(ip_), port(port_) { }
	//};
	//struct destination {
	//	std::string ip;
	//	int port;
	//	destination(std::string ip_, int port_) :ip(ip_), port(port_) { }
	//};

	//connection connect(destination* pDest)
	//{
	//	std::shared_ptr<connection> pConn(new connection(pDest->ip, pDest->port));
	//	std::cout << "creating connection(" << pConn.use_count() << ")" << std::endl;
	//	return *pConn;
	//}

	//void disconnect(connection pConn)
	//{
	//	std::cout << "connection close(" << pConn.ip << ":" << pConn.port << ")" << std::endl;
	//}

	//void f(destination &d)
	//{
	//	connection conn = connect(&d);
	//	std::shared_ptr<connection> p(&conn, [](connection *p) { disconnect(*p); });
	//	std::cout << "connecting now(" << p.use_count() << ")" << std::endl;
	//}

	//int main()
	//{
	//	destination dest("202.118.176.67", 3316);
	//	f(dest);
	//}
}

int main(int argc, char* argv[])
{
	N11();
}
