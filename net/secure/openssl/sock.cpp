/*
 *   Filename: sock.cpp
 *
 * Created on: 15 April 2016
 *     Author: Synergiance
 *
 * This is a module that maintains a TCP connection whether or not it's SSL
 */

#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>

#include "sock.h"
#include "ssl.h"

addrlookup(const char *address) {
}

CSock::CSock() {
}

