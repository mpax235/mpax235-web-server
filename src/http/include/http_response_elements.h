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

#ifndef HTTP_RESPONSE_ELEMENTS_H
#define HTTP_RESPONSE_ELEMENTS_H

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

#endif // HTTP_RESPONSE_ELEMENTS_H