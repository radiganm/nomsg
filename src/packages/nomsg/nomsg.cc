/// nomsg.cc
/// Copyright 2017 Mac Radigan
/// All Rights Reserved

  #include "packages/nomsg/nomsg.h"

  #include <iomanip>
  #include <bitset>

namespace rad::nomsg {

  std::ostream& operator<<(std::ostream &os, const rad::nomsg::nomsg_t &o)
  {
    std::ios::fmtflags flags(os.flags());
  //std::bitset<8> bits(o.packet_type);
  //os << "              bits: " << bits << std::endl;
  //os << "       packet_type: " << std::hex       << o.packet_type << std::endl;
  //os << "  class_id_present: " << std::boolalpha << bits.test(3)  << std::endl;
  //os << "   trailer_present: " << std::boolalpha << bits.test(2)  << std::endl;
  //os << "        reserved_1: " << std::boolalpha << bits.test(1)  << std::endl;
  //os << "        reserved_2: " << std::boolalpha << bits.test(0)  << std::endl;
  //os << "       packet_size: " << std::dec       << o.packet_size << std::endl;
  //os.flags(flags);
    return os;
  }

} // namespace

  using namespace rad::nomsg;

/// *EOF*
