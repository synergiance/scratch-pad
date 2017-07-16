/*
 *   Filename: sock.h
 *
 * Created on: 15 April 2016
 *     Author: Synergiance
 *
 * This is a module that maintains a TCP connection whether or not it's SSL
 */

#include "ssl.h"

#ifndef SOCK_H_
#define SOCK_H_

addrlookup(const char *address);

class CSock
{
public:
    CSock();
    bool connect (const char *address, int portnum, bool secure);
    bool connect (const char *address, int portnum);
    bool disconnect();
    virtual ~CSock();
    int send(const void *data, int len);
    int recv(void *data, int len);
private:
    SslObj *ssl;
    bool secured;
    int port;
    const char *addr;
    bool connected;
};

#endif /* SOCK_H_ */
