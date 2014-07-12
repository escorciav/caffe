// Copyright 2014 BVLC and contributors.

#ifndef CAFFE_TEST_COMMON_H_
#define CAFFE_TEST_COMMON_H_

#include <glog/logging.h>
#include <gtest/gtest.h>

#include <algorithm>
#include <cmath>
#include <vector>

#include "caffe/layer.hpp"
#include "caffe/net.hpp"

using std::max;

namespace caffe {

// TEST_ALL_DEVICES creates a copy of a test for each device.
// Whenever possible, this should be used rather than creating copy-paste
// test duplicates for each device.
// (Currently should really just be TEST_BOTH_DEVICES as Caffe currently just
// two devices: CPU and GPU, but named TEST_ALL_DEVCIES for future-proofing.)
#define TYPED_TEST_ALL_DEVICES(CaseName, TestName, TestBody) \
  TYPED_TEST_DEVICE(CaseName, TestName, CPU, TestBody) \
  TYPED_TEST_DEVICE(CaseName, TestName, GPU, TestBody)

#define TYPED_TEST_DEVICE(CaseName, TestName, DeviceName, TestBody) \
  TYPED_TEST(CaseName, TestName##DeviceName) { \
    Caffe::set_mode(Caffe::DeviceName); \
    TestBody \
  }

}  // namespace caffe

#endif  // CAFFE_TEST_COMMON_H_
