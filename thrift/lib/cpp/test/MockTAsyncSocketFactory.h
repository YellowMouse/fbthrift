/*
 * Copyright 2014 Facebook, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef THRIFT_TEST_MOCKTASYNCSOCKETFACTORY_H_
#define THRIFT_TEST_MOCKTASYNCSOCKETFACTORY_H_ 1

#include "thrift/lib/cpp/async/TAsyncSocketFactory.h"

#include <gmock/gmock.h>

namespace apache { namespace thrift {

namespace async {
class TEventBase;
}

namespace test {

class MockTAsyncSocketFactory : public async::TAsyncSocketFactory {
 public:
  explicit MockTAsyncSocketFactory(async::TEventBase* base) :
   async::TAsyncSocketFactory(base) {
  }
  async::TAsyncSocket::UniquePtr make() const {
    return async::TAsyncSocket::UniquePtr(make_mocked());
  }

  // GMock can't handle non-copy-constructable types
  MOCK_CONST_METHOD0(make_mocked, async::TAsyncSocket*());
};

}}}

#endif
