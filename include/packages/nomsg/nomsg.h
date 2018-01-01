/// nomsg.h
/// Copyright 2017 Mac Radigan
/// All Rights Reserved

  #include <cinttypes>
  #include <iostream>

#pragma once

namespace rad::nomsg {

  enum nomsg_type_t : uint32_t
  {
    NOMSG__TYPE_INTERROBANG = 0x233f2121, // #?!!
    NOMSG__TYPE_SEXP        = 0x53455850, // SEXP
    NOMSG__TYPE_LISP        = 0x4c495350  // LISP
  }; // types

  using nomsg_crc32_t = uint32_t;
  using nomsg_size_t  = uint64_t;

  typedef struct __attribute__((__packed__)) nomsg_s
  {
    public:
      nomsg_type_t  type;
      nomsg_crc32_t crc32;
      nomsg_size_t  size;
      uint8_t       payload[] __attribute__((aligned (8)));
    private:
     friend std::ostream& operator<<(std::ostream &os, const struct nomsg_s &o);
  } nomsg_t; // nomsg

} // namespace

/// *EOF*
