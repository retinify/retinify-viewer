// SPDX-FileCopyrightText: Copyright (c) 2025 Sensui Yagi
// SPDX-License-Identifier: Apache-2.0

#pragma once
#include <opencv2/core.hpp>
#include <rerun.hpp>

namespace retinify
{
class Viewer
{
  public:
    Viewer();
    ~Viewer() = default;
    Viewer(const Viewer &) = delete;
    Viewer &operator=(const Viewer &) = delete;
    Viewer(Viewer &&) = delete;
    Viewer &operator=(Viewer &&) = delete;

    /**
     * @brief Log image to viewer
     *
     * @param name category name
     * @param img image to log
     * @note image must be BGR CV_8UC3
     */
    void Image(const std::string &name, const cv::Mat &img);

    /**
     * @brief Log points to viewer
     *
     * @param name category name
     * @param img image to log
     * @param points points to log
     * @note image must be BGR CV_8UC3, points must be CV_32FC3
     */
    void Points(const std::string &name, const cv::Mat &img, const cv::Mat &points);

  private:
    const rerun::RecordingStream rec = rerun::RecordingStream("retinify");
};
} // namespace retinify