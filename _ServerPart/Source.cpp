#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <winsock2.h>
#include <Windows.h>
#include <string>
#include "Calculator.h"


using namespace std;



int main()
{
	WORD wVersionRequested;
	WSADATA wsaData;
	wVersionRequested = MAKEWORD(2, 2);
	WSAStartup(wVersionRequested, &wsaData);
	SOCKET s = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in local;
	local.sin_family = AF_INET;
	local.sin_port = htons(1280);
	local.sin_addr.s_addr = htonl(INADDR_ANY);
	int c = bind(s, (struct sockaddr*)&local, sizeof(local));
	int r = listen(s, 5);

	while (true)
	{
		int firstNumber;
		int secondNumber;
		char operation;

		sockaddr_in remote_addr;
		int size = sizeof(remote_addr);
		SOCKET s2 = accept(s, (struct sockaddr*)&remote_addr, &size);

		int breakCondition;
		while (true)
		{
			breakCondition = recv(s2, reinterpret_cast<char*>(&firstNumber), sizeof(firstNumber), 0);
			if (!breakCondition)
			{
				break;
			}

			breakCondition = recv(s2, reinterpret_cast<char*>(&secondNumber), sizeof(secondNumber), 0);
			if (!breakCondition)
			{
				break;
			}

			breakCondition = recv(s2, &operation, sizeof(operation), 0);
			if (!breakCondition)
			{
				break;
			}


			Calculator calc(firstNumber, secondNumber);

			double result;


			if (operation == '+')
			{
				result = calc.addition();
			}
			else if (operation == '-')
			{
				result = calc.substraction();
			}
			else if (operation == '*')
			{
				result = calc.multiplication();
			}
			else if (operation == '/')
			{
				result = calc.division();
			}

			send(s2, reinterpret_cast<char*>(&result), sizeof(result), 0);
		}

		closesocket(s2);
	}

	WSACleanup();

	return 0;
}
