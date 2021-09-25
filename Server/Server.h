#ifndef OMOK_SERVER_H
#define OMOK_SERVER_H
#define _CRT_SECURE_NO_WARNINGS
#pragma comment (lib, "ws2_32.lib")
#include <iostream>
using namespace std;
#include <Winsock.h>
#include <vector>
#include "Util.h"
#include "Client.h"

static class Server {
private:
	static SOCKET serverSocket;
	static vector<Client*> connections;
	static WSAData wsaData;
	static SOCKADDR_IN serverAddress;
	static int nextID;
	static Util util;
public:
	static void start();
	static int clientCountInRoom(int roomID);
	static void playClient(int roomID); 
	static void exitClient(int roomID);
	static void putClient(int roomID, int x, int y);
	static void fullClient(Client* client);
	static void enterClient(Client* client);
	static void ServerThread(Client* client);
};
#endif // !OMOK_SERVER_H

