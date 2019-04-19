#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness.h>

extern "C" {
#include "FreeRTOS.h"
#include "task.h"
#include "stub.h"
}

TEST_GROUP(xTaskCreate)
{
  void setup()
  {
  }
  void teardown()
  {
    stub_reset ();
  }
};

TEST(xTaskCreate, allocFail)
{
  stub_set_malloc_fail ();
  CHECK_EQUAL(errCOULD_NOT_ALLOCATE_REQUIRED_MEMORY,
              xTaskCreate (NULL, "TaskName", 0, NULL, 0, NULL));
}

TEST(xTaskCreate, Success)
{
  CHECK_EQUAL(pdPASS,
              xTaskCreate (NULL, "TaskName", 0, NULL, 0, NULL));
}

int
main (int argc, char *argv[])
{
  return CommandLineTestRunner::RunAllTests(argc, argv);
}
