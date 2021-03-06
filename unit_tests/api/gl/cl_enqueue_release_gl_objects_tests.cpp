/*
 * Copyright (C) 2018 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#include "unit_tests/api/cl_api_tests.h"

using namespace OCLRT;

typedef api_tests clEnqueueReleaseGLObjects_;

namespace ULT {

TEST_F(clEnqueueReleaseGLObjects_, givenNullCommandQueueWhenReleaseGlObjectsIsCalledThenInvalidCommandQueueIsReturned) {
    auto retVal = clEnqueueReleaseGLObjects(nullptr, // cl_command_queue command_queue
                                            0,       // cl_uint num_objects
                                            nullptr, // const cl_mem *mem_objects
                                            0,       // cl_uint num_events_in_wait_list
                                            nullptr, // const cl_event *event_wait_list
                                            nullptr  // cl_event *event
    );
    EXPECT_EQ(CL_INVALID_COMMAND_QUEUE, retVal);
}
} // namespace ULT
