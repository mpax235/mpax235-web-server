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

#include <iostream>
#include <fstream>
#include <sstream>
#include <thread>
#include <sys/stat.h>
#include <cctype>

#include "socket/include/mpax_socket.h"
#include "http/include/http_response.h"
#include "info/include/defines.h"
#include "info/include/server_info.h"

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

void handleClient(mpax_socket clientSocket) {
    bool showVersionTag = false;
    bool inMaintenance = false;

    std::ifstream config("config.txt");
    if (config) {
        std::string line;
        while (std::getline(config, line)) {
            if (line.find("showVersionTag = true") != std::string::npos) {
                showVersionTag = true;
            }

            if (line.find("inMaintenance = true") != std::string::npos) {
                inMaintenance = true;
            }
        }
        config.close();
    }

    char recvBuffer[4096] = {0};

    #ifdef _WIN32
    DWORD timeout = 10000;
    setsockopt(clientSocket, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(timeout));
    #else
    struct timeval timeout;
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;
    setsockopt(clientSocket, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));
    #endif

    int recvLen = recv(clientSocket, recvBuffer, sizeof(recvBuffer) - 1, 0);
    if (recvLen <= 0) {
        #ifdef _WIN32
        int err = mpax_error();
        if (err == WSAETIMEDOUT) {
            std::cerr << "\033[31m[408] Request Timeout\033[0m\n";
            send_response_page(clientSocket, 408);
        } else {
            std::cerr << "Connection closed: " << err << "\n";
        }
        mpax_closesocket(clientSocket);
        #else
        if (errno == EWOULDBLOCK || errno == EAGAIN) {
            std::cerr << "\033[31m[408] Request Timeout\033[0m\n";
            send_response_page(clientSocket, 408);
        } else {
            std::cerr << "Connection closed: " << errno << "\n";
        }
        mpax_closesocket(clientSocket);
        #endif
        
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
        send_response_page(clientSocket, 400);
        return;
    }

    if (method != "GET" && method != "HEAD") {
        send_response_page(clientSocket, 405);
        return;
    }

    bool isHeadRequest = (method == "HEAD");

    std::string base_dir = "host_files/";
    size_t start = request.find(' ');
    size_t end = request.find(" HTTP/", start + 1);
    std::string req_path = request.substr(start + 1, end - start - 1);

    if (start != std::string::npos && end != std::string::npos) {
        if (req_path.length() > 3072) {
            std::cout << "\033[31m[414] URI Too Long: " << req_path << "\033[0m\n";
            send_response_page(clientSocket, 414);
            return;
        }

        size_t percent_pos = req_path.find('%');
        if (percent_pos != std::string::npos) {
            if (percent_pos + 2 >= req_path.length()) {
                std::cout << "\033[31m[400] Bad Request: " << req_path << "\033[0m\n";
                send_response_page(clientSocket, 400);
                return;
            }

            char hex1 = req_path[percent_pos + 1];
            char hex2 = req_path[percent_pos + 2];

            if (!std::isxdigit(hex1) || !std::isxdigit(hex2)) {
                std::cout << "\033[31m[400] Bad Request: " << req_path << "\033[0m\n";
                send_response_page(clientSocket, 400);
                return;
            }
        }

        if (inMaintenance) {
            std::cout << "\033[31m[503] Service Unavailable: " << req_path << "\033[0m\n";
            send_response_page(clientSocket, 503);
            return;
        }

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // this will be used in the event that this web server is proxying the Apache HTTP Server (still being worked on)
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        if (req_path == "/.htaccess") {
            std::cout << "\033[31m[403] Forbidden: " << req_path << "\033[0m\n";
            send_response_page(clientSocket, 403);
            return;
        }
        /////////////////////////////////////////////////////////////////////////////////////////

        if (req_path.find("..") != std::string::npos) {
            sockaddr_storage clientAddr;
            #ifdef _WIN32
            int addrLen = sizeof(clientAddr);
            #else
            socklen_t addrLen = sizeof(clientAddr);
            #endif
            char ipStr[INET6_ADDRSTRLEN] = {0};

            if (getpeername(clientSocket, (sockaddr*)&clientAddr, &addrLen) == 0) {
                void* addrPtr = nullptr;

                if (clientAddr.ss_family == AF_INET) {
                    addrPtr = &((sockaddr_in*)&clientAddr)->sin_addr;
                } else if (clientAddr.ss_family == AF_INET6) {
                    addrPtr = &((sockaddr_in6*)&clientAddr)->sin6_addr;
                }
                
                if (addrPtr && inet_ntop(clientAddr.ss_family, addrPtr, ipStr, sizeof(ipStr))) {
                    std::cout << "\033[31m[494] Path Traversal attack blocked: IP " << ipStr << " tried to do " << req_path << "\033[0m\n";
                }
            } else {
                std::cout << "\033[31m[494] Path Traversal attack blocked: " << req_path << "\033[0m\n";
            }
            send_response_page(clientSocket, 494);
            return;
        }

        if (req_path.empty() || req_path[0] != '/') {
            std::cout << "\033[31m[501] Method Not Implemented: " << req_path << "\033[0m\n";
            send_response_page(clientSocket, 501);
            return;
        }

        if (req_path == "/") {
            path = base_dir + "index.html";
        } else if (req_path.find("..") == std::string::npos) {
            path = base_dir + req_path.substr(1);
        } else {
            std::cout << "\033[31m[400] Bad Request: " << req_path << "\033[0m\n";
            send_response_page(clientSocket, 400);
            return;
        }
    } else {
        std::cout << "\033[31m[400] Bad Request: " << req_path << "\033[0m\n";
        send_response_page(clientSocket, 400);
        return;
    }

    std::ifstream file(path, std::ios::binary);
    if (!file.is_open()) {
        std::cout << "\033[31m[404] Not Found: " << req_path << "\033[0m\n";
        send_response_page(clientSocket, 404);
        return;
    } else {
        std::cout << "\033[32m[200] OK: " << req_path << "\033[0m\n";
    }

    std::stringstream bodyStream;
    bodyStream << file.rdbuf();
    std::string body = bodyStream.str();

    std::string mimeType = getMimeType(path);

    std::string serverHeader;

    if (showVersionTag) {
        #ifdef BUILD
        #ifdef _WIN32
        serverHeader = "mpax235 WS/build " + std::to_string(buildVersion) + " (Windows)";
        #else
        serverHeader = "mpax235 WS/" + std::to_string(buildVersion) + " (Linux)";
        #endif
        #else
        #ifdef _WIN32
        serverHeader = "mpax235 WS/" + releaseVersion + " (Windows)";
        #else
        serverHeader = "mpax235 WS/" + releaseVersion + " (Linux)";
        #endif
        #endif
    } else {
        serverHeader = "mpax235 WS";
    }

    std::string response =
        "HTTP/1.1 200 OK\r\n"
        "Server: " + serverHeader + "\r\n"
        "Content-Type: " + mimeType + "\r\n"
        "Content-Length: " + std::to_string(body.size()) + "\r\n"
        "Connection: close\r\n\r\n";

    if (!isHeadRequest) {
        try {
            response += body;
        } catch (const std::exception& ex) {
            std::cout << "\033[31m[500] Internal Server Error: " << ex.what() << "\033[0m\n";
            send_response_page(clientSocket, 500);
            return;
        }
    }

    size_t totalSent = 0;
    while (totalSent < response.size()) {
        int sent = send(clientSocket, response.c_str() + totalSent,
                        static_cast<int>(response.size() - totalSent), 0);
        if (sent == mpax_socketerror) break;
        totalSent += sent;
    }

    shutdown(clientSocket, mpax_send);
    #ifdef _WIN32
    Sleep(200);
    #else
    usleep(200000);
    #endif
    mpax_closesocket(clientSocket);
}

int main(int argc, char *argv[]) {
    int port = (argc > 1) ? std::atoi(argv[1]) : 8080;
    if (port > 9999 || port < 2) port = 8080;
    
    /* unused since build 14
    struct stat info;
    if (stat("host_files/mpax235WebServerCSS", &info) == 0 && (info.st_mode & S_IFDIR)) {
        // do nothing
    } else {
        std::cerr << "[WEB SERVER ERROR]: The mpax235WebServerCSS directory does not exist in the host_files directory. Please put back the directory into the host_files directory.";
        return -1;
    }
    */

    #ifdef _WIN32
    WSADATA wsaData;
    mpax_socket serverSocket;
    #else
    mpax_socket serverSocket;
    #endif
    sockaddr_in serverAddr{}, clientAddr{};
    #ifdef _WIN32
    int clientSize = sizeof(clientAddr);
    #else
    socklen_t clientSize = sizeof(clientAddr);
    #endif

    bool nonLocal = false;

    std::ifstream config("config.txt");
    if (config) {
        std::string line;
        while (std::getline(config, line)) {
            if (line.find("nonLocal = true") != std::string::npos) {
                nonLocal = true;
            }
        }
        config.close();
    }

    #ifdef _WIN32
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "\033[31mUnfortunately, the Windows Socket API failed to load :(\033[0m\n";
        return 1;
    }
    serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serverSocket == mpax_invalidsocket) {
        std::cerr << "\033[31mUnfortunately, the socket() function failed :( | " << WSAGetLastError() << "\033[0m\n";
        return 1;
    }
    #else
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == mpax_invalidsocket) {
        std::cerr << "\033[31mUnfortunately, the socket() function failed :( | " << errno << "\033[0m\n";
        return 1;
    }
    #endif

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);

    std::cout << "\033[34m=======================================\n";
    std::cout << "The mpax235 Web Server\n";
    #ifdef BUILD
    std::cout << "Build " << std::to_string(buildVersion) << "\n";
    #else
    std::cout << "Version " << releaseVersion << "\n";
    #endif
    std::cout << "2024-2025 mpax235\n";
    std::cout << "=======================================\033[0m\n";

    if (nonLocal) {
        #ifdef _WIN32
        char hostname[256];
        if (gethostname(hostname, sizeof(hostname)) == mpax_socketerror) {
            std::cerr << "\033[31mUnfortunately, the gethostname() function failed :(\033[0m\n";
            return 1;
        }
        if (gethostname(hostname, sizeof(hostname)) == -1) {
            std::cerr << "\033[31mUnfortunately, the gethostname() function failed :(\033[0m\n";
            return 1;
        }

        struct addrinfo hints = {}, *info;
        hints.ai_family = AF_INET;
        hints.ai_socktype = SOCK_STREAM;
        hints.ai_protocol = IPPROTO_TCP;

        if (getaddrinfo(hostname, nullptr, &hints, &info) != 0) {
            std::cerr << "\033[31mUnfortunately, the getaddrinfo() function failed :(\033[0m\n";
            return 1;
        }

        sockaddr_in* addr = reinterpret_cast<sockaddr_in*>(info->ai_addr);
        serverAddr.sin_addr = addr->sin_addr;

        char ipStr[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &serverAddr.sin_addr, ipStr, sizeof(ipStr));
        std::cout << "Listening on http://" << ipStr << ":" << port << "\n";

        freeaddrinfo(info);
        #else
        struct ifaddrs *ifaddr;
        if (getifaddrs(&ifaddr) == -1) {
            std::cerr << "Unfortunately, the getifaddrs() function failed :(\n";
            return 1;
        }

        bool found = false;
        for (struct ifaddrs *ifa = ifaddr; ifa != nullptr; ifa = ifa->ifa_next) {
            if (ifa->ifa_addr && ifa->ifa_addr->sa_family == AF_INET && !(ifa->ifa_flags & IFF_LOOPBACK)) {
                sockaddr_in* sa = reinterpret_cast<sockaddr_in*>(ifa->ifa_addr);
                serverAddr.sin_addr = sa->sin_addr;

                char ipStr[INET_ADDRSTRLEN];
                inet_ntop(AF_INET, &serverAddr.sin_addr, ipStr, sizeof(ipStr));
                std::cout << "Listening on http://" << ipStr << ":" << port << "\n";
                found = true;
                break;
            }
        }

        freeifaddrs(ifaddr);

        if (!found) {
            std::cerr << "\033[31mUnfortunately, a non-loopback IPv4 address was not found :(\033[0m\n";
            return 1;
        }
        #endif
    } else {
        inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);
        std::cout << "Listening on http://localhost:" << port << "\n";
    }

    #ifdef _WIN32
    if (bind(serverSocket, (mpax_socketaddr*)&serverAddr, sizeof(serverAddr)) == mpax_socketerror) {
        std::cerr << "\033[31mUnfortunately, the bind() function failed :( | " << mpax_error() << "\033[0m\n";
        return 1;
    }

    if (listen(serverSocket, SOMAXCONN) == mpax_socketerror) {
        std::cerr << "\033[31mUnfortunately, the listen() function failed :( | " << mpax_error() << "\033[0m\n";
        return 1;
    }

    while (true) {
        mpax_socket clientSocket = accept(serverSocket, (mpax_socketaddr*)&clientAddr, &clientSize);
        if (clientSocket == mpax_invalidsocket) {
            std::cerr << "\033[31mUnfortunately, the accept() function failed :( | " << mpax_error() << "\033[0m\n";
            continue;
        }

        std::thread clientThread(handleClient, clientSocket);
        clientThread.detach();
    }
    #else
    int opt = 1;
    if (setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
        std::cerr << "\033[31mUnfortunately, the setsocketopt() function failed :( | " << errno << "\033[0m\n";
        return 1; 
    }

    if (bind(serverSocket, (mpax_socketaddr*)&serverAddr, sizeof(serverAddr)) == mpax_socketerror) {
        std::cerr << "\033[31mUnfortunately, the bind() function failed :( | " << mpax_error() << "\033[0m\n";
        return 1;
    }

    if (listen(serverSocket, SOMAXCONN) == mpax_socketerror) {
        std::cerr << "\033[31mUnfortunately, the listen() function failed :( | " << mpax_error() << "\033[0m\n";
        return 1;
    }

    while (true) {
        mpax_socket clientSocket = accept(serverSocket, (mpax_socketaddr*)&clientAddr, &clientSize);
        if (clientSocket == mpax_invalidsocket) {
            std::cerr << "\033[31mUnfortunately, the accept() function failed :( | " << mpax_error() << "\033[0m\n";
            continue;
        }

        std::thread clientThread(handleClient, clientSocket);
        clientThread.detach();
    }
    #endif
    
    mpax_closesocket(serverSocket);
    #ifdef _WIN32
    WSACleanup();
    #endif

    return 0;
}