#include "calc_graph.h"

#include <chrono>
#include <iostream>
#include <syncstream>
#include <thread>

namespace calc_graph {
    static void run_step(const std::string& name, int seconds) {
        std::this_thread::sleep_for(std::chrono::seconds(seconds));
        std::osyncstream(std::cout) << name << '\n';
    }

    void slow(const std::string& name) {
        run_step(name, 7);
    }

    void quick(const std::string& name) {
        run_step(name, 1);
    }

    void work() {
        slow("A");
        quick("B");
        slow("C");

        quick("D1");
        quick("D2");
        quick("F1");
        quick("F2");
    }
}