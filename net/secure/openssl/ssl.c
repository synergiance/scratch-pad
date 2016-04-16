/*
 *   Filename: ssl.c
 *
 * Created on: 15 April 2016
 *     Author: Synergiance
 *
 * This is a beginner's guide to SSL.  It will be heavily commented, as I
 * am learning, good luck reading everything.
 */

#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>

#include <openssl/bio.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/pem.h>
#include <openssl/x509.h>
#include <openssl/x509_vfy.h>

int create_socket(char[]);

int main(int argc, char *argv[]) {
}

int create_socket(char url_str[]) {
    int sockfd;
    char hostname[256] = "";
    char    portnum[6] = "443";
    char      proto[6] = "";
    char      *tmp_ptr = NULL;
    int           port;
    struct hostent *host;
    struct sockaddr_in dest_addr;

    //
}
