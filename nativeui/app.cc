// Copyright 2016 Cheng Zhao. All rights reserved.
// Use of this source code is governed by the license that can be found in the
// LICENSE file.

#include "nativeui/app.h"

#include "nativeui/menu_bar.h"
#include "nativeui/state.h"

namespace nu {

App::App() : weak_factory_(this) {
}

App::~App() {
}

Color App::GetColor(ThemeColor name) {
  int key = static_cast<int>(name);
  auto it = theme_colors_.find(key);
  if (it != theme_colors_.end())
    return it->second;
  Color color = PlatformGetColor(name);
  theme_colors_[key] = color;
  return color;
}

}  // namespace nu
