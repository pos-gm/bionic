/*
 * Copyright (C) 2014 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <gtest/gtest.h>

#include <utmp.h>

TEST(utmp, login_tty) {
  // login_tty is tested indirectly by the openpty and forkpty tests.
  // This test just checks that we're exporting the symbol independently.
  ASSERT_EQ(-1, login_tty(-1));
}

TEST(utmp, smoke) {
  // The rest of <utmp.h> is just no-op implementations, so testing is trivial.
  ASSERT_EQ(-1, utmpname("hello"));
  setutent();
  ASSERT_EQ(NULL, getutent());
  endutent();
  utmp failure = {.ut_type = EMPTY};
  ASSERT_EQ(NULL, pututline(&failure));
}
