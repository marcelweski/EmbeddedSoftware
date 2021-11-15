/**
 * declare test function header
 */
#define DECLARE_TEST(testname) \
extern int testname##Test(int argc, char** argv);

/**
 *
 */
#define BEG_SUITE(suitename)

/**
 * Internal error counting function for assertXXX methods.
 * @param msg to report
 */
extern void cunit_report_error(const char* msg);
extern void cunit_report_failure(const char* msg);

/**
 * raise a failure situation with message.
 */
#define fail(msg) { \
  char test_buf[BUFSIZE]; \
  sprintf(test_buf, ”FAIL %s:%d %s\n”, \
    FILE, LINE, msg); \
  cunit_report_failure(test_buf); \
}

/**
 * check that the given expression is true .
 */
#define assertTrue(expr) { \
  if( !( expr) ) { \
    char test_buf[BUFSIZE]; \
    sprintf(test_buf, ”ERROR %s:%d %s\n”, \
      FILE, LINE, #expr); \
    cunit_report_error(test_buf); \
  } \
}
