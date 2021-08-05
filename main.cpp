#include <bitset>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
//
#include <cstdint>

constexpr uint32_t morton_code(uint16_t x, uint16_t y) {
  auto z = (uint32_t{y} << 16) | uint32_t{x};
  z = (z & 0xff0000ff) | ((z & 0x0000ff00) << 8) | ((z & 0x00ff0000) >> 8);
  z = (z & 0xf00ff00f) | ((z & 0x00f000f0) << 4) | ((z & 0x0f000f00) >> 4);
  z = (z & 0xc3c3c3c3) | ((z & 0x0c0c0c0c) << 2) | ((z & 0x30303030) >> 2);
  z = (z & 0x99999999) | ((z & 0x22222222) << 1) | ((z & 0x44444444) >> 1);
  return z;
}

using namespace std;

int main() {
  mt19937 rng{random_device{}()};

  for (size_t i = 0; i < 5; ++i) {
    for (size_t j = 0; j < 5; ++j) {
      uint16_t x = i;
      uint16_t y = j;
      cout << setw(20) << bitset<16>{x} << setw(20) << bitset<16>{y} << setw(35)
           << bitset<32>{morton_code(x, y)} << '\n';
    }
  }

  for (size_t i = 0; i < 10; ++i) {
    uint16_t x = rng();
    uint16_t y = rng();
    cout << setw(20) << bitset<16>{x} << setw(20) << bitset<16>{y} << setw(35)
         << bitset<32>{morton_code(x, y)} << '\n';
  }
}
