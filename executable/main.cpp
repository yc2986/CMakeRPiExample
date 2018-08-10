#include <any>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;

// experiment with c++20 __VA_ARGS_OPT__ macro
#define cxx_2a_foo(param, ...) \
    ::foo(param __VA_OPT__(,) __VA_ARGS__)

namespace {
    void foo(const char *c1) {
        cout << "single param foo: "
             << c1
             << endl; 
    }

    void foo(const char *c1, const char *c2) {
        cout << "double params foo: "
             << c1 << " "
             << c2
             << endl;
    }
}

int main() {
    vector<thread> threads;
    threads.reserve(10);
    mutex mtx;
    for (size_t i = 0; i < 10; i++) {
        threads.push_back(thread([i, &mtx]() {
            lock_guard<mutex> guard(mtx);
            int a = 5;
            auto obj = make_any<decltype(a)>(a);
            cout << "thread " << i << " finished" << endl;
        }));
    }
    for (auto &t : threads) {
        if (t.joinable()) {
            t.join();
        }
    }
    // try out c++2a feature
    cxx_2a_foo("static c1", "optional c2 param");
    cxx_2a_foo("static c1");
    return 0;
}
