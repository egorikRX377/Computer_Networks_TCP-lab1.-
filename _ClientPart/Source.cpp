#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <iostream>
#include <winsock2.h>
#include <Windows.h>
#include <conio.h>
#include "Helper.h"
#include <string>


using namespace std;


int main()
{
	WORD wVersionRequested;
	WSADATA wsaData;
	wVersionRequested = MAKEWORD(2, 2);
	WSAStartup(wVersionRequested, &wsaData);

	struct sockaddr_in peer;
	peer.sin_family = AF_INET;
	peer.sin_port = htons(1280);

	peer.sin_addr.s_addr = inet_addr("127.0.0.1");

	SOCKET s = socket(AF_INET, SOCK_STREAM, 0);

	connect(s, (struct sockaddr*)&peer, sizeof(peer));

	int firstNumber;
	int secondNumber;
	char operation;

	firstNumber = correctNumberInput<int>("Enter the first number please: ");
	secondNumber = correctNumberInput<int>("Enter the second number please: ");
	operation = inputCorrectMathOperation();

	try
	{
		if (operation == '/' && secondNumber == 0)
		{
			throw exception("Error: Division by zero!");
		}
	}
	catch (exception& exc)
	{
		cout << exc.what() << endl;
		closesocket(s);

		WSACleanup();

		return -1;
	}

	send(s, reinterpret_cast<char*>(&firstNumber), sizeof(firstNumber), 0);
	send(s, reinterpret_cast<char*>(&secondNumber), sizeof(secondNumber), 0);
	send(s, &operation, sizeof(firstNumber), 0);

	double result;

	if (recv(s, reinterpret_cast<char*>(&result), sizeof(result), 0) != 0)
	{
		cout << "The result is: " << result << endl;
	}

	closesocket(s);

	WSACleanup();

	return 0;
}
