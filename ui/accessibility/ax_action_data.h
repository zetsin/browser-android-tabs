// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef UI_ACCESSIBILITY_AX_ACTION_DATA_H_
#define UI_ACCESSIBILITY_AX_ACTION_DATA_H_

#include "base/strings/string16.h"
#include "ui/accessibility/ax_enums.mojom.h"
#include "ui/accessibility/ax_export.h"
#include "ui/gfx/geometry/rect.h"

namespace ui {

// A compact representation of an accessibility action and the arguments
// associated with that action.
struct AX_EXPORT AXActionData {
  AXActionData();
  AXActionData(const AXActionData& other);
  virtual ~AXActionData();

  // Return a string representation of this data, for debugging.
  virtual std::string ToString() const;

  // This is a simple serializable struct. All member variables should be
  // public and copyable.

  // See the ax::mojom::Action enums in ax_enums.idl for explanations of which
  // parameters apply.

  // The action to take.
  ax::mojom::Action action = ax::mojom::Action::kNone;

  // The ID of the tree that this action should be performed on.
  int target_tree_id = -1;

  // The source extension id (if any) of this action.
  std::string source_extension_id;

  // The ID of the node that this action should be performed on.
  int target_node_id = -1;

  // The request id of this action tracked by the client.
  int request_id = -1;

  // Use enums from ax::mojom::ActionFlags
  int flags = 0;

  // For an action that creates a selection, the selection anchor and focus
  // (see ax_tree_data.h for definitions).
  int anchor_node_id = -1;
  int anchor_offset = -1;

  int focus_node_id = -1;
  int focus_offset = -1;

  // For custom action.
  int custom_action_id = -1;

  // The target rect for the action.
  gfx::Rect target_rect;

  // The target point for the action.
  gfx::Point target_point;

  // The new value for a node, for the SET_VALUE action.
  base::string16 value;

  // The event to fire in response to a HIT_TEST action.
  ax::mojom::Event hit_test_event_to_fire = ax::mojom::Event::kNone;
};

}  // namespace ui

#endif  // UI_ACCESSIBILITY_AX_ACTION_DATA_H_
