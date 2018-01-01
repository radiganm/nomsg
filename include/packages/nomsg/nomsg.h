/// nomsg.h
/// Copyright 2017 Mac Radigan
/// All Rights Reserved

  #include <cinttypes>
  #include <iostream>

#pragma once

  #define NOMSG__BIT_SET(field,bit)    ( field |=   1UL << bit )
  #define NOMSG__BIT_CLEAR(field,bit)  ( field &= ~(1UL << bit))
  #define NOMSG__BIT_CHECK(field,bit)  ((field << bit) & 1UL)
  #define NOMSG__BIT_TOGGLE(field,bit) ( field ^=   1UL << bit )

  #define NOMSG__FILE_NAME_LENGTH             (4096)
  #define NOMSG__INDEX_ENTRY_NAME_LENGTH      (4096)

namespace rad::nomsg {

  enum nomsg_type_t : uint32_t
  {
    NOMSG__TYPE_NOMSG       = 0x4e4d5347, // NMSG - NoMsg container
    NOMSG__TYPE_INDEX       = 0x494e4458, // INDX - indexed array
    NOMSG__TYPE_FILE        = 0x46494c45, // FILE - ordinary file
    NOMSG__TYPE_INTERROBANG = 0x233f2121, // #?!! - interrobang script
    NOMSG__TYPE_EDN         = 0x45444e30, // EDN0 - Extensible Data Notation (EDN)
    NOMSG__TYPE_SEXP        = 0x53455850, // SEXP - s-expressions
    NOMSG__TYPE_LISP        = 0x4c495350, // LISP - lisp code
    NOMSG__TYPE_STL         = 0x53544c30, // STL0 - Standard Tessellation Language (STL) "stereolithography"
    NOMSG__TYPE_WAV         = 0x57415630, // WAV0 - Wave Format
    NOMSG__TYPE_MP3         = 0x4d503330, // MP3 - MP3 Format
    NOMSG__TYPE_MIDI        = 0x4d494449, // MIDI - MIDI
    NOMSG__TYPE_BLUE        = 0x424c5545, // BLUE - MIDAS BLUE Format
    NOMSG__TYPE_GREY        = 0x47524559, // GREY - Xinx-Midas GREY Format
    NOMSG__TYPE_JSON        = 0x4a534f4e, // JSON - JavaScript Array Object Notation (JSON)
    NOMSG__TYPE_AVRO        = 0x4156524f, // AVRO - Apache Avro
    NOMSG__TYPE_GOOG        = 0x474f4f47  // GOOD - Google serialization
  }; // types

  // --------------------------------------------------------------------------
  // NoMsg
  // --------------------------------------------------------------------------

  using nomsg_type_aux_t = uint32_t;
  using nomsg_crc32_t    = uint32_t;
  using nomsg_flags_t    = uint32_t;
  using nomsg_sequence_t = uint64_t;
  using nomsg_count_t    = uint64_t;
  using nomsg_size_t     = uint64_t;

  typedef struct __attribute__((__packed__)) nomsg_s
  {
    public: // 40 octets, not including payload
      nomsg_type_t      type;      // 04/04: message type
      nomsg_type_aux_t  type_aux;  // 04/08: message subtype
      nomsg_flags_t     flags;     // 04/12: flags
      nomsg_crc32_t     crc32;     // 04/16: CRC32 checksum
      nomsg_sequence_t  sequence;  // 08/24: 64-bit monotonic sequence counter
      nomsg_count_t     count;     // 08/32: number of elements in payload
      nomsg_size_t      size;      // 08/40: payload size in bytes
      // payload flexbible array member, aligned to 8-byte boundary
      uint8_t           payload[] __attribute__((aligned (8))); 
    private:
     friend std::ostream& operator<<(std::ostream &os, const struct nomsg_s &o);
  } nomsg_t; // nomsg

  enum nomsg_type_aux_goog_t : uint32_t
  {
    NOMSG__TYPE_AUX_PROTOCOL_BUFFER = 0x50425546, // PBUF - Google Protocol Buffers
    NOMSG__TYPE_AUX_FLAT_BUFFER     = 0x46425546, // FBUF - Google Flat Buffers
    NOMSG__TYPE_AUX_CAPN_PROTO      = 0x4341504e  // CAPN - Cap'N Proto
  }; // types

  enum nomsg_type_aux_stl_t : uint32_t
  {
    NOMSG__TYPE_STL_ASCII   = 0x53544c61, // STLa - Standard Tessellation Language (STL) "stereolithography", ASCII
    NOMSG__TYPE_STL_BINARY  = 0x53544c62  // STLb - Standard Tessellation Language (STL) "stereolithography", binary
  }; // types

  std::ostream& operator<<(std::ostream &os, const rad::nomsg::nomsg_type_t &o);
  std::ostream& operator<<(std::ostream &os, const rad::nomsg::nomsg_flags_t &o);

  // --------------------------------------------------------------------------
  // FILE
  // --------------------------------------------------------------------------

  using nomsg_file_type_t     = uint32_t;
  using nomsg_file_flags_t    = uint32_t;
  using nomsg_file_name_t     = char[NOMSG__FILE_NAME_LENGTH];
  using nomsg_file_sha1_t     = char[20];
  using nomsg_file_size_t     = uint64_t;

  typedef struct __attribute__((__packed__)) nomsg_file_s
  {
    public: // 4132 octets, not including payload
      nomsg_file_type_t      type;      // 0004/0004: file type
      nomsg_file_flags_t     flags;     // 0004/0008: flags
      nomsg_file_name_t      name;      // 8192/4104: file name
      nomsg_file_sha1_t      sha1;      // 0020/4124: SHA1 checksum
      nomsg_file_size_t      size;      // 0008/4132: payload size in bytes
      // payload flexbible array member, aligned to 8-byte boundary
      uint8_t                payload[] __attribute__((aligned (8))); 
    private:
     friend std::ostream& operator<<(std::ostream &os, const struct nomsg_file_s &o);
  } nomsg_file_t; // nomsg_file

  // --------------------------------------------------------------------------
  // INDX
  // --------------------------------------------------------------------------

  using nomsg_index_type_t     = uint32_t;
  using nomsg_index_version_t  = uint32_t;
  using nomsg_index_flags_t    = uint32_t;
  using nomsg_index_sha1_t     = char[20];
  using nomsg_index_count_t    = uint64_t;
  using nomsg_index_size_t     = uint64_t;

  typedef struct __attribute__((__packed__)) nomsg_index_s
  {
    public: // 4132 octets, not including payload
      nomsg_index_type_t        type;         // 04/04: file type
      nomsg_index_version_t     version;      // 04/08: file type
      nomsg_index_flags_t       flags;        // 04/12: flags
      nomsg_index_sha1_t        sha1;         // 20/32: SHA1 checksum
      nomsg_index_count_t       count;        // 08/40: number of entries
      nomsg_index_size_t        index_size;   // 08/48: index size in bytes
      nomsg_index_size_t        payload_size; // 08/56: payload size in bytes
      // payload flexbible array member, aligned to 8-byte boundary
      uint8_t                   payload[] __attribute__((aligned (8))); 
    private:
     friend std::ostream& operator<<(std::ostream &os, const struct nomsg_index_s &o);
  } nomsg_index_t; // nomsg_index

  using nomsg_index_entry_name_t  = char[NOMSG__INDEX_ENTRY_NAME_LENGTH];
  using nomsg_index_entry_flags_t = uint32_t;

  typedef struct __attribute__((__packed__)) nomsg_index_entry_s
  {
    public: // 4116 octets, not including payload
      nomsg_index_entry_flags_t flags;  // 0004/0004: flags
      nomsg_index_entry_name_t  name;   // 4096/4100: entry name
      nomsg_index_size_t        size;   // 0008/4108: size of entry
      nomsg_index_size_t        offset; // 0008/4116: offset of entry
      // payload flexbible array member, aligned to 8-byte boundary
      uint8_t                   payload[] __attribute__((aligned (8))); 
    private:
     friend std::ostream& operator<<(std::ostream &os, const struct nomsg_index_entry_s &o);
  } nomsg_index_entry_t; // nomsg_index_entry

} // namespace

/// *EOF*
