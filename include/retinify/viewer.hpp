// SPDX-License-Identifier: Apache-2.0
// Copyright (c) 2025 Sensui Yagi

#pragma once
#include <opencv2/core.hpp>
#include <rerun.hpp>

namespace retinify
{
class Viewer
{
  public:
    Viewer();
    ~Viewer();
    Viewer(const Viewer &) = delete;
    Viewer &operator=(const Viewer &) = delete;
    Viewer(Viewer &&) = delete;
    Viewer &operator=(Viewer &&) = delete;
    void Image(const std::string &name, const cv::Mat &img);
    void Points(const std::string &name, const cv::Mat &img, const cv::Mat &points);

  private:
    const rerun::RecordingStream rec = rerun::RecordingStream("retinify");
};
} // namespace retinify