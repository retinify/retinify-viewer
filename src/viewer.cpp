// SPDX-License-Identifier: Apache-2.0
// Copyright (c) 2025 Sensui Yagi

#include "retinify/viewer.hpp"

namespace retinify
{
Viewer::Viewer()
{
    rec.spawn().exit_on_failure();
    rec.log_static("world", rerun::ViewCoordinates::RIGHT_HAND_Y_DOWN);
}

Viewer::~Viewer() = default;

void Viewer::Image(const std::string &name, const cv::Mat &img)
{
    if (img.empty())
    {
        return;
    }

    if (img.type() != CV_8UC3)
    {
        return;
    }

    cv::Mat tmp = img.clone();
    rec.log(name, rerun::Image(tmp.data, {static_cast<uint32_t>(tmp.cols), static_cast<uint32_t>(tmp.rows)},
                               rerun::datatypes::ColorModel::BGR));
}

void Viewer::Points(const std::string &name, const cv::Mat &img, const cv::Mat &points)
{
    if (img.empty())
    {
        return;
    }

    if (points.empty())
    {
        return;
    }

    if (img.type() != CV_8UC3)
    {
        return;
    }

    if (points.type() != CV_32FC3)
    {
        return;
    }

    int rows = points.rows;
    int cols = points.cols;
    std::vector<rerun::datatypes::Vec3D> pointsVec;
    pointsVec.reserve(rows * cols);

    std::vector<rerun::components::Color> colorsVec;
    colorsVec.reserve(rows * cols);

    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < cols; ++c)
        {
            cv::Vec3f pt = points.at<cv::Vec3f>(r, c);
            pointsVec.emplace_back(pt[0], pt[1], pt[2]);
            cv::Vec3b col = img.at<cv::Vec3b>(r, c);
            colorsVec.emplace_back(static_cast<uint8_t>(col[2]), static_cast<uint8_t>(col[1]),
                                   static_cast<uint8_t>(col[0]), static_cast<uint8_t>(255));
        }
    }

    rec.log("world/" + name, rerun::Points3D(pointsVec).with_colors(colorsVec));
}
} // namespace retinify