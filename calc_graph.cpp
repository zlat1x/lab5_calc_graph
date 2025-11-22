#include "calc_graph.h"

#include <chrono>
#include <future>
#include <iostream>
#include <syncstream>
#include <thread>

namespace calc_graph {
    constexpr int slow_duration_seconds = 7;
    constexpr int quick_duration_seconds = 1;

    static void run_step(const std::string& name, int seconds) {
        std::this_thread::sleep_for(std::chrono::seconds(seconds));
        std::osyncstream(std::cout) << name << '\n';
    }

    void slow(const std::string& name) {
        run_step(name, slow_duration_seconds);
    }

    void quick(const std::string& name) {
        run_step(name, quick_duration_seconds);
    }

    void work() {
        using std::chrono::steady_clock;
        using std::chrono::duration_cast;
        using std::chrono::seconds;

        auto start = steady_clock::now();

        auto future_c = std::async(std::launch::async, [] {
            slow("C");
        });

        auto future_b_d2_f2 = std::async(std::launch::async, [] {
            quick("B");
            quick("D2");
            quick("F2");
        });

        slow("A");

        future_c.get();
        future_b_d2_f2.get();

        quick("D1");
        
        quick("F1");

        auto finish = steady_clock::now();                    
        auto elapsed = duration_cast<seconds>(finish - start); 

        std::osyncstream(std::cout) << "Total time: "
                                    << elapsed.count() << " s\n";
        std::osyncstream(std::cout) << "Work is done!\n";
    }
}