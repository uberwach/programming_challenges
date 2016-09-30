// http://stackoverflow.com/questions/2808398/easily-measure-elapsed-time
// how to reignite my interest into C++ the code ;)
#include <chrono>

template <typename TimeT = std::chrono::milliseconds>
struct measure {
  template <typename F, typename... Args>
  static typename TimeT::rep execution(F&& func, Args&&... args) {
    auto start = std::chrono::steady_clock::now();
    std::forward<decltype(func)>(func)(std::forward<Args>(args)...);
    auto duration = std::chrono::duration_cast<TimeT>(
        std::chrono::steady_clock::now() - start);
    return duration.count();
  }
};
