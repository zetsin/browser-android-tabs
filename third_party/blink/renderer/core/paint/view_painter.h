// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_PAINT_VIEW_PAINTER_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_PAINT_VIEW_PAINTER_H_

#include "third_party/blink/renderer/platform/wtf/allocator.h"

namespace blink {

class LayoutPoint;
struct PaintInfo;
class LayoutView;

class ViewPainter {
  STACK_ALLOCATED();

 public:
  ViewPainter(const LayoutView& layout_view) : layout_view_(layout_view) {}

  void Paint(const PaintInfo&, const LayoutPoint& paint_offset);
  void PaintBoxDecorationBackground(const PaintInfo&);

 private:
  const LayoutView& layout_view_;
};

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_PAINT_VIEW_PAINTER_H_
