/* OpenSSL Test Project
 *  simplesocket.cpp
 * Author: Synergiance
 *
 * This is just a learning program where I test the abilities of the OpenSSL
 * library.  I will be implementing this library into net based applications I
 * own in the future.  This is where I will be testing my tests.
 *
 * Source: http://www.ibm.com/developerworks/linux/library/l-openssl/index.html
 */

/* OpenSSL headers */

#include "openssl/bio.h"
#include "openssl/ssl.h"
#include "openssl/err.h"

// BIO * bui; == bio pointer

int main() {
    // Initializing OpenSSL
    SSL_load_error_strings();
    ERR_load_BIO_strings();
    OpenSSL_add_all_algorithms();

  /* This is an abstraction library called BIO which handles many forms
   * of communication.  This pointer is like the FILE stream in C.
   */
    BIO * bio;

  /* This can be split up into two calls.  BIO_new_connect with just the
   * hostname, and BIO_set_conn_port or BIO_set_conn_int_port) to set the
   * port number.  Once the hostname and port number are specified to the
   * BIO, it will attempt to open open the connection.  If there was a
   * problem creating the object, the pointer will be NULL.  Call
   * BIO_do_connect to verify the connection was successful.
   */
    bio = BIO_new_connect("google.com:443");
    if(bio == NULL)
    {
        // Handle the failure.
    }

    if(BIO_do_connect(bio) <= 0)
    {
        // Handle failed connection
    }

    // DO NOT COMPILE THIS IS NOT FINISHED.
    return -1;
}
