/*
MIT License

Copyright (c) 2025 mpax235

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifdef _WIN32
#include <WinSock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#else
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <net/if.h>
#endif

#ifdef _WIN32
#pragma comment(lib, "Ws2_32.lib")
#endif

#ifndef MPAX_SOCKET_H
#define MPAX_SOCKET_H

#ifdef _WIN32
typedef SOCKET              mpax_socket;

#define mpax_socketerror    SOCKET_ERROR
#define mpax_send           SD_SEND
#define mpax_socketaddr     SOCKADDR
#define mpax_invalidsocket  INVALID_SOCKET
#else
typedef int                 mpax_socket;

#define mpax_socketerror    -1
#define mpax_send           SHUT_WR
#define mpax_socketaddr     sockaddr
#define mpax_invalidsocket  -1
#endif

int mpax_error(void);
int mpax_closesocket(int socket);

#endif // MPAX_SOCKET_H