# Trivial HTTP C Client

This is a trivial C implementation of an HTTP 1.0 client.
This program performs an HTTP (1.0) GET for the specified ip address, port and path.
The result is printed to standard output.

## Compilation

```shell
gcc -Wall -o bin/http_client sources/http_client.c sources/simple_tcp.c
```

## Usage

```shell
./bin/http_client <ip address> <port> <path>
```

For example, to query the root path of www.google.com (IP: 173.194.35.112):

```shell
./http_client 173.194.35.112 80 /
HTTP/1.0 302 Found
Location: http://www.google.it/?gws_rd=cr&ei=IaCgUt7aN8jVsgaYnYD4Bw
Cache-Control: private
Content-Type: text/html; charset=UTF-8
Set-Cookie: PREF=ID=3bb5187e1b8bafc5:FF=0:TM=1386258465:LM=1386258465:S=aC1Rob5nwoieF6DD; expires=Sat, 05-Dec-2015 15:47:45 GMT; path=/; domain=.google.com
Set-Cookie: NID=67=CPVFWApVdwc6VYIjuG0wI1j5RxIbnOGjcblfk5xgCJopmIKUpV_b9XkbOMEGxAmmk6X_w_lc1gFQCh_likgsSOLv4-IWKiBXdkkj886FphMS556EFeejbhQRwrfAY3VB; expires=Fri, 06-Jun-2014 15:47:45 GMT; path=/; domain=.google.com; HttpOnly
P3P: CP="This is not a P3P policy! See http://www.google.com/support/accounts/bin/answer.py?hl=en&answer=151657 for more info."
Date: Thu, 05 Dec 2013 15:47:45 GMT
Server: gws
Content-Length: 258
X-XSS-Protection: 1; mode=block
X-Frame-Options: SAMEORIGIN
Alternate-Protocol: 80:quic

<HTML><HEAD><meta http-equiv="content-type" content="text/html;charset=utf-8">
<TITLE>302 Moved</TITLE></HEAD><BODY>
<H1>302 Moved</H1>
The document has moved
<A HREF="http://www.google.it/?gws_
rd=cr&amp;ei=IaCgUt7aN8jVsgaYnYD4Bw">here</A>.
</BODY></HTML>
```
