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

#include "include/http_response.h"
#include "include/http_codes.h"
#include <string>
#include <iostream>
#pragma comment(lib, "Ws2_32.lib")

static char mpax235_301_page[] =
"<!DOCTYPE html>\n"
"<html>\n"
"    <head>\n"
"        <title>301 Moved Permanently</title>\n"
"        <link rel=\"stylesheet\" href=\"/mpax235WebServerCSS/serverCSS/httpresponsepage.css\">\n"
"    </head>\n"
"    <body>\n"
"        <center><h1>301 Moved Permanently</h1><center>\n";

static char mpax235_302_page[] =
"<!DOCTYPE html>\n"
"<html>\n"
"    <head>\n"
"        <title>302 Found</title>\n"
"        <link rel=\"stylesheet\" href=\"/mpax235WebServerCSS/serverCSS/httpresponsepage.css\">\n"
"    </head>\n"
"    <body>\n"
"        <center><h1>302 Found</h1><center>\n";

static char mpax235_303_page[] =
"<!DOCTYPE html>\n"
"<html>\n"
"    <head>\n"
"        <title>303 See Other</title>\n"
"        <link rel=\"stylesheet\" href=\"/mpax235WebServerCSS/serverCSS/httpresponsepage.css\">\n"
"    </head>\n"
"    <body>\n"
"        <center><h1>303 See Other</h1><center>\n";

static char mpax235_400_page[] =
"<!DOCTYPE html>\n"
"<html>\n"
"    <head>\n"
"        <title>400 Bad Request</title>\n"
"        <link rel=\"stylesheet\" href=\"/mpax235WebServerCSS/serverCSS/httpresponsepage.css\">\n"
"    </head>\n"
"    <body>\n"
"        <center><h1>400 Bad Request</h1><center>\n";

static char mpax235_403_page[] =
"<!DOCTYPE html>\n"
"<html>\n"
"    <head>\n"
"        <title>403 Forbidden</title>\n"
"        <link rel=\"stylesheet\" href=\"/mpax235WebServerCSS/serverCSS/httpresponsepage.css\">\n"
"    </head>\n"
"    <body>\n"
"        <center><h1>403 Forbidden</h1><center>\n";

static char mpax235_404_page[] =
"<!DOCTYPE html>\n"
"<html>\n"
"    <head>\n"
"        <title>404 Not Found</title>\n"
"        <link rel=\"stylesheet\" href=\"/mpax235WebServerCSS/serverCSS/httpresponsepage.css\">\n"
"    </head>\n"
"    <body>\n"
"        <center><h1>404 Not Found</h1><center>\n";

static char mpax235_429_page[] =
"<!DOCTYPE html>\n"
"<html>\n"
"    <head>\n"
"        <title>429 Too Many Requests</title>\n"
"        <link rel=\"stylesheet\" href=\"/mpax235WebServerCSS/serverCSS/httpresponsepage.css\">\n"
"    </head>\n"
"    <body>\n"
"        <center><h1>429 Too Many Requests</h1><center>\n";

static char mpax235_500_page[] =
"<!DOCTYPE html>\n"
"<html>\n"
"    <head>\n"
"        <title>500 Internal Server Error</title>\n"
"        <link rel=\"stylesheet\" href=\"/mpax235WebServerCSS/serverCSS/httpresponsepage.css\">\n"
"    </head>\n"
"    <body>\n"
"        <center><h1>500 Internal Server Error</h1><center>\n";

static char mpax235_502_page[] =
"<!DOCTYPE html>\n"
"<html>\n"
"    <head>\n"
"        <title>502 Bad Gateway</title>\n"
"        <link rel=\"stylesheet\" href=\"/mpax235WebServerCSS/serverCSS/httpresponsepage.css\">\n"
"    </head>\n"
"    <body>\n"
"        <center><h1>502 Bad Gateway</h1><center>\n";

static char footer[] =
"        <hr><center><span>mpax235</span></center>\n"
"    </body>\n"
"</html>\n";

void send_response_page(SOCKET clientSocket, int httpCode) {
    const char* responseBody = nullptr;
    const char* status = nullptr;

    switch (httpCode) {
        case 301:
            responseBody = mpax235_301_page;
            status = MPAX235_301;
            break;
        case 302:
            responseBody = mpax235_302_page;
            status = MPAX235_302;
            break;
        case 303:
            responseBody = mpax235_303_page;
            status = MPAX235_303;
            break;
        case 400:
            responseBody = mpax235_400_page;
            status = MPAX235_400;
            break;
        case 403:
            responseBody = mpax235_403_page;
            status = MPAX235_403;
            break;
        case 404:
            responseBody = mpax235_404_page;
            status = MPAX235_404;
            break;
        case 429:
            responseBody = mpax235_429_page;
            status = MPAX235_429;
            break;
        case 500:
            responseBody = mpax235_500_page;
            status = MPAX235_500;
            break;
        case 502:
            responseBody = mpax235_502_page;
            status = MPAX235_502;
            break;
        default:
            responseBody = mpax235_500_page;
            status = MPAX235_500;
            break;
    }

    std::string fullBody = std::string(responseBody) + footer;
    std::string response =
        "HTTP/1.1 " + std::string(status) + "\r\n" +
        "Server: mpax235\r\n" +
        "Content-Type: text/html\r\n" +
        "Content-Length: " + std::to_string(strlen(responseBody) + strlen(footer)) + "\r\n" +
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