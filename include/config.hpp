// include/config.hpp

#pragma once

namespace Config {

namespace Paddle {

constexpr float kSpeed{1000.f};

}

namespace Ball {

constexpr float kSpawnTimer{1.f};
constexpr float kInitialSpeed{1250.f};
constexpr float kAccelerationSpeed{15.f};

}  // namespace Ball

}  // namespace Config