/*
* Copyright 2016 Google Inc. All Rights Reserved.

* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at

* http://www.apache.org/licenses/LICENSE-2.0

* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
#ifndef QUERY_POOL_H_
#define QUERY_POOL_H_

#include <vcc/device.h>

namespace vcc {
namespace query_pool {

struct query_pool_type
	: public internal::movable_destructible_with_parent<VkQueryPool,
	device::device_type, vkDestroyQueryPool> {
	friend VCC_LIBRARY query_pool_type create(
		type::supplier<device::device_type> &device,
		VkQueryType queryType,
		uint32_t queryCount,
		VkQueryPipelineStatisticFlags pipelineStatistics);

	query_pool_type() = default;
	query_pool_type(query_pool_type &&) = default;
	query_pool_type(const query_pool_type &) = delete;
	query_pool_type &operator=(query_pool_type &&) = default;
	query_pool_type &operator=(const query_pool_type &) = delete;

private:
	query_pool_type(VkQueryPool instance,
		const type::supplier<device::device_type> &parent)
		: internal::movable_destructible_with_parent<VkQueryPool,
		device::device_type, vkDestroyQueryPool>(instance, parent) {}
};

VCC_LIBRARY query_pool_type create(type::supplier<device::device_type> &device,
		VkQueryType queryType,
		uint32_t queryCount,
		VkQueryPipelineStatisticFlags pipelineStatistics);

VCC_LIBRARY void get_results(uint32_t firstQuery, uint32_t queryCount, size_t dataSize,
		void* pData, VkDeviceSize stride, VkQueryResultFlags flags);

}  // namespace query_pool
}  // namespace vcc

#endif /* QUERY_POOL_H_ */
