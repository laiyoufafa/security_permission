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

#ifndef PMS_ADAPTER_H
#define PMS_ADAPTER_H

#include <memory>
#include <mutex>
#include <string>
#include <unordered_map>

#include "constant.h"
#include "i_permission_manager.h"
#include "ability_manager_interface.h"
#include "if_system_ability_manager.h"

namespace OHOS {
namespace Security {
namespace Permission {
class PmsAdapter {
public:
    PmsAdapter() = default;
    virtual ~PmsAdapter() = default;
    sptr<Permission::IPermissionManager> GetPermissionManager();

private:
    OHOS::sptr<ISystemAbilityManager> saMgr_;
    std::mutex saMutex_;
    sptr<IRemoteObject> GetSystemAbility(const Constant::ServiceId systemAbilityId);
    sptr<Permission::IPermissionManager> iPermissionManager_;
};
}  // namespace Permission
}  // namespace Security
}  // namespace OHOS
#endif  // PMS_ADAPTER_H
