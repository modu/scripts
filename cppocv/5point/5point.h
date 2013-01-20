/*
Code is released under Simplified BSD License.
-------------------------------------------------------------------------------
Copyright 2012 Nghia Ho. All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are
permitted provided that the following conditions are met:

   1. Redistributions of source code must retain the above copyright notice, this list of
      conditions and the following disclaimer.

   2. Redistributions in binary form must reproduce the above copyright notice, this list
      of conditions and the following disclaimer in the documentation and/or other materials
      provided with the distribution.

THIS SOFTWARE IS PROVIDED BY NGHIA HO ``AS IS'' AND ANY EXPRESS OR IMPLIED
WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL NGHIA HO OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

The views and conclusions contained in the software and documentation are those of the
authors and should not be interpreted as representing official policies, either expressed
or implied, of Nghia Ho.
*/

#ifndef __5POINT_H__
#define __5POINT_H__

#include <opencv2/core/core.hpp>

// Call this function
bool Solve5PointEssential(double *pts1, double *pts2, int num_pts, cv::Mat &ret_E, cv::Mat &ret_P, int &ret_inliers);

void ProjectionsFromEssential(const cv::Mat &E, cv::Mat &P1, cv::Mat &P2, cv::Mat &P3, cv::Mat &P4);
cv::Mat TriangulatePoint(const cv::Point2d &pt1, const cv::Point2d &pt2, const cv::Mat &P1, const cv::Mat &P2);
double CalcDepth(const cv::Mat &X, const cv::Mat &P);

#endif
