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

#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <thread>
#include <sys/stat.h>

#include "error_pages.h"

#pragma comment(lib, "Ws2_32.lib")

bool endsWith(const std::string& str, const std::string& suffix) {
    return str.size() >= suffix.size() &&
           str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}

std::string getMimeType(const std::string& path) {
    if (endsWith(path, ".html") || endsWith(path, ".htm") || endsWith(path, ".shtml")) return "text/html";
    if (endsWith(path, ".css")) return "text/css";
    if (endsWith(path, ".xml")) return "text/xml";
    if (endsWith(path, ".gif")) return "image/gif";
    if (endsWith(path, ".jpeg") || endsWith(path, ".jpg")) return "image/jpeg";
    if (endsWith(path, ".js")) return "application/javascript";
    if (endsWith(path, ".atom")) return "application/atom+xml";
    if (endsWith(path, ".rss")) return "application/rss+xml";

    if (endsWith(path, ".mml")) return "text/mathml";
    if (endsWith(path, ".txt")) return "text/plain";
    if (endsWith(path, ".jad")) return "text/vnd.sun.j2me.app-descriptor";
    if (endsWith(path, ".wml")) return "text/vnd.wap.wml";
    if (endsWith(path, ".htc")) return "text/x-component";

    if (endsWith(path, ".avif")) return "image/avif";
    if (endsWith(path, ".png")) return "image/png";
    if (endsWith(path, ".svg") || endsWith(path, ".svgz")) return "image/svg+xml";
    if (endsWith(path, ".tif") || endsWith(path, ".tiff")) return "image/tiff";
    if (endsWith(path, ".wbmp")) return "image/vnd.wap.wbmp";
    if (endsWith(path, ".webp")) return "image/webp";
    if (endsWith(path, ".ico")) return "image/x-icon";
    if (endsWith(path, ".jng")) return "image/x-jng";
    if (endsWith(path, ".bmp")) return "image/x-ms-bmp";

    if (endsWith(path, ".woff")) return "font/woff";
    if (endsWith(path, ".woff2")) return "font/woff2";

    if (endsWith(path, ".jar") || endsWith(path, ".war") || endsWith(path, ".ear")) return "application/java-archive";
    if (endsWith(path, ".json")) return "application/json";
    if (endsWith(path, ".hqx")) return "application/mac-binhex40";
    if (endsWith(path, ".doc")) return "application/msword";
    if (endsWith(path, ".pdf")) return "application/pdf";
    if (endsWith(path, ".ps") || endsWith(path, ".eps") || endsWith(path, ".ai")) return "application/postscript";
    if (endsWith(path, ".rtf")) return "application/rtf";
    if (endsWith(path, ".m3u8")) return "application/vnd.apple.mpegurl";
    if (endsWith(path, ".kml")) return "application/vnd.google-earth.kml+xml";
    if (endsWith(path, ".kmz")) return "application/vnd.google-earth.kmz";
    if (endsWith(path, ".xls")) return "application/vnd.ms-excel";
    if (endsWith(path, ".eot")) return "application/vnd.ms-fontobject";
    if (endsWith(path, ".ppt")) return "application/vnd.ms-powerpoint";
    if (endsWith(path, ".odg")) return "application/vnd.oasis.opendocument.graphics";
    if (endsWith(path, ".odp")) return "application/vnd.oasis.opendocument.presentation";
    if (endsWith(path, ".ods")) return "application/vnd.oasis.opendocument.spreadsheet";
    if (endsWith(path, ".odt")) return "application/vnd.oasis.opendocument.text";
    if (endsWith(path, ".pptx")) return "application/vnd.openxmlformats-officedocument.presentationml.presentation";
    if (endsWith(path, ".xlsx")) return "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet";
    if (endsWith(path, ".docx")) return "application/vnd.openxmlformats-officedocument.wordprocessingml.document";
    if (endsWith(path, ".wmlc")) return "application/vnd.wap.wmlc";
    if (endsWith(path, ".wasm")) return "application/wasm";
    if (endsWith(path, ".7z")) return "application/x-7z-compressed";
    if (endsWith(path, ".cco")) return "application/x-cocoa";
    if (endsWith(path, ".jardiff")) return "application/x-java-archive-diff";
    if (endsWith(path, ".jnlp")) return "application/x-java-jnlp-file";
    if (endsWith(path, ".run")) return "application/x-makeself";
    if (endsWith(path, ".pl") || endsWith(path, ".pm")) return "application/x-perl";
    if (endsWith(path, ".prc") || endsWith(path, ".pdb")) return "application/x-pilot";
    if (endsWith(path, ".rar")) return "application/x-rar-compressed";
    if (endsWith(path, ".rpm")) return "application/x-redhat-package-manager";
    if (endsWith(path, ".sea")) return "application/x-sea";
    if (endsWith(path, ".swf")) return "application/x-shockwave-flash";
    if (endsWith(path, ".sit")) return "application/x-stuffit";
    if (endsWith(path, ".tcl") || endsWith(path, ".tk")) return "application/x-tcl";
    if (endsWith(path, ".der") || endsWith(path, ".pem") || endsWith(path, ".crt")) return "application/x-x509-ca-cert";
    if (endsWith(path, ".xpi")) return "application/x-xpinstall";
    if (endsWith(path, ".xhtml")) return "application/xhtml+xml";
    if (endsWith(path, ".xspf")) return "application/xspf+xml";
    if (endsWith(path, ".zip")) return "application/zip";

    if (endsWith(path, ".bin") || endsWith(path, ".exe") || endsWith(path, ".dll")) return "application/octet-stream";
    if (endsWith(path, ".deb")) return "application/octet-stream";
    if (endsWith(path, ".dmg")) return "application/octet-stream";
    if (endsWith(path, ".iso") || endsWith(path, ".img")) return "application/octet-stream";
    if (endsWith(path, ".msi") || endsWith(path, ".msp") || endsWith(path, ".msm")) return "application/octet-stream";

    if (endsWith(path, ".mid") || endsWith(path, ".midi") || endsWith(path, ".kar")) return "audio/midi";
    if (endsWith(path, ".mp3")) return "audio/mpeg";
    if (endsWith(path, ".ogg")) return "audio/ogg";
    if (endsWith(path, ".m4a")) return "audio/x-m4a";
    if (endsWith(path, ".ra")) return "audio/x-realaudio";

    if (endsWith(path, ".3gpp") || endsWith(path, ".3gp")) return "video/3gpp";
    if (endsWith(path, ".ts")) return "video/mp2t";
    if (endsWith(path, ".mp4")) return "video/mp4";
    if (endsWith(path, ".mpeg") || endsWith(path, ".mpg")) return "video/mpeg";
    if (endsWith(path, ".mov")) return "video/quicktime";
    if (endsWith(path, ".webm")) return "video/webm";
    if (endsWith(path, ".flv")) return "video/x-flv";
    if (endsWith(path, ".m4v")) return "video/x-m4v";
    if (endsWith(path, ".mng")) return "video/x-mng";
    if (endsWith(path, ".asx") || endsWith(path, ".asf")) return "video/x-ms-asf";
    if (endsWith(path, ".wmv")) return "video/x-ms-wmv";
    if (endsWith(path, ".avi")) return "video/x-msvideo";

    return "text/plain";
}

void handleClient(SOCKET clientSocket) {
    char recvBuffer[4096] = {0};
    int recvLen = recv(clientSocket, recvBuffer, sizeof(recvBuffer) - 1, 0);
    if (recvLen <= 0) {
        std::cerr << "Connection closed: " << WSAGetLastError() << "\n";
        closesocket(clientSocket);
        return;
    }
    recvBuffer[recvLen] = '\0';

    std::string request(recvBuffer);
    std::string method;
    std::string path = "index.html";

    size_t methodEnd = request.find(' ');
    if (methodEnd != std::string::npos) {
        method = request.substr(0, methodEnd);
    } else {
        send_error_page(clientSocket, 400);
        return;
    }

    if (method != "GET" && method != "HEAD") {
        send_error_page(clientSocket, 400);
        return;
    }

    bool isHeadRequest = (method == "HEAD");

    std::string base_dir = "host_files/";
    size_t start = request.find(' ');
    size_t end = request.find(" HTTP/", start + 1);

    if (start != std::string::npos && end != std::string::npos) {
        std::string req_path = request.substr(start + 1, end - start - 1);
        std::cout << "New Request: " << req_path << "\n";

        if (req_path == "/") {
            path = base_dir + "index.html";
        } else if (req_path.find("..") == std::string::npos) {
            path = base_dir + req_path.substr(1);
        } else {
            send_error_page(clientSocket, 400);
            return;
        }
    } else {
        send_error_page(clientSocket, 400);
        return;
    }

    std::ifstream file(path, std::ios::binary);
    if (!file.is_open()) {
        std::cout << "404 Not Found: " << path << "\n";
        send_error_page(clientSocket, 404);
        return;
    }

    std::stringstream bodyStream;
    bodyStream << file.rdbuf();
    std::string body = bodyStream.str();

    std::string mimeType = getMimeType(path);

    std::string response =
        "HTTP/1.1 200 OK\r\n"
        "Server: mpax235\r\n"
        "Content-Type: " + mimeType + "\r\n"
        "Content-Length: " + std::to_string(body.size()) + "\r\n"
        "Connection: close\r\n\r\n";

    if (!isHeadRequest) {
        response += body;
    }

    size_t totalSent = 0;
    while (totalSent < response.size()) {
        int sent = send(clientSocket, response.c_str() + totalSent,
                        static_cast<int>(response.size() - totalSent), 0);
        if (sent == SOCKET_ERROR) break;
        totalSent += sent;
    }

    shutdown(clientSocket, SD_SEND);
    Sleep(200);
    closesocket(clientSocket);
}

int main() {
    struct stat info;
    if (stat("host_files/mpax235WebServerCSS", &info) == 0 && (info.st_mode & S_IFDIR)) {
        // do nothing
    } else {
        std::cerr << "[WEB SERVER ERROR]: The mpax235WebServerCSS directory does not exist in the host_files directory. Please put back the directory into the host_files directory.";
        return -1;
    }

    WSADATA wsaData;
    SOCKET serverSocket;
    sockaddr_in serverAddr{}, clientAddr{};
    int clientSize = sizeof(clientAddr);

    bool nonLocal = false;

    std::ifstream config("config.txt");
    if (config) {
        std::string line;
        while (std::getline(config, line)) {
            if (line.find("nonLocal = true") != std::string::npos) {
                nonLocal = true;
                break;
            }
        }
        config.close();
    }

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "Unfortunately, the Windows Socket API failed to load :(\n";
        return 1;
    }
    serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serverSocket == INVALID_SOCKET) {
        std::cerr << "Unfortunately, the socket() function failed :( | " << WSAGetLastError() << "\n";
        return 1;
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);

    if (nonLocal) {
        char hostname[256];
        if (gethostname(hostname, sizeof(hostname)) == SOCKET_ERROR) {
            std::cerr << "Unfortunately, the gethostname() function failed :(\n";
            return 1;
        }

        struct addrinfo hints = {}, *info;
        hints.ai_family = AF_INET;
        hints.ai_socktype = SOCK_STREAM;
        hints.ai_protocol = IPPROTO_TCP;

        if (getaddrinfo(hostname, nullptr, &hints, &info) != 0) {
            std::cerr << "Unfortunately, the getaddrinfo() function failed :(\n";
            return 1;
        }

        sockaddr_in* addr = reinterpret_cast<sockaddr_in*>(info->ai_addr);
        serverAddr.sin_addr = addr->sin_addr;

        char ipStr[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &serverAddr.sin_addr, ipStr, sizeof(ipStr));
        std::cout << "The mpax235 Web Server is running at http://" << ipStr << ":8080\n";

        freeaddrinfo(info);
    } else {
        inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);
        std::cout << "The mpax235 Web Server is running at http://localhost:8080\n";
    }

    if (bind(serverSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        std::cerr << "Unfortunately, the bind() function failed :( | " << WSAGetLastError() << "\n";
        return 1;
    }

    if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR) {
        std::cerr << "Unfortunately, the listen() function failed :( | " << WSAGetLastError() << "\n";
        return 1;
    }

    while (true) {
        SOCKET clientSocket = accept(serverSocket, (SOCKADDR*)&clientAddr, &clientSize);
        if (clientSocket == INVALID_SOCKET) {
            std::cerr << "Unfortunately, the accept() function failed :( | " << WSAGetLastError() << "\n";
            continue;
        }

        std::thread clientThread(handleClient, clientSocket);
        clientThread.detach();
    }

    closesocket(serverSocket);
    WSACleanup();
    return 0;
}