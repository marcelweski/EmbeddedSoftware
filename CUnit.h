/**
 * declare a test function
 */
#define DECLARE_TEST(test) \
extern int test##Test(int argc, char** argv);

/**
 * begin a test suite
 */
#define BEG_SUITE(suite) \
int (*)(int, char**) suite##_testfuncs[] = {

/**
 * add test to the suite
 */
#define ADD_TEST(test) \
  test##Test,

/**
 * end the suite
 */
#define END_SUITE(suite) \
};

/**
 * run the created test suite
 */
#define RUN_SUITE(suite) \
int main(int argc, char** argv) { \
  int test_count = sizeof(suite##_testfuncs) / sizeof(void*); \
  for (int i = 0; i < test_count; i++) { \
  } \
}

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
