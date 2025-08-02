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
#include "include/http_response_elements.h"
#include <iostream>
#include <fstream>
#include <sstream>
#pragma comment(lib, "Ws2_32.lib")

void send_response_page(SOCKET clientSocket, int httpCode) {
    const char* responseBody = nullptr;
    const char* status = nullptr;
    bool footerEnabled = true;
    bool showVersionTag = false;

    std::string stringFor404Path;
    std::string error404PagePath = "default";

    std::ifstream config("config.txt");
    if (config) {
        std::string line;
        while (std::getline(config, line)) {
            size_t pos = line.find("error404PagePath =");
            if (pos != std::string::npos) {
                std::string value = line.substr(pos + 18);
                value.erase(0, value.find_first_not_of(" \t"));
                value.erase(value.find_last_not_of(" \t") + 1);

                if (value != "default") {
                    error404PagePath = value;
                } else {
                    // do nothing
                }
            }

            if (line.find("showVersionTag = true") != std::string::npos) {
                showVersionTag = true;
            }
        }
        config.close();
    }

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
        case 307:
            responseBody = mpax235_307_page;
            status = MPAX235_307;
            break;
        case 308:
            responseBody = mpax235_308_page;
            status = MPAX235_308;
            break;
        case 400:
            responseBody = mpax235_400_page;
            status = MPAX235_400;
            break;
        case 401:
            responseBody = mpax235_401_page;
            status = mpax235_401_page;
            break;
        case 402:
            responseBody = mpax235_402_page;
            status = MPAX235_402;
            break;
        case 403:
            responseBody = mpax235_403_page;
            status = MPAX235_403;
            break;
        case 404:
            if (error404PagePath != "default") {
                std::string hostFiles = "host_files/";
                error404PagePath = hostFiles + error404PagePath;
                std::ifstream custom404(error404PagePath);
                if (custom404) {
                    std::stringstream buffer;
                    buffer << custom404.rdbuf();
                    stringFor404Path = buffer.str();
                    responseBody = stringFor404Path.c_str();
                    footerEnabled = false;
                    custom404.close();
                } else {
                    std::cerr << "The custom 404 page cannot be found :( | " << error404PagePath << " | Using fallback page." << "\n";
                    responseBody = mpax235_404_page;
                }
            } else {
                responseBody = mpax235_404_page;
            }

            status = MPAX235_404;
            break;
        case 405:
            responseBody = mpax235_405_page;
            status = MPAX235_405;
            break;
        case 406:
            responseBody = mpax235_406_page;
            status = MPAX235_406;
            break;
        case 408:
            responseBody = mpax235_408_page;
            status = MPAX235_408;
            break;
        case 409:
            responseBody = mpax235_409_page;
            status = MPAX235_409;
            break;
        case 410:
            responseBody = mpax235_410_page;
            status = MPAX235_410;
            break;
        case 411:
            responseBody = mpax235_411_page;
            status = MPAX235_411;
            break;
        case 412:
            responseBody = mpax235_412_page;
            status = MPAX235_412;
            break;
        case 413:
            responseBody = mpax235_413_page;
            status = MPAX235_413;
            break;
        case 414:
            responseBody = mpax235_414_page;
            status = MPAX235_414;
            break;
        case 415:
            responseBody = mpax235_415_page;
            status = MPAX235_415;
            break;
        case 416:
            responseBody = mpax235_416_page;
            status = MPAX235_416;
            break;
        case 421:
            responseBody = mpax235_421_page;
            status = MPAX235_421;
            break;
        case 429:
            responseBody = mpax235_429_page;
            status = MPAX235_429;
            break;
        case 494:
            responseBody = mpax235_494_page;
            status = MPAX235_494;
            break;
        case 495:
            responseBody = mpax235_495_page;
            status = MPAX235_495;
            break;
        case 496:
            responseBody = mpax235_496_page;
            status = MPAX235_496;
            break;
        case 497:
            responseBody = mpax235_497_page;
            status = MPAX235_497;
            break;
        case 498:
            responseBody = mpax235_498_page;
            status = MPAX235_498;
            break;
        case 500:
            responseBody = mpax235_500_page;
            status = MPAX235_500;
            break;
        case 501:
            responseBody = mpax235_501_page;
            status = MPAX235_501;
            break;
        case 502:
            responseBody = mpax235_502_page;
            status = MPAX235_502;
            break;
        case 503:
            responseBody = mpax235_503_page;
            status = MPAX235_503;
            break;
        case 504:
            responseBody = mpax235_504_page;
            status = MPAX235_504;
            break;
        case 505:
            responseBody = mpax235_505_page;
            status = MPAX235_505;
            break;
        case 507:
            responseBody = mpax235_507_page;
            status = MPAX235_507;
            break;
        default:
            responseBody = mpax235_500_page;
            status = MPAX235_500;
            break;
    }

    std::string fullBody = std::string(responseBody);
    if (footerEnabled) {
        if (showVersionTag == true) {
            fullBody += footer;
        } else {
            fullBody += footerNoVersionTag;
        }
    }

    std::string paddingComments;
    for (int i = 0; i < 16; ++i) {
        paddingComments += padding;
    }

    std::string response =
        "HTTP/1.1 " + std::string(status) + "\r\n" +
        "Server: mpax235\r\n" +
        "Content-Type: text/html\r\n" +
        "Content-Length: " + std::to_string(fullBody.length() + paddingComments.length()) + "\r\n" +
        "Connection: close\r\n\r\n" +
        fullBody + paddingComments;

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