/// NomsgParser.h
///
/// Copyright 2017 Mac Radigan
/// All Rights Reserved


  #include "packages/nomsg/nomsg.h"

#pragma once

namespace rad::nomsg {

  class NomsgParser
  {
    public:
      NomsgParser() = default;
      virtual ~NomsgParser() {};
      static inline nomsg_type_t get_type(const void * buffer, std::size_t size);
      static inline constexpr bool infer_type(char c, nomsg_type_t &type);
    private:
  };

} // namespace

/// *EOF*
