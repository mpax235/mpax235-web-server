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

static char mpax235_307_page[] =
"<!DOCTYPE html>\n"
"<html>\n"
"    <head>\n"
"        <title>307 Temporary Redirect</title>\n"
"        <link rel=\"stylesheet\" href=\"/mpax235WebServerCSS/serverCSS/httpresponsepage.css\">\n"
"    </head>\n"
"    <body>\n"
"        <center><h1>307 Temporary Redirect</h1><center>\n";

static char mpax235_308_page[] =
"<!DOCTYPE html>\n"
"<html>\n"
"    <head>\n"
"        <title>308 Permanent Redirect</title>\n"
"        <link rel=\"stylesheet\" href=\"/mpax235WebServerCSS/serverCSS/httpresponsepage.css\">\n"
"    </head>\n"
"    <body>\n"
"        <center><h1>308 Permanent Redirect</h1><center>\n";

static char mpax235_400_page[] =
"<!DOCTYPE html>\n"
"<html>\n"
"    <head>\n"
"        <title>400 Bad Request</title>\n"
"        <link rel=\"stylesheet\" href=\"/mpax235WebServerCSS/serverCSS/httpresponsepage.css\">\n"
"    </head>\n"
"    <body>\n"
"        <center><h1>400 Bad Request</h1><center>\n";

static char mpax235_401_page[] =
"<!DOCTYPE html>\n"
"<html>\n"
"    <head>\n"
"        <title>401 Authorization Required</title>\n"
"        <link rel=\"stylesheet\" href=\"/mpax235WebServerCSS/serverCSS/httpresponsepage.css\">\n"
"    </head>\n"
"    <body>\n"
"        <center><h1>401 Authorization Required</h1><center>\n";

static char mpax235_402_page[] =
"<!DOCTYPE html>\n"
"<html>\n"
"    <head>\n"
"        <title>402 Payment Required</title>\n"
"        <link rel=\"stylesheet\" href=\"/mpax235WebServerCSS/serverCSS/httpresponsepage.css\">\n"
"    </head>\n"
"    <body>\n"
"        <center><h1>402 Payment Required</h1><center>\n";

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

static char mpax235_405_page[] =
"<!DOCTYPE html>\n"
"<html>\n"
"    <head>\n"
"        <title>405 Not Allowed</title>\n"
"        <link rel=\"stylesheet\" href=\"/mpax235WebServerCSS/serverCSS/httpresponsepage.css\">\n"
"    </head>\n"
"    <body>\n"
"        <center><h1>405 Not Allowed</h1><center>\n";

static char mpax235_406_page[] =
"<!DOCTYPE html>\n"
"<html>\n"
"    <head>\n"
"        <title>406 Not Acceptable</title>\n"
"        <link rel=\"stylesheet\" href=\"/mpax235WebServerCSS/serverCSS/httpresponsepage.css\">\n"
"    </head>\n"
"    <body>\n"
"        <center><h1>406 Not Acceptable</h1><center>\n";

static char mpax235_408_page[] =
"<!DOCTYPE html>\n"
"<html>\n"
"    <head>\n"
"        <title>408 Request Time-out</title>\n"
"        <link rel=\"stylesheet\" href=\"/mpax235WebServerCSS/serverCSS/httpresponsepage.css\">\n"
"    </head>\n"
"    <body>\n"
"        <center><h1>408 Request Time-out</h1><center>\n";

static char mpax235_409_page[] =
"<!DOCTYPE html>\n"
"<html>\n"
"    <head>\n"
"        <title>409 Conflict</title>\n"
"        <link rel=\"stylesheet\" href=\"/mpax235WebServerCSS/serverCSS/httpresponsepage.css\">\n"
"    </head>\n"
"    <body>\n"
"        <center><h1>409 Conflict</h1><center>\n";

static char mpax235_410_page[] =
"<!DOCTYPE html>\n"
"<html>\n"
"    <head>\n"
"        <title>410 Gone</title>\n"
"        <link rel=\"stylesheet\" href=\"/mpax235WebServerCSS/serverCSS/httpresponsepage.css\">\n"
"    </head>\n"
"    <body>\n"
"        <center><h1>410 Gone</h1><center>\n";

static char mpax235_411_page[] =
"<!DOCTYPE html>\n"
"<html>\n"
"    <head>\n"
"        <title>411 Length Required</title>\n"
"        <link rel=\"stylesheet\" href=\"/mpax235WebServerCSS/serverCSS/httpresponsepage.css\">\n"
"    </head>\n"
"    <body>\n"
"        <center><h1>411 Length Required</h1><center>\n";

static char mpax235_412_page[] =
"<!DOCTYPE html>\n"
"<html>\n"
"    <head>\n"
"        <title>412 Precondition Failed</title>\n"
"        <link rel=\"stylesheet\" href=\"/mpax235WebServerCSS/serverCSS/httpresponsepage.css\">\n"
"    </head>\n"
"    <body>\n"
"        <center><h1>412 Precondition Failed</h1><center>\n";

static char mpax235_413_page[] =
"<!DOCTYPE html>\n"
"<html>\n"
"    <head>\n"
"        <title>413 Request Entity Too Large</title>\n"
"        <link rel=\"stylesheet\" href=\"/mpax235WebServerCSS/serverCSS/httpresponsepage.css\">\n"
"    </head>\n"
"    <body>\n"
"        <center><h1>413 Request Entity Too Large</h1><center>\n";

static char mpax235_414_page[] =
"<!DOCTYPE html>\n"
"<html>\n"
"    <head>\n"
"        <title>414 Request-URI Too Large</title>\n"
"        <link rel=\"stylesheet\" href=\"/mpax235WebServerCSS/serverCSS/httpresponsepage.css\">\n"
"    </head>\n"
"    <body>\n"
"        <center><h1>414 Request-URI Too Large</h1><center>\n";

static char mpax235_415_page[] =
"<!DOCTYPE html>\n"
"<html>\n"
"    <head>\n"
"        <title>415 Unsupported Media Type</title>\n"
"        <link rel=\"stylesheet\" href=\"/mpax235WebServerCSS/serverCSS/httpresponsepage.css\">\n"
"    </head>\n"
"    <body>\n"
"        <center><h1>415 Unsupported Media Type</h1><center>\n";

static char mpax235_416_page[] =
"<!DOCTYPE html>\n"
"<html>\n"
"    <head>\n"
"        <title>416 Request Range Not Satisfiable</title>\n"
"        <link rel=\"stylesheet\" href=\"/mpax235WebServerCSS/serverCSS/httpresponsepage.css\">\n"
"    </head>\n"
"    <body>\n"
"        <center><h1>416 Request Range Not Satisfiable</h1><center>\n";

static char mpax235_421_page[] =
"<!DOCTYPE html>\n"
"<html>\n"
"    <head>\n"
"        <title>421 Misdirected Request</title>\n"
"        <link rel=\"stylesheet\" href=\"/mpax235WebServerCSS/serverCSS/httpresponsepage.css\">\n"
"    </head>\n"
"    <body>\n"
"        <center><h1>421 Misdirected Request</h1><center>\n";

static char mpax235_429_page[] =
"<!DOCTYPE html>\n"
"<html>\n"
"    <head>\n"
"        <title>429 Too Many Requests</title>\n"
"        <link rel=\"stylesheet\" href=\"/mpax235WebServerCSS/serverCSS/httpresponsepage.css\">\n"
"    </head>\n"
"    <body>\n"
"        <center><h1>429 Too Many Requests</h1><center>\n";

static char mpax235_494_page[] =
"<!DOCTYPE html>\n"
"<html>\n"
"    <head>\n"
"        <title>400 Request Header Or Cookie Too Large</title>\n"
"        <link rel=\"stylesheet\" href=\"/mpax235WebServerCSS/serverCSS/httpresponsepage.css\">\n"
"    </head>\n"
"    <body>\n"
"        <center><h1>400 Bad Request</h1><center>\n"
"        <center>Request Header Or Cookie Too Large</center>\n";

static char mpax235_495_page[] =
"<!DOCTYPE html>\n"
"<html>\n"
"    <head>\n"
"        <title>400 Invalid SSL Certificate</title>\n"
"        <link rel=\"stylesheet\" href=\"/mpax235WebServerCSS/serverCSS/httpresponsepage.css\">\n"
"    </head>\n"
"    <body>\n"
"        <center><h1>400 Bad Request</h1><center>\n"
"        <center>Invalid SSL Certificate</center>\n";

static char mpax235_496_page[] =
"<!DOCTYPE html>\n"
"<html>\n"
"    <head>\n"
"        <title>400 No required SSL certificate was sent</title>\n"
"        <link rel=\"stylesheet\" href=\"/mpax235WebServerCSS/serverCSS/httpresponsepage.css\">\n"
"    </head>\n"
"    <body>\n"
"        <center><h1>400 Bad Request</h1><center>\n"
"        <center>No required SSL certificate was sent</center>\n";

static char mpax235_497_page[] =
"<!DOCTYPE html>\n"
"<html>\n"
"    <head>\n"
"        <title>400 The plain HTTP request was sent to HTTPS port</title>\n"
"        <link rel=\"stylesheet\" href=\"/mpax235WebServerCSS/serverCSS/httpresponsepage.css\">\n"
"    </head>\n"
"    <body>\n"
"        <center><h1>400 Bad Request</h1><center>\n"
"        <center>The plain HTTP request was sent to HTTPS port</center>\n";

static char mpax235_498_page[] =
"<!DOCTYPE html>\n"
"<html>\n"
"    <head>\n"
"        <title>406 Path Traversal attack blocked</title>\n"
"        <link rel=\"stylesheet\" href=\"/mpax235WebServerCSS/serverCSS/httpresponsepage.css\">\n"
"    </head>\n"
"    <body>\n"
"        <center><h1>406 Not Acceptable</h1><center>"
"        <center>Path Traversal attack blocked</center>\n";

static char mpax235_500_page[] =
"<!DOCTYPE html>\n"
"<html>\n"
"    <head>\n"
"        <title>500 Internal Server Error</title>\n"
"        <link rel=\"stylesheet\" href=\"/mpax235WebServerCSS/serverCSS/httpresponsepage.css\">\n"
"    </head>\n"
"    <body>\n"
"        <center><h1>500 Internal Server Error</h1><center>\n";

static char mpax235_501_page[] =
"<!DOCTYPE html>\n"
"<html>\n"
"    <head>\n"
"        <title>501 Not Implementedr</title>\n"
"        <link rel=\"stylesheet\" href=\"/mpax235WebServerCSS/serverCSS/httpresponsepage.css\">\n"
"    </head>\n"
"    <body>\n"
"        <center><h1>501 Not Implemented</h1><center>\n";

static char mpax235_502_page[] =
"<!DOCTYPE html>\n"
"<html>\n"
"    <head>\n"
"        <title>502 Bad Gateway</title>\n"
"        <link rel=\"stylesheet\" href=\"/mpax235WebServerCSS/serverCSS/httpresponsepage.css\">\n"
"    </head>\n"
"    <body>\n"
"        <center><h1>502 Bad Gateway</h1><center>\n";

static char mpax235_503_page[] =
"<!DOCTYPE html>\n"
"<html>\n"
"    <head>\n"
"        <title>503 Service Temporarily Unavailable</title>\n"
"        <link rel=\"stylesheet\" href=\"/mpax235WebServerCSS/serverCSS/httpresponsepage.css\">\n"
"    </head>\n"
"    <body>\n"
"        <center><h1>503 Service Temporarily Unavailable</h1><center>\n";

static char mpax235_504_page[] =
"<!DOCTYPE html>\n"
"<html>\n"
"    <head>\n"
"        <title>504 Gateway Time-out</title>\n"
"        <link rel=\"stylesheet\" href=\"/mpax235WebServerCSS/serverCSS/httpresponsepage.css\">\n"
"    </head>\n"
"    <body>\n"
"        <center><h1>504 Gateway Time-out</h1><center>\n";

static char mpax235_505_page[] =
"<!DOCTYPE html>\n"
"<html>\n"
"    <head>\n"
"        <title>505 HTTP Version Not Supported</title>\n"
"        <link rel=\"stylesheet\" href=\"/mpax235WebServerCSS/serverCSS/httpresponsepage.css\">\n"
"    </head>\n"
"    <body>\n"
"        <center><h1>505 HTTP Version Not Supported</h1><center>\n";

static char mpax235_507_page[] =
"<!DOCTYPE html>\n"
"<html>\n"
"    <head>\n"
"        <title>507 Insufficient Storage</title>\n"
"        <link rel=\"stylesheet\" href=\"/mpax235WebServerCSS/serverCSS/httpresponsepage.css\">\n"
"    </head>\n"
"    <body>\n"
"        <center><h1>507 Insufficient Storage</h1><center>\n";

static char footer[] =
"        <hr><center><span>mpax235</span></center>\n"
"    </body>\n"
"</html>\n";

static char padding[] =
"<!-- a padding in order to disable friendly error page -->\n";

#endif // HTTP_RESPONSE_ELEMENTS_H