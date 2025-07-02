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

#include "error_pages.h"
#include "errors.h"
#include <string>
#include <iostream>
#pragma comment(lib, "Ws2_32.lib")

static char mpax235_400_page[] =
"<!DOCTYPE html>\n"
"<html>\n"
"    <head>\n"
"        <title>400 Bad Request</title>\n"
"        <link rel=\"stylesheet\" href=\"/mpax235WebServerCSS/serverCSS/errorpage.css\">\n"
"    </head>\n"
"    <body>\n"
"        <center><h1>400 Bad Request</h1><center>\n";

static char mpax235_404_page[] =
"<!DOCTYPE html>\n"
"<html>\n"
"    <head>\n"
"        <title>404 Not Found</title>\n"
"        <link rel=\"stylesheet\" href=\"/mpax235WebServerCSS/serverCSS/errorpage.css\">\n"
"    </head>\n"
"    <body>\n"
"        <center><h1>404 Not Found</h1><center>\n";

static char mpax235_500_page[] =
"<!DOCTYPE html>\n"
"<html>\n"
"    <head>\n"
"        <title>500 Internal Server Error</title>\n"
"        <link rel=\"stylesheet\" href=\"/mpax235WebServerCSS/serverCSS/errorpage.css\">\n"
"    </head>\n"
"    <body>\n"
"        <center><h1>500 Internal Server Error</h1><center>\n";

static char footer[] =
"        <hr><center><span>mpax235</span></center>\n"
"    </body>\n"
"</html>\n";

void send_error_page(SOCKET clientSocket, int errorCode) {
    const char* errorBody = nullptr;
    const char* status = nullptr;

    switch (errorCode) {
        case 400:
            errorBody = mpax235_400_page;
            status = MPAX235_400;
            break;
        case 404:
            errorBody = mpax235_404_page;
            status = MPAX235_404;
            break;
        case 500:
            errorBody = mpax235_500_page;
            status = MPAX235_500;
            break;
        default:
            errorBody = mpax235_500_page;
            status = MPAX235_500;
            break;
    }

    std::string fullBody = std::string(errorBody) + footer;
    std::string response =
        "HTTP/1.1 " + std::string(status) + "\r\n" +
        "Server: mpax235\r\n" +
        "Content-Type: text/html\r\n" +
        "Content-Length: " + std::to_string(strlen(errorBody) + strlen(footer)) + "\r\n" +
        "Connection: close\r\n\r\n" +
        fullBody;

    const char* data = response.c_str();
    int totalSent = 0;
    int toSend = static_cast<int>(response.size());

    while (totalSent < toSend) {
        int sent = send(clientSocket, data + totalSent, toSend - totalSent, 0);
        if (sent == SOCKET_ERROR) {
            std::cerr << "Unfortunately, the sending failed :( | " << WSAGetLastError() << "\n";
            break;
        }
        totalSent += sent;
    }

    int sent = send(clientSocket, response.c_str(), (int)response.length(), 0);
    if (sent == SOCKET_ERROR) {
        std::cerr << "Unfortunately, the send() function failed :( | " << WSAGetLastError() << "\n";
    }

    shutdown(clientSocket, SD_SEND);
    Sleep(200);
    closesocket(clientSocket);
}