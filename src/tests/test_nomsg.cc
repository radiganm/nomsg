/// test_nomsg.cc
/// Copyright 2017 Mac Radigan
/// All Rights Reserved

  #include "packages/nomsg/nomsg.h"
  #include <gflags/gflags.h>
  #include <iostream>
  #include <iterator>
  #include <thread>
  #include <chrono>
  #include <string.h>
  #include <signal.h>
  #include <unistd.h>
  #include <cstring>
  #include <atomic>
  #include <bitset>

  using namespace std::chrono_literals;

  static std::atomic<bool> is_running(true);

  using element_t = int;
//static rad::nomsg::Nomsg *nomsg;

  static void interrupt(int signo)
  {
    switch(signo)
    {
      case SIGINT:
        is_running = false;
      //nomsg->close();
        break;
      default:
        std::cerr << "unhandled signal" << std::endl << std::flush;
    }
  }
  
  DEFINE_bool(debug,   false, "debug");
  DEFINE_bool(verbose, false, "verbose");

  int main(int argc, char *argv[])
  {
    int status(EXIT_SUCCESS);

    if(SIG_ERR == signal(SIGINT, interrupt)) {
      perror("unable to set signal");
      return status;
    }

    std::string usage("test_nomsg - usage:\n");
    usage += argv[0];
    usage += " ";
    gflags::SetUsageMessage(usage);
    gflags::ParseCommandLineFlags(&argc, &argv, true);

    if (argc < 2) 
    {
      std::cout << gflags::ProgramUsage() << std::endl << std::flush;
      exit(EXIT_FAILURE);
    }

  //nomsg = new rad::nomsg::Nomsg();

  //delete nomsg;

    return status;
  }

/// *EOF*
