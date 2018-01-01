/// NomsgParser.cc
///
/// Copyright 2017 Mac Radigan
/// All Rights Reserved

  #include "packages/nomsg/NomsgParser.h"
  #include <assert.h>
  #include <stdexcept>

namespace rad::nomsg {

  inline constexpr bool NomsgParser::infer_type(char c, nomsg_type_t &type)
  {
    switch(c)
    {
      case '{':
        type = NOMSG__TYPE_EDN;
        return true;
      case '[':
        type = NOMSG__TYPE_JSON;
        return true;
      case '(':
        type = NOMSG__TYPE_SEXP;
        return true;
      default:
        return false;
    }
  }

  inline nomsg_type_t NomsgParser::get_type(const void * buffer, std::size_t size) 
  { 
    assert(size > sizeof(nomsg_type_t));
    nomsg_type_t result;
    const char *pchar = reinterpret_cast<const char *>(buffer);
    // detect EDN, JSON, and S-expressions 
    if (infer_type(*pchar, result))   return result;
    else while( ' ' == *(++pchar)) 
      if (infer_type(*pchar, result)) return result;
    // detect cookie
    const nomsg_type_t &type = *reinterpret_cast<const nomsg_type_t * const>(buffer);
    switch(type)
    {
      case NOMSG__TYPE_EDN:
        throw std::runtime_error("NOMSG: invalid type, must be valid EDN");
        break;
      case NOMSG__TYPE_JSON:
        throw std::runtime_error("NOMSG: invalid type, must be valid JSON");
        break;
      case NOMSG__TYPE_SEXP:
        throw std::runtime_error("NOMSG: invalid type, must be a valid S-expression");
        break;
      case NOMSG__TYPE_NOMSG:
      case NOMSG__TYPE_INDEX:
      case NOMSG__TYPE_FILE:
      case NOMSG__TYPE_INTERROBANG:
      case NOMSG__TYPE_LISP:
      case NOMSG__TYPE_STL:
      case NOMSG__TYPE_WAV:
      case NOMSG__TYPE_MP3:
      case NOMSG__TYPE_MIDI:
      case NOMSG__TYPE_BLUE:
      case NOMSG__TYPE_GREY:
      case NOMSG__TYPE_AVRO:
      case NOMSG__TYPE_GOOG:
        return type; 
        break;
      default:
        throw std::runtime_error("NOMSG: unsupported type");
    }
  }

} // namespace


  using namespace rad::nomsg;

/// *EOF*
