/**
 * Internal error counting function for assertXXX methods.
 * @param msg to report
 */
extern void cunit report error(const char* msg);
extern void cunit report failure(const char* msg);

/**
 * raise a failure situation with message.
 */
#define fail(msg) { \
  char test buf[BUFSIZE]; \
  sprintf ( test buf ,”FAIL %s:%d %s \n”, \
    FILE , LINE , msg); \
  cunit report failure ( test buf ); \
}

/**
 * check that the given expression is true .
 */
#define assertTrue(expr) { \
  if( !( expr) ) { \
    char test buf[BUFSIZE]; \
    sprintf ( test buf ,”ERROR %s:%d %s \n”, \
      FILE , LINE , #expr); \
    cunit report error ( test buf ); \
  } \
}
