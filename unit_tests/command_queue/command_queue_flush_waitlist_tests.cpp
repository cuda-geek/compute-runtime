/*
 * Copyright (C) 2017-2018 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#include "unit_tests/command_queue/command_queue_fixture.h"
#include "unit_tests/fixtures/context_fixture.h"
#include "unit_tests/fixtures/device_fixture.h"
#include "unit_tests/mocks/mock_command_queue.h"
#include "unit_tests/mocks/mock_event.h"

#include "test.h"
#include "gtest/gtest.h"

using namespace OCLRT;

struct CommandQueueSimpleTest
    : public DeviceFixture,
      public ContextFixture,
      public ::testing::Test {

    using ContextFixture::SetUp;

    CommandQueueSimpleTest() {
    }

    void SetUp() override {
        DeviceFixture::SetUp();
        cl_device_id device = pDevice;
        ContextFixture::SetUp(1, &device);
    }

    void TearDown() override {
        ContextFixture::TearDown();
        DeviceFixture::TearDown();
    }
};
