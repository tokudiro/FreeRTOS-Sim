#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness.h>

#define traceQUEUE_CREATE_FAILED(ucQueueType) traceQUEUE_CREATE_FAILED_stub(ucQueueType)

extern "C" {
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "stub.h"

// task's stub
void * pvTaskIncrementMutexHeldCount(void){ return NULL; }
void vTaskInternalSetTimeOutState(TimeOut_t * const pxTimeOut){}
void vTaskMissedYield(void){}
void vTaskPlaceOnEventList( List_t * const pxEventList, const TickType_t xTicksToWait ){}
void vTaskPlaceOnEventListRestricted( List_t * const pxEventList, TickType_t xTicksToWait, const BaseType_t xWaitIndefinitely ){}
void vTaskPriorityDisinheritAfterTimeout( TaskHandle_t const pxMutexHolder, UBaseType_t uxHighestPriorityWaitingTask ){}
BaseType_t xTaskCheckForTimeOut( TimeOut_t * const pxTimeOut, TickType_t * const pxTicksToWait ){ return pdFALSE; }
TaskHandle_t xTaskGetCurrentTaskHandle( void ){ return NULL; }
BaseType_t xTaskGetSchedulerState( void ){ return taskSCHEDULER_NOT_STARTED; }
BaseType_t xTaskPriorityDisinherit( TaskHandle_t const pxMutexHolder ){ return pdFALSE; }
BaseType_t xTaskPriorityInherit( TaskHandle_t const pxMutexHolder ){ return pdFALSE; }
BaseType_t xTaskRemoveFromEventList( const List_t * const pxEventList ){ return pdFALSE; }
BaseType_t xTaskResumeAll( void ){ return pdFALSE; }
void vTaskSuspendAll( void ){}


int called_traceQUEUE_CREATE_FAILED = 0;
void traceQUEUE_CREATE_FAILED_stub(int ucQueueType)
{
}

} // extern "C"

TEST_GROUP(xQueueCreate)
{
  void setup()
  {
  }
  void teardown()
  {
    stub_reset ();
  }
};

TEST(xQueueCreate, allocFail)
{
  stub_set_malloc_fail ();
  CHECK_EQUAL(0,
              xQueueCreate (10, sizeof( uint32_t )));
}

TEST(xQueueCreate, Success)
{
  CHECK(0 != xQueueCreate (10, sizeof( uint32_t )));
}

int
main (int argc, char *argv[])
{
  return CommandLineTestRunner::RunAllTests(argc, argv);
}
