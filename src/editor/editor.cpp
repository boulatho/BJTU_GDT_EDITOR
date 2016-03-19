#include			<iostream>
#include			<stdlib.h>
#include			<string.h>
#include			"../lib/SocketAPI/SocketTCPClient.hpp"
#include			"../lib/SocketAPI/Select/FDSet/FDSet.hpp"
#include			"../lib/SocketAPI/Select/Select.hpp"
#include			"Thread.hpp"

#ifdef			WIN32
#include		<WinSock2.h>
#endif

void*			inputHandling(void *param)
{
	std::string			entry;
	SocketTCPClient		*client;

	client = (SocketTCPClient*)param;
	while (true)
	{
		std::getline(std::cin, entry);
		client->send(entry.c_str(), entry.length());
	}
}

int				main(int ac, char **av) {
    SocketTCPClient		client;
    FDSet			fdSet;
	char			buff[1024];
 //   std::string			entry;
    int				nbRead;
	Thread			inputThread;
	struct timeval tv;


    if (ac != 3)
    {
	std::cout << "./editor host port" << std::endl;
	return (0);
    }
	if (!client.start())
		return -1;
	if (!client.connectToServer(av[1], atoi(av[2])))
		return -1;
	inputThread.create(inputHandling, &client);
    while (true)
    {
		tv.tv_sec = 0;
		tv.tv_usec = 10;
		 fdSet.zero();
        fdSet.set(&client);
        if (!Select::call(&fdSet, NULL, &tv))
	{
	    std::cout << "Editor : Socket managment failed" << std::endl;
	    return (-1);
	}
        if (fdSet.isset(&client))
        {
            memset(buff, 0, 1024);
            if ((nbRead = client.receive(buff, 1024)) == 0)
            {
                client.close();
                std::cout << "Server left" << std::endl;
                return 0;
            }
	    buff[nbRead] = 0;
            if (std::string(buff) == "BIENVENU")
            {
                client.send("editor|editor", 13);
            }
            if (std::string(buff) == "kick")
            {
                std::cout << "You are kicked by server" << std::endl;
                return (0);
            }
        }
     /*   if (fdSet.isset(0))
        {
            std::getline(std::cin, entry);
            client.send(entry.c_str(), entry.length());
        }      */
    }
}
