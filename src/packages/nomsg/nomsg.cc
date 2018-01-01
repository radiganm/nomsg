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
    os << o.type;
  //os << o.flags;
    os.flags(flags);
    return os;
  } // nomsg

  std::ostream& operator<<(std::ostream &os, const rad::nomsg::nomsg_type_t &o)
  {
    switch(o)
    {
      case rad::nomsg::NOMSG__TYPE_NOMSG:
        os << "type: NoMsg container";
        break;
      case rad::nomsg::NOMSG__TYPE_INDEX:
        os << "type: indexed array";
        break;
      case rad::nomsg::NOMSG__TYPE_FILE:
        os << "type: ordinary file";
        break;
      case rad::nomsg::NOMSG__TYPE_EDN:
        os << "type: extensible data notation";
        break;
      case rad::nomsg::NOMSG__TYPE_INTERROBANG:
        os << "type: interrobang script";
        break;
      case rad::nomsg::NOMSG__TYPE_SEXP:
        os << "type: s-expression";
        break;
      case rad::nomsg::NOMSG__TYPE_LISP:
        os << "type: lisp code";
        break;
      case rad::nomsg::NOMSG__TYPE_STL:
        os << "type: Standard Tesselation Language";
        break;
      case rad::nomsg::NOMSG__TYPE_JSON:
        os << "type: JavaScript Array Object Notation";
        break;
      case rad::nomsg::NOMSG__TYPE_AVRO:
        os << "type: Apache AVRO";
        break;
      case rad::nomsg::NOMSG__TYPE_GOOG:
        os << "type: Google serialization";
        break;
      default:
        os << "type: unknown";
        break;
    }
  } // flags

  std::ostream& operator<<(std::ostream &os, const rad::nomsg::nomsg_flags_t &o)
  {
    std::ios::fmtflags flags(os.flags());
    std::bitset<8> bits(o);
    os << "        flags bits: " << bits << std::endl;
    os << "     CRC32_present: " << std::boolalpha << bits.test(0)  << std::endl;
    os.flags(flags);
    return os;
  } // flags

  // --------------------------------------------------------------------------
  // FILE
  // --------------------------------------------------------------------------

  std::ostream& operator<<(std::ostream &os, const rad::nomsg::nomsg_file_t &o)
  {
    return os;
  }; // file

  // --------------------------------------------------------------------------
  // INDX
  // --------------------------------------------------------------------------

  std::ostream& operator<<(std::ostream &os, const rad::nomsg::nomsg_index_t &o)
  {
    return os;
  }; // index

  std::ostream& operator<<(std::ostream &os, const rad::nomsg::nomsg_index_entry_t &o)
  {
    return os;
  }; // index entry

} // namespace

  using namespace rad::nomsg;

/// *EOF*
