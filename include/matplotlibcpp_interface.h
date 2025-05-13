#pragma once
#include <matplotlib_cpp_catkin/matplotlibcpp.h>
#include <Eigen/Core>

namespace matplotlibcpp_interface
{
template<typename VecT>
  void plotData(const std::vector<VecT>& data, const std::vector<double>& times, const std::string & title = "", bool& show_plot = false)
  {
    for(int i = 0; i < data.at(0).size(); i++)
      {
        std::vector<double> data_i(0);
        for(int j = 0; j < data.size(); j++)
          {
            data_i.push_back(data[j][i]);
          }
        matplotlibcpp::named_plot("data_" + std::to_string(i), times, data_i);
      }
    matplotlibcpp::title(title);
    matplotlibcpp::legend();

    if(show_plot)
      matplotlibcpp::show();
  }
}
