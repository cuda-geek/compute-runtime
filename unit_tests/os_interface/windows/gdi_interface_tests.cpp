/*
 * Copyright (C) 2017-2019 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#if defined(_WIN32)
#include "runtime/os_interface/os_library.h"
#include "runtime/os_interface/windows/gdi_interface.h"
#include "unit_tests/helpers/debug_manager_state_restore.h"

#include "test.h"
#include "gtest/gtest.h"

TEST(GdiInterface, creation) {
    OCLRT::Gdi gdi;
    ASSERT_TRUE(gdi.isInitialized());
}

TEST(GdiInterface, failLoad) {
    const char *oldName = Os::gdiDllName;
    Os::gdiDllName = "surely_not_exists_.dll";

    OCLRT::Gdi gdi;
    EXPECT_FALSE(gdi.isInitialized());

    Os::gdiDllName = oldName;
}

TEST(GdiInterface, givenGdiOverridePathWhenGdiInterfaceIsCalledThenOverridePathIsUsed) {
    const char *oldName = Os::gdiDllName;

    DebugManagerStateRestore dbgRestorer;

    Os::gdiDllName = "surely_not_exists_.dll";
    DebugManager.flags.OverrideGdiPath.set(oldName);

    OCLRT::Gdi gdi;
    EXPECT_TRUE(gdi.isInitialized());

    Os::gdiDllName = oldName;
}

TEST(ThkWrapperTest, givenThkWrapperWhenConstructedThenmFuncIsInitialized) {
    OCLRT::ThkWrapper<false, void *> wrapper;
    EXPECT_EQ(nullptr, wrapper.mFunc);
}
#endif
