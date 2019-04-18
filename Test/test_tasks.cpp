#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness.h>

extern "C" {
#include "FreeRTOS.h"
#include "task.h"
}

TEST_GROUP(ClassName)
{
  void* className;

  void setup()
  {
    className = NULL;
  }
  void teardown()
  {
    ;
  }
};

#if 0
	BaseType_t xTaskCreate(	TaskFunction_t pxTaskCode,
							const char * const pcName,	/*lint !e971 Unqualified char types are allowed for strings and single characters only. */
							const configSTACK_DEPTH_TYPE usStackDepth,
							void * const pvParameters,
							UBaseType_t uxPriority,
							TaskHandle_t * const pxCreatedTask ) PRIVILEGED_FUNCTION;
#endif

TEST(ClassName, Create)
{
  CHECK(0 == className);
  CHECK(true);
  CHECK_EQUAL(1,1);
  LONGS_EQUAL(1,1);
  DOUBLES_EQUAL(1.000, 1.001, .01);
  STRCMP_EQUAL("hello", "hello");
  xTaskCreate (NULL,
               "TaskName",
               0,
               NULL,
               0,
               NULL);
}

int
main (int argc, char *argv[])
{
  return CommandLineTestRunner::RunAllTests(argc, argv);
}
