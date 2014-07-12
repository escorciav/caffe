
// TEST_ALL_DEVICES creates a copy of a test for each device.
// Whenever possible, this should be used rather than creating copy-paste
// test duplicates for each device.
// (Currently should really just be TEST_BOTH_DEVICES as Caffe currently just
// two devices: CPU and GPU, but named TEST_ALL_DEVCIES for future-proofing.)

#define TEST_ALL_DEVICES(CaseName, TestName) \
TYPED_TEST(DataLayerTest, TestReadLevelDBCPU) {
  Caffe::set_mode(Caffe::CPU);
  const bool unique_pixels = false;  // all pixels the same; images different
  this->FillLevelDB(unique_pixels);
  this->TestRead();
}

TYPED_TEST(DataLayerTest, TestReadLevelDBGPU) {
  Caffe::set_mode(Caffe::GPU);
  const bool unique_pixels = false;  // all pixels the same; images different
  this->FillLevelDB(unique_pixels);
  this->TestRead();
}

