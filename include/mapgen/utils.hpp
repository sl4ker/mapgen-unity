#ifndef UTILS_HPP_
#define UTILS_HPP_
#include <functional>
#include "mapgen/City.hpp"

#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;

typedef sf::Vector2<double>* Point;
namespace mg {
	template <typename T> using filterFunc = std::function<bool(T *)>;
	template <typename T> using sortFunc = std::function<bool(T *, T *)>;


  double getDistance(Point p, Point p2);

  template <typename T>
  std::vector<T *> filterObjects(std::vector<T *> regions,
                                 std::function<bool(T *)> filter, std::function<bool(T *, T *)> sort);

  void before(std::string method);
  void after(std::string method);
  void info(std::string prefix, std::string value);
  void info(std::string prefix, int value);
  void info(std::string prefix, City value);
  void info(std::string prefix, fs::path value);
  void warn(std::string prefix, std::string value);
  void warn(std::string prefix, int value);
  void warn(std::string prefix, City value);
};
#endif
