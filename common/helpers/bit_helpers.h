/*
 * Copyright (C) 2019 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#pragma once
#include <cassert>
#include <cstdint>
#include <limits>

namespace OCLRT {

constexpr bool isBitSet(uint64_t field, uint64_t bitPosition) {
    assert(bitPosition < std::numeric_limits<uint64_t>::digits); // undefined behavior
    return (field & (1ull << bitPosition));
}

constexpr bool isValSet(uint64_t field, uint64_t value) {
    assert(value != 0);
    return ((field & value) == value);
}

} // namespace OCLRT
