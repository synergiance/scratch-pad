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

// Normal headers

#include <stdio.h> // Standard IO library
#include <string> // String library
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
    bio = BIO_new_connect("google.com:80"); // Our socket connection
    if(bio == NULL) // No socket means no communication
    {
        puts("FATAL ERROR. Exiting.\n"; // Print scary looking error
        return -1;
    }

    if(BIO_do_connect(bio) <= 0) // We failed to connect. Network probably
    {
        puts("ERROR: Could not establish connection"); // Print regular error
        return -1;
    }

    bool stop = false; // Stop condition
    int x; // Returned length
    char buf [1024]; // Buffer
    std:string str; // All our data that we acquired, bwahahahahahahahahaha

  /* BIO_write will attempt to write bytes to the socket. Return value is the
   * number of bytes written, 0 for a closed connection, or -1 for a technical
   * error.  For a reliable error read, call BIO_should_retry.
   */
    while (!stop) {
        stop = true;
        if(BIO_write(bio, "GET / http/1.1\r\n", 16) <= 0) { // Our socket write
            if(! BIO_should_retry(bio)) { // Check to see if we should retry
                puts("FATAL WRITE ERROR. Exiting.\n"); // Print scary error
		BIO_free_all(bio); // We'll learn about this later
                return -1;
            }
            stop = false;
        }
    }

    stop = false; // Reset stop variable

  /* BIO_read is just like BIO_write, but you get to limit the amount of bytes
   * that it returns.  As with BIO_write, BIO_read returns the number of bytes
   * it reads, and 0 or -1 for their respective errors.
   */
    while (!stop) {
        x = BIO_read(bio, buf, 1023); // This is how we get our datas
        if(x == 0) { // This indicates a closed connection
            stop = true; // This is what we will wait for
        } else if(x < 0) {
            puts("READING TERMINATED EARLY!!!\n\n"); // Oopsie daisy
            stop = true;
        } else {
            buf[x] = '\0'; // Set the string termination byte
	    str += buf; // This will append the string
        }
    }

  /* Now we need to close the connection.  If we want to reuse it, use
   * BIO_reset.  This is useful for many HTTP purposes where we load multiple
   * resources.  For now, we're just going to free the connection with
   * BIO_free_all. Enjoy the magic! <3
   */
    BIO_free_all(bio); // We're free now!!!
    // BIO_reset(bio); // This would prime BIO for further use

    // Now we print everything out
    while(str.compare("") != 0) { // Test whether string is empty
        buf = str.substr(0,1023).c_str(); // Fill the buffer
        str.erase(0,1023); // Erase from string
        puts(buf); // Print out whatever's there
    }

    puts("\n");

    return 0;
}
