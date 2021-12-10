/*
 * Copyright (c) 2021 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "get_uid_permission_command_test.h"
#include <algorithm>
#include <functional>
#include <fstream>
#include <iostream>
#include <iostream>
#include <map>
#include <memory>
#include <thread>
#include "gtest/gtest.h"
#include "ability_manager_interface.h"
#include "base_remote_command.h"
#include "constant_mock.h"
#include "if_system_ability_manager.h"
#include "iservice_registry.h"
#include "mock_bundle_mgr.h"
#include "mock_permission_mgr.h"

using namespace std;
using namespace OHOS::Security::Permission;
using namespace testing::ext;

GetUidPermissionCommandTest::GetUidPermissionCommandTest()
{}
GetUidPermissionCommandTest::~GetUidPermissionCommandTest()
{}
void GetUidPermissionCommandTest::SetUpTestCase()
{}
void GetUidPermissionCommandTest::TearDownTestCase()
{}
void GetUidPermissionCommandTest::SetUp()
{}
void GetUidPermissionCommandTest::TearDown()
{}

HWTEST_F(GetUidPermissionCommandTest, GetUidPermissionCommandTest_0001, Function | MediumTest | Level1)
{
    int32_t uid = 1;
    std::string srcDeviceId = "srcDeviceId";
    std::string dstDeviceId = "dstDeviceId";

    std::unique_ptr<GetUidPermissionCommand> class_ =
        std::make_unique<GetUidPermissionCommand>(uid, srcDeviceId, dstDeviceId);

    EXPECT_EQ(class_->remoteProtocol_.commandName, "GetUidPermissionCommand");
    EXPECT_EQ(class_->remoteProtocol_.uniqueId, "GetUidPermissionCommand-1");
    EXPECT_EQ(class_->remoteProtocol_.srcDeviceId, srcDeviceId);
    EXPECT_EQ(class_->remoteProtocol_.dstDeviceId, dstDeviceId);
    EXPECT_EQ(class_->remoteProtocol_.responseVersion, 1);
}

HWTEST_F(GetUidPermissionCommandTest, GetUidPermissionCommandTest_0002, Function | MediumTest | Level1)
{
    int32_t uid = 1;
    std::string srcDeviceId = "srcDeviceId";
    std::string dstDeviceId = "dstDeviceId";

    std::unique_ptr<GetUidPermissionCommand> class_ =
        std::make_unique<GetUidPermissionCommand>(uid, srcDeviceId, dstDeviceId);

    class_->Prepare();
    EXPECT_EQ(class_->remoteProtocol_.statusCode, 0);
}

HWTEST_F(GetUidPermissionCommandTest, GetUidPermissionCommandTest_0005, Function | MediumTest | Level1)
{
    int32_t uid = -1;
    std::string srcDeviceId = "srcDeviceId";
    std::string dstDeviceId = "dstDeviceId";

    std::unique_ptr<GetUidPermissionCommand> class_ =
        std::make_unique<GetUidPermissionCommand>(uid, srcDeviceId, dstDeviceId);

    class_->Execute();

    EXPECT_EQ(class_->remoteProtocol_.statusCode, -2);
    EXPECT_EQ(class_->remoteProtocol_.message, "failed to get permissions");
}

HWTEST_F(GetUidPermissionCommandTest, GetUidPermissionCommandTest_0009, Function | MediumTest | Level1)
{
    int32_t uid = 12610001;
    std::string srcDeviceId = "12345678901234567890123456789012345678901234567890123456789012345";
    std::string dstDeviceId = "dstDeviceId";

    std::unique_ptr<GetUidPermissionCommand> class_ =
        std::make_unique<GetUidPermissionCommand>(uid, srcDeviceId, dstDeviceId);

    class_->Execute();
    class_->Finish();

    EXPECT_EQ(class_->remoteProtocol_.statusCode, -2);
    EXPECT_EQ(class_->remoteProtocol_.message, "execute command failed");
}

HWTEST_F(GetUidPermissionCommandTest, GetUidPermissionCommandTest_0010, Function | MediumTest | Level1)
{
    int32_t uid = 12600000;
    std::string srcDeviceId = "srcDeviceId";
    std::string dstDeviceId = "dstDeviceId";

    std::unique_ptr<GetUidPermissionCommand> class_ =
        std::make_unique<GetUidPermissionCommand>(uid, srcDeviceId, dstDeviceId);

    class_->Execute();
    class_->Finish();

    EXPECT_EQ(class_->remoteProtocol_.statusCode, -2);
    EXPECT_EQ(class_->remoteProtocol_.message, "execute command failed");
}

HWTEST_F(GetUidPermissionCommandTest, GetUidPermissionCommandTest_0012, Function | MediumTest | Level1)
{
    std::string json =
        "{\"commandName\":\"GetUidPermissionCommand\",\"dstDeviceId\":\"dstDeviceId\",\"dstDeviceLevel\":\"\","
        "\"message\":\"success\",\"requestVersion\":1,\"responseDeviceId\":\"1004\",\"responseVersion\":1,"
        "\"srcDeviceId\":\"srcDeviceId\",\"srcDeviceLevel\":\"\",\"statusCode\":0,\"uid\":12600000,\"uidPermission\":{"
        "\"DEFAULT_SIZE\":10,\"MIN_UID_PACKAGES_NUM\":1,\"appAttribute\":2,\"bundles\":[{\"appId\":\"bundleInfo."
        "appId\",\"bundleLabel\":\"bundleInfo.label\",\"name\":\"bundleInfo.name\",\"permissions\":[{\"defInfo\":0,"
        "\"grantMode\":0,\"level\":0,\"name\":\"reqPermissions1\",\"status\":1,\"type\":\"app\"},{\"defInfo\":0,"
        "\"grantMode\":0,\"level\":0,\"name\":\"reqPermissions2\",\"status\":1,\"type\":\"app\"},{\"defInfo\":0,"
        "\"grantMode\":0,\"level\":0,\"name\":\"reqPermissions3\",\"status\":1,\"type\":\"app\"},{\"defInfo\":0,"
        "\"grantMode\":0,\"level\":0,\"name\":\"reqPermissions4\",\"status\":1,\"type\":\"app\"},{\"defInfo\":0,"
        "\"grantMode\":0,\"level\":0,\"name\":\"reqPermissions5\",\"status\":1,\"type\":\"app\"}],\"sign\":[{"
        "\"sha256\":\"applicationInfo.signatureKey\"}]}],\"remoteSensitivePermission\":null,\"uid\":12600000,"
        "\"uidState\":0},\"uniqueId\":\"GetUidPermissionCommand-12600000\"}";

    std::unique_ptr<GetUidPermissionCommand> class_ = std::make_unique<GetUidPermissionCommand>(json);

    EXPECT_EQ(class_->remoteProtocol_.commandName, "GetUidPermissionCommand");
    EXPECT_EQ(class_->remoteProtocol_.dstDeviceId, "dstDeviceId");
    EXPECT_EQ(class_->remoteProtocol_.message, "success");
    EXPECT_EQ(class_->remoteProtocol_.requestVersion, 1);
    EXPECT_EQ(class_->remoteProtocol_.responseDeviceId, "1004");
    EXPECT_EQ(class_->remoteProtocol_.responseVersion, 1);
    EXPECT_EQ(class_->remoteProtocol_.srcDeviceId, "srcDeviceId");
    EXPECT_EQ(class_->remoteProtocol_.statusCode, 0);
    EXPECT_EQ(class_->remoteProtocol_.uniqueId, "GetUidPermissionCommand-12600000");
}